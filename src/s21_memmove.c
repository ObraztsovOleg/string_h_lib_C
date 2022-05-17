#include "s21_string.h"

void * s21_memmove(void *dest, const void *src, s21_size_t len) {
    char * d = dest;
    char * s = (char *)src;

    if (d < s) {
        while (len--)
            *d++ = *s++;
    } else {
        char *lasts = s + (len-1);
        char *lastd = d + (len-1);

        while (len--)
            *lastd-- = *lasts--;
    }

    return dest;
}
