#include "s21_string.h"

char * s21_strstr(const char * str_1, const char * str_2) {
    const s21_size_t len = s21_strlen(str_2);
    char * ptr = (char *) str_1;

    while (*ptr) {
        if (!s21_memcmp(ptr, str_2, len))
            break;

        ++ptr;

        if (*ptr == '\0') {
            ptr = S21_NULL;
            break;
        }
    }
    return (char *) ptr;
}
