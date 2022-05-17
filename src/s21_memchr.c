#include "s21_string.h"

void * s21_memchr(const void * str, int c, s21_size_t n) {
    s21_size_t i;
    char * p = S21_NULL;

    for (i = 0; i < n; i++) {
        if (*((char*)str + i) == c) {
            p = (char *)str + i;
            break;
        } else {
            p = S21_NULL;
        }
    }

    return p;
}
