#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    for (; n > 0 && *str1 && *str1 == *str2; str1++, str2++, n--)
        continue;

    return (int) *str1 - *str2;
}
