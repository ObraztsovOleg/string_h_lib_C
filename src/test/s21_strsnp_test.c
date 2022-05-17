#include "s21_tests_suite.h"

// <STRSPN>

START_TEST(test_01_s21_strspn) {
    char str1[] = "this is a test";
    char str2[] = "stha ";
    ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
} END_TEST

START_TEST(test_02_s21_strspn) {
    char str1[] = "this is a test";
    char str2[] = "yv";
    ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
} END_TEST

// </STRSPN>
Suite * s21_strsnp_suite(void) {
    Suite * suite = suite_create("group of strsnp tests");

    // <STRSPN>
    TCase * tc_strspn = tcase_create("strspn_tests");

    tcase_add_test(tc_strspn, test_01_s21_strspn);
    tcase_add_test(tc_strspn, test_02_s21_strspn);
    suite_add_tcase(suite, tc_strspn);

    return suite;
} 