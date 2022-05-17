#include "s21_string.h"

int s21_strcmp(const char * str_1, const char * str_2) {
    for (; *str_1 && *str_1 == *str_2; str_1++, str_2++)
        continue;

    return (int) *str_1 - *str_2;
}
