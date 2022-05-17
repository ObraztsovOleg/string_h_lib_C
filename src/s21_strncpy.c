#include "s21_string.h"

char * s21_strncpy(char *dest, const char *src, s21_size_t n) {
    char *s;
    for (s = dest; 0 < n && *src != '\0'; n--)
        *s++ = *src++;
    for (; 0 < n; n--)
        *s++ = '\0';
    return dest;
}
