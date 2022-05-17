#include "s21_string.h"

void * s21_memset(void * buf, int val, s21_size_t bytes) {
    unsigned char *ptr = buf;
    while (bytes--)
        *ptr++ = val;

    return buf;
}
