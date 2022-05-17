#include "s21_string.h"

int _is_delim(char c, const char * delim) {
    int ret = 0;

    while (*delim != '\0') {
        if (c == *delim) {
            ret = 1;
            break;
        }
        delim++;
    }

    return ret;
}

char * s21_strtok(char * str, const char * delim) {
    char * ret = S21_NULL;
    int exit = 0;
    static char * backup_tmp;

    if (!str) str = backup_tmp;
    if (!str) {
        ret = S21_NULL;
        exit = 1;
    }

    if (!exit) {
        while (1) {
            if (_is_delim(*str, delim)) {
                str++;
                continue;
            }

            if (*str == '\0') {
                ret = S21_NULL;
                exit = 1;
                break;
            }

            break;
        }
    }

    if (!exit) {
        ret = str;
        while (1) {
            if (*str == '\0') {
                backup_tmp = str;
                break;
            }

            if (_is_delim(*str, delim)) {
                *str = '\0';
                backup_tmp = str + 1;
                break;
            }

            str++;
        }
    }

    return ret;
}
