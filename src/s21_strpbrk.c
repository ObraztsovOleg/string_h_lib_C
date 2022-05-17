#include "s21_string.h"

char * s21_strpbrk(const char *str1, const char *str2) {
    const char *c = str2;

    if (*str1) {
        while (*str1) {
            for (c = str2; *c; c++) {
                if (*str1 == *c)
                    break;
            }
            if (*c)
                break;
            str1++;
        }

        if (*c == '\0')
            str1 = S21_NULL;
    } else {
        str1 = S21_NULL;
    }

    return (char *) str1;
}
