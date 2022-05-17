#include "s21_string.h"
#include <stdlib.h>

void *s21_to_upper(const char *str) {
    char *strCop = S21_NULL;
    if (str != S21_NULL) {
        s21_size_t len = s21_strlen(str);

        strCop = (char*)malloc((len + 1)*sizeof(char));

        if (strCop) {
            for (s21_size_t i = 0; i <= len; i++) {
                if ('a' <= str[i] && str[i] <= 'z') {
                    strCop[i] = str[i] - 'z' + 'Z';
                } else {
                    strCop[i] = str[i];
                }
            }
            strCop[len] = '\0';
        }
    }

    return strCop;
}
