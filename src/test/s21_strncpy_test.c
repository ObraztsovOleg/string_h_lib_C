#include "s21_tests_suite.h"

// <STRNCPY>

// not full word
START_TEST(test_01_s21_strncpy) {
    char dest[10] = "";
    char src[10] = "src";
    s21_size_t n = 2;

    ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
} END_TEST

// full word
START_TEST(test_02_s21_strncpy) {
    char dest[10] = "";
    char src[10] = "src";
    s21_size_t n = 4;

    ck_assert_str_eq(strncpy(dest, src, n), s21_strncpy(dest, src, n));
} END_TEST

// </STRNCPY>

Suite * s21_strncpy_suite(void) {
    Suite * suite = suite_create("group of strncpy tests");
    
    // <STRNCPY>
    TCase * tc_strncpy = tcase_create("strncpy_tests");

    tcase_add_test(tc_strncpy, test_01_s21_strncpy);
    tcase_add_test(tc_strncpy, test_02_s21_strncpy);
    suite_add_tcase(suite, tc_strncpy);

    return suite;
}