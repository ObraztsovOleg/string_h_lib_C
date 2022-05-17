#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

// internal flag definitions
#define FLAGS_ZEROPAD                   (1U <<  0U)
#define FLAGS_LEFT                      (1U <<  1U)
#define FLAGS_PLUS                      (1U <<  2U)
#define FLAGS_SPACE                     (1U <<  3U)
#define FLAGS_HASH                      (1U <<  4U)
#define FLAGS_UPPERCASE                 (1U <<  5U)
#define FLAGS_OUTOFRANGE                (1U <<  6U)

// #define FLAGS_CHAR      (1U <<  6U)
#define FLAGS_SHORT                     (1U <<  7U)
#define FLAGS_LONG                      (1U <<  8U)

// #define FLAGS_LONG_LONG (1U <<  9U)
#define FLAGS_PRECISION                 (1U << 10U)
#define FLAGS_ADAPT_EXP                 (1U << 11U)

#define PRINTF_NTOA_BUFFER_SIZE         32U
#define PRINTF_FTOA_BUFFER_SIZE         32U
#define PRINTF_MAX_FLOAT                1e9
#define PRINTF_DEFAULT_FLOAT_PRECISION  6U
#define INT_MAX                         2147483647
#define INT_MIN                         -2147483647
#define UINT_MAX                        4294967295UL
#define S21_NAN                         0./0.

#define S21_NULL (void *)0
typedef long unsigned s21_size_t;

char * s21_strcat(char * dest, const char * src);
char * s21_strncat(char *dest, const char *src, s21_size_t n);
char * s21_strchr(const char * str, int c);
int s21_strcmp(const char *str_1, const char *str_2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char * s21_strncpy(char *dest, const char *src, s21_size_t n);
char * s21_strcpy(char *strDest, const char *strSrc);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char * s21_strpbrk(const char * str1, const char *str2);
char * s21_strrchr(const char * str, int c);
s21_size_t s21_strspn(const char * str1, const char *str2);
s21_size_t s21_strlen(const char * str);
char * s21_strstr(const char * s1, const char *s2);
char * s21_strtok(char * str, const char * delim);
char * s21_strerror(int err);
void * s21_memchr(const void * str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void * s21_memcpy(void *dest, const void *src, s21_size_t n);
void * s21_memmove(void *dest, const void *src, s21_size_t len);
void * s21_memset(void* buf, int val, s21_size_t bytes);
int s21_sprintf(char * buffer, const char * format, ...);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);

// output function type
typedef void (* out_fct_type)(char character, void * buffer, s21_size_t idx, s21_size_t maxlen);

#endif  // SRC_S21_STRING_H_
