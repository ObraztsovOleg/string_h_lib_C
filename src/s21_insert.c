#include "s21_string.h"
#include <stdlib.h>

void * s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char * new_line = S21_NULL;

    if (src != S21_NULL && str != S21_NULL) {
        s21_size_t src_len = s21_strlen(src);
        s21_size_t str_len = s21_strlen(str);

        s21_size_t gen_len = src_len + str_len;

        if (str_len >= start_index) {
            new_line = (char *)malloc(sizeof(char) * (gen_len + 1));
        }

        if (new_line) {
            for (s21_size_t i = 0, j = 0, k = 0; i < gen_len; i++) {
                if (i >= start_index && j < src_len) {
                    new_line[i] = src[j];
                    j++;
                } else {
                    new_line[i] = str[k];
                    k++;
                }
            }
            new_line[gen_len] = '\0';
        }
    }

    return new_line;
}
