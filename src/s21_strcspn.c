#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    const char *sc1, *sc2;
    int ret = 0;

    for (sc1 = str1; *sc1 != '\0'; sc1++) {
        for (sc2 = str2; *sc2 != '\0'; sc2++) {
            if (*sc1 == *sc2) {
                ret = 1;
                break;
            }
        }
        if (ret) break;
    }

    return (sc1 - str1);
}
