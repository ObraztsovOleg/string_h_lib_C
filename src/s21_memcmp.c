#include "s21_string.h"

int s21_memcmp(const void * str1, const void * str2, s21_size_t n) {
    char * str_1_char = (char *) str1;
    char * str_2_char = (char *) str2;
    int diff = 0;

    if (n != 0) {
        for (; --n && *str_1_char && *str_1_char == *str_2_char; str_1_char++, str_2_char++)
            continue;

        diff = *((unsigned char*)str_1_char) - *((unsigned char*)str_2_char);
    }

    return diff;
}
