#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
    char *s = dest;
    for (; (*s++ = *src++) != '\0';)
        continue;
    return dest;
}
