#include "s21_string.h"

char * s21_strrchr(const char *str, int c) {
    char *k = S21_NULL;
    while (*str != '\0') {
        if (*str == c) {
            k = (char*)str;
        }
        str++;
    }
    return k;
}
