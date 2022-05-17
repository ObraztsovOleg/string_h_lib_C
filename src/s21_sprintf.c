#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <float.h>
#include "s21_string.h"

static inline bool _is_digit(char ch) {
    return (ch >= '0') && (ch <= '9');
}

// internal secure strlen
// \return The length of the string (excluding the terminating 0) limited by 'maxsize'
static inline unsigned int _strnlen_s(const char* str, s21_size_t maxsize) {
    const char * s;
    for (s = str; *s && maxsize--; ++s)
        continue;

    return (unsigned int)(s - str);
}

// output the specified string in reverse, taking care of any zero-padding
static s21_size_t _out_rev(out_fct_type out, char* buffer, s21_size_t idx, s21_size_t maxlen, \
                        const char* buf, s21_size_t len, unsigned int width, unsigned int flags) {
    const s21_size_t start_idx = idx;

    // pad spaces up to given width
    if ((!(flags & FLAGS_LEFT) && !(flags & FLAGS_ZEROPAD)) || (flags & FLAGS_OUTOFRANGE)) {
        for (s21_size_t i = len; i < width; i++) {
            out(' ', buffer, idx++, maxlen);
        }
    }

    // reverse string
    while (len) {
        out(buf[--len], buffer, idx++, maxlen);
    }

    // append pad spaces up to given width
    if (flags & FLAGS_LEFT) {
        while (idx - start_idx < width) {
            out(' ', buffer, idx++, maxlen);
        }
    }

    return idx;
}

// internal ASCII string to unsigned int conversion
static unsigned int _atoi(const char** str) {
    unsigned int i = 0U;
    while (_is_digit(**str)) {
        i = i * 10U + (unsigned int)(*((*str)++) - '0');
    }

    return i;
}

// internal itoa format
static s21_size_t _ntoa_format(out_fct_type out, char* buffer, s21_size_t idx, s21_size_t maxlen, \
                            char* buf, s21_size_t len, bool negative, unsigned int base,  \
                            unsigned int prec, unsigned int width, unsigned int flags) {
        if (width && (flags & FLAGS_ZEROPAD) && (negative || (flags & (FLAGS_PLUS | FLAGS_SPACE)))) {
            width--;
        }
        while ((len < prec) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
            buf[len++] = '0';
        }
        while ((flags & FLAGS_ZEROPAD) && (len < width) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
            buf[len++] = '0';
        }


    // handle hash
    if (flags & FLAGS_HASH) {
        if (!(flags & FLAGS_PRECISION) && len && ((len == prec) || (len == width))) {
            len--;
            if (len && (base == 16U)) {
                len--;
            }
        }
        if ((base == 16U) && !(flags & FLAGS_UPPERCASE) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
            buf[len++] = 'x';
            flags &= ~FLAGS_SPACE;
        } else if ((base == 16U) && (flags & FLAGS_UPPERCASE) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
            buf[len++] = 'X';
            flags &= ~FLAGS_SPACE;
        } else if ((base == 2U) && (len < PRINTF_NTOA_BUFFER_SIZE)) {
            buf[len++] = 'b';
        }
        if (len < PRINTF_NTOA_BUFFER_SIZE) {
            buf[len++] = '0';
        }
    }

    if (len < PRINTF_NTOA_BUFFER_SIZE) {
        if (negative) {
            buf[len++] = '-';
        } else if (flags & FLAGS_PLUS) {
            buf[len++] = '+';  // ignore the space if the '+' exists
        }
    }

    return _out_rev(out, buffer, idx, maxlen, buf, len, width, flags);
}

// internal itoa for 'long' type
static s21_size_t _ntoa_long(out_fct_type out, char * buffer, s21_size_t idx, s21_size_t maxlen, \
                        unsigned long value, bool negative, unsigned long base,      \
                        unsigned int prec, unsigned int width, unsigned int flags) {
    char buf[PRINTF_NTOA_BUFFER_SIZE];
    s21_size_t len = 0U;

    // no hash for 0 values
    if (!value) {
        flags &= ~FLAGS_HASH;
    }

    // write if precision != 0 and value is != 0
    if (!(flags & FLAGS_PRECISION) || value) {
        do {
            const char digit = (char)(value % base);
            buf[len++] = digit < 10 ? '0' + digit : ((flags & FLAGS_UPPERCASE) ? 'A' : 'a') + digit - 10;
            value /= base;
        } while (value && (len < PRINTF_NTOA_BUFFER_SIZE));
    }

    return _ntoa_format(out, buffer, idx, maxlen, buf, len, negative, (unsigned int)base, prec, width, flags);
}


// internal ftoa for fixed decimal floating point
static s21_size_t _ftoa(out_fct_type out, char* buffer, s21_size_t idx, s21_size_t maxlen, \
                     double value, unsigned int prec, unsigned int width, unsigned int flags) {
    char buf[PRINTF_FTOA_BUFFER_SIZE];
    s21_size_t len  = 0U;

    // powers of 10
    static const double pow10[11] = { 1, 10, 100, 1000, 10000, 100000, \
                                    1000000, 10000000, 100000000, 1000000000};

    // test for special values
    if (value != value) {
        #if defined(__APPLE__) || defined(__MACH__)
            flags |= FLAGS_OUTOFRANGE;
            idx = _out_rev(out, buffer, idx, maxlen, "nan", 3, width, flags);
        #elif defined(__linux__)
            flags |= FLAGS_OUTOFRANGE;
            idx = _out_rev(out, buffer, idx, maxlen, "nan-", 4, width, flags);
        #endif
    } else if (value < -DBL_MAX) {
        flags |= FLAGS_OUTOFRANGE;
        idx = _out_rev(out, buffer, idx, maxlen, "fni-", 4, width, flags);
    } else if (value > DBL_MAX) {
        flags |= FLAGS_OUTOFRANGE;
        idx = _out_rev(out, buffer, idx, maxlen, (flags & FLAGS_PLUS) ? "fni+" : "fni", \
                    (flags & FLAGS_PLUS) ? 4U : 3U, width, flags);
    } else if ((value > PRINTF_MAX_FLOAT) || (value < -PRINTF_MAX_FLOAT)) {
        idx = _out_rev(out, buffer, idx, maxlen, "llun", 4, width, flags);
    } else {
        // test for negative
        bool negative = false;
        if (value < 0) {
            negative = true;
            value = 0 - value;
        }

        // set default precision, if not set explicitly
        if (!(flags & FLAGS_PRECISION)) {
            prec = PRINTF_DEFAULT_FLOAT_PRECISION;
        }
        // limit precision to 9, cause a prec >= 10 can lead to overflow errors
        while ((len < PRINTF_FTOA_BUFFER_SIZE) && (prec > 9U)) {
            buf[len++] = '0';
            prec--;
        }

        double diff = 0.0;

        int whole = (int)value;
        double tmp = (value - whole) * pow10[prec];
        unsigned long frac = (unsigned long)tmp;
        diff = tmp - frac;


        if (diff > 0.5) {
            ++frac;
            // handle rollover, e.g. case 0.99 with prec 1 is 1.0
            if (frac >= pow10[prec]) {
                frac = 0;
                ++whole;
            }
        } else if (diff < 0.5) {
            // do nothing
        } else if ((frac == 0U) || (frac & 1U)) {
            // if halfway, round up if odd OR if last digit is 0
            ++frac;
        }

        if (prec == 0U) {
            diff = value - (double)whole;
            if ((diff >= 0.5) && (whole & 1)) {
                // exactly 0.5 and ODD, then round up
                // 1.5 -> 2, but 2.5 -> 2
                ++whole;
            }
        } else {
            unsigned int count = prec;
            // now do fractional part, as an unsigned number
            while (len < PRINTF_FTOA_BUFFER_SIZE) {
                --count;
                buf[len++] = (char)(48U + (frac % 10U));

                if (!(frac /= 10U)) {
                    break;
                }
            }

            // add extra 0s
            while ((len < PRINTF_FTOA_BUFFER_SIZE) && (count-- > 0U)) {
                buf[len++] = '0';
            }

            if (len < PRINTF_FTOA_BUFFER_SIZE) {
                // add decimal
                buf[len++] = '.';
            }
        }

        // do whole part, number is reversed
        while (len < PRINTF_FTOA_BUFFER_SIZE) {
            buf[len++] = (char)(48 + (whole % 10));
            if (!(whole /= 10)) {
                break;
            }
        }

        // pad leading zeros
        if (!(flags & FLAGS_LEFT) && (flags & FLAGS_ZEROPAD)) {
            if (width && (negative || (flags & (FLAGS_PLUS | FLAGS_SPACE)))) {
                width--;
            }
            while ((len < width) && (len < PRINTF_FTOA_BUFFER_SIZE)) {
                buf[len++] = '0';
            }
        }

        if (len < PRINTF_FTOA_BUFFER_SIZE) {
            if (negative) {
                buf[len++] = '-';
            } else if (flags & FLAGS_PLUS) {
                buf[len++] = '+';  // ignore the space if the '+' exists
            } else if (flags & FLAGS_SPACE) {
                buf[len++] = ' ';
            }
        }
        idx = _out_rev(out, buffer, idx, maxlen, buf, len, width, flags);
    }

    return idx;
}

// internal buffer output
static inline void _out_buffer(char character, void * buffer, s21_size_t idx, s21_size_t maxlen) {
  if (idx < maxlen) {
    ((char*)buffer)[idx] = character;
  }
}

static int _vsnprintf(out_fct_type out, char * buffer, const s21_size_t maxlen, \
                    const char * format, va_list va) {
    unsigned int flags, width, precision, n;
    s21_size_t idx = 0U;

    while (*format) {
        // format specifier?  %[flags][width][.precision][length]
        if (*format != '%') {
            // no
            out(*format, buffer, idx++, maxlen);
            format++;
            continue;
        } else {
            // yes, evaluate it
            format++;
        }

        // evaluate flags
        flags = 0U;
        do {
            switch (*format) {
                case '0': flags |= FLAGS_ZEROPAD; format++; n = 1U; break;
                case '-': flags |= FLAGS_LEFT;    format++; n = 1U; break;
                case '+': flags |= FLAGS_PLUS;    format++; n = 1U; break;
                case ' ': flags |= FLAGS_SPACE;   format++; n = 1U; break;
                case '#': flags |= FLAGS_HASH;    format++; n = 1U; break;
                default :                                   n = 0U; break;
            }
        } while (n);

        // evaluate width field
        width = 0U;
        if (_is_digit(*format)) {
            width = _atoi(&format);
        } else if (*format == '*') {
            const int w = va_arg(va, int);
            if (w < 0) {
                flags |= FLAGS_LEFT;    // reverse padding
                width = (unsigned int)-w;
            } else {
                width = (unsigned int)w;
            }

            format++;
        }

        // evaluate precision field
        precision = 0U;
        if (*format == '.') {
            flags |= FLAGS_PRECISION;
            format++;

            if (_is_digit(*format)) {
                precision = _atoi(&format);
            } else if (*format == '*') {
                const int prec = (int)va_arg(va, int);
                precision = prec > 0 ? (unsigned int)prec : PRINTF_DEFAULT_FLOAT_PRECISION;
                format++;
            }
        }

        // evaluate length field
        switch (*format) {
            case 'l' :
                flags |= FLAGS_LONG;
                format++;

                break;
            case 'h' :
                flags |= FLAGS_SHORT;
                format++;

                break;
            default :
                break;
    }

    // evaluate specifier
    switch (*format) {
        case 'd' :
        case 'i' :
        case 'u' :
        case 'x' :
        case 'X' :
        case 'o' : {
            // set the base
            unsigned int base;

            if (*format == 'x' || *format == 'X') {
                base = 16U;
            } else if (*format == 'o') {
                base = 8U;
            } else {
                base = 10U;
                flags &= ~FLAGS_HASH;   // no hash for dec format
            }

            // uppercase
            if (*format == 'X') {
                flags |= FLAGS_UPPERCASE;
            }

            // no plus or space flag for u, x, X, o, b
            if ((*format != 'i') && (*format != 'd')) {
                flags &= ~(FLAGS_PLUS | FLAGS_SPACE);
            }

            // ignore '0' flag when precision is given
            if (flags & FLAGS_PRECISION) {
                flags &= ~FLAGS_ZEROPAD;
            }

            // convert the integer
            if ((*format == 'i') || (*format == 'd')) {
                // signed
                if (flags & FLAGS_LONG) {
                    const long value = va_arg(va, long);
                    idx = _ntoa_long(out, buffer, idx, maxlen, \
                                    (unsigned long)(value > 0 ? value : 0 - value), \
                                    value < 0, base, precision, width, flags);
                } else {
                    const int value = (flags & FLAGS_SHORT) ? (short int)va_arg(va, int) : va_arg(va, int);
                    idx = _ntoa_long(out, buffer, idx, maxlen, \
                                    (unsigned int)(value > 0 ? value : 0 - value), \
                                    value < 0, base, precision, width, flags);
                }
            } else {
                // unsigned
                if (flags & FLAGS_LONG) {
                    idx = _ntoa_long(out, buffer, idx, maxlen, va_arg(va, unsigned long), \
                                    false, base, precision, width, flags);
                } else {
                    const unsigned int value = (flags & FLAGS_SHORT) ? \
                                                (unsigned short int)va_arg(va, unsigned int) : \
                                                va_arg(va, unsigned int);
                    idx = _ntoa_long(out, buffer, idx, maxlen, value, false, base, precision, width, flags);
                }
            }
            format++;
            break;
        }
        case 'f' :
            if (*format == 'f') flags |= FLAGS_UPPERCASE;
            idx = _ftoa(out, buffer, idx, maxlen, va_arg(va, double), precision, width, flags);
            format++;

            break;
        case 'c' : {
            unsigned int l = 1U;
            // pre padding
            if (!(flags & FLAGS_LEFT)) {
                while (l++ < width) {
                    out(' ', buffer, idx++, maxlen);
                }
            }
            // char output
            out((char)va_arg(va, int), buffer, idx++, maxlen);
            // post padding
            if (flags & FLAGS_LEFT) {
                while (l++ < width) {
                    out(' ', buffer, idx++, maxlen);
                }
            }
            format++;
            break;
        }

        case 's' : {
            const char * p = va_arg(va, char*);

            if (p != S21_NULL) {
                unsigned int l = _strnlen_s(p, precision ? precision : (s21_size_t) - 1);

                // pre padding
                if (flags & FLAGS_PRECISION) {
                    l = (l < precision ? l : precision);
                }
                if (!(flags & FLAGS_LEFT)) {
                    while (l++ < width) {
                        out(' ', buffer, idx++, maxlen);
                    }
                }
                // string output
                while ((*p != 0) && (!(flags & FLAGS_PRECISION) || precision--)) {
                    out(*(p++), buffer, idx++, maxlen);
                }
                // post padding
                if (flags & FLAGS_LEFT) {
                    while (l++ < width) {
                        out(' ', buffer, idx++, maxlen);
                    }
                }
            } else {
                const char * null_str = "(null)";

                while (*null_str) {
                    out(*(null_str++), buffer, idx++, maxlen);
                }
            }

            format++;
            break;
        }

        case '%' :
            out('%', buffer, idx++, maxlen);
            format++;
            break;
    }
}

    // termination
    out((char)0, buffer, idx < maxlen ? idx : maxlen - 1U, maxlen);

    // return written chars without terminating \0
    return (int)idx;
}

int s21_sprintf(char * buffer, const char * format, ...) {
    va_list va;
    va_start(va, format);

    const int ret = _vsnprintf(_out_buffer, buffer, (s21_size_t) - 1, format, va);

    va_end(va);
    return ret;
}
