#include "s21_string.h"
#include <stdlib.h>

static void _s21_trim_left(const char **src, const char *trim_chars,
                   s21_size_t *src_len) {
    s21_size_t i = 0;

    while (trim_chars[i] != '\0') {
        if ((**src) == trim_chars[i]) {
            (*src)++;
            (*src_len)--;
            i = 0;
            continue;
        }
        i++;
    }
}

static void _s21_trim_right(const char **src, const char *trim_chars,
                    s21_size_t *src_len) {
    s21_size_t i = 0;
    s21_size_t j = (*src_len) - 1;

    while (trim_chars[i] != '\0') {
        if ((*src)[j] == trim_chars[i]) {
            j--;
            (*src_len)--;
            i = 0;
            continue;
        }
        i++;
    }
}

void * s21_trim(const char *src, const char *trim_chars) {
    char *return_str = S21_NULL;

    if (src) {
        if (trim_chars && *trim_chars) {
            s21_size_t len = s21_strlen(src);

            _s21_trim_left(&src, trim_chars, &len);
            if (len)
                _s21_trim_right(&src, trim_chars, &len);

            return_str = (char *)malloc(sizeof(char) * (len + 1));

            if (return_str) {
                for (s21_size_t i = 0; i < len + 1; i++) {
                    if (i < len)
                        return_str[i] = src[i];
                    else
                        return_str[i] = '\0';
                }
            }
        } else {
            return_str = s21_trim(src, "\t \n");
        }
    }
    return return_str;
}
