#include "s21_string.h"

char * s21_strchr(const char * str, int c) {
    const char ch = c;
    char * ptr = (char *)str;

    for (; *ptr != ch; ptr++) {
        if (*ptr == '\0') {
            ptr = S21_NULL;
            break;
        }
    }

    return ptr;
}
