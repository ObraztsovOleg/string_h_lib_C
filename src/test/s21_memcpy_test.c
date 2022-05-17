#include "s21_tests_suite.h"

// <MEMCPY>

START_TEST(test_01_s21_memcpy) {
    const char src[50] = "http://www.tutorialspoint.com";
    char dest_s21[50], dest[50];

    memcpy(dest, src, strlen(src) + 1);
    s21_memcpy(dest_s21, src, strlen(src) + 1);

    ck_assert_str_eq(dest, dest_s21);
} END_TEST

// </MEMCPY>

Suite * s21_memcpy_suite(void) {
    Suite * suite = suite_create("group of memcpy tests");

    // MEMCPY
    TCase * tc_memcpy = tcase_create("memcpy_tests");

    tcase_add_test(tc_memcpy, test_01_s21_memcpy);
    suite_add_tcase(suite, tc_memcpy);

    return suite;
}