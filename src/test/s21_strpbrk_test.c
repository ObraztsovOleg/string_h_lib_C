#include "s21_tests_suite.h"

// <STRPBRK>

START_TEST(test_01_s21_strpbrk) {
    char str1[] = "this is a test";
    char str2[] = "absj";
    ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
} END_TEST

START_TEST(test_02_s21_strpbrk) {
    char str1[] = "this is a test";
    char str2[] = "bj";
    ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
} END_TEST

START_TEST(test_03_s21_strpbrk) {
    char str1[] = "";
    char str2[] = "da";
    ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
} END_TEST

// </STRPBRK>

Suite * s21_strpbrk_suite(void) {
    Suite * suite = suite_create("group of strpbrk tests");

    // <STRPBRK>
    TCase * tc_strpbrk = tcase_create("strpbrk_tests");

    tcase_add_test(tc_strpbrk, test_01_s21_strpbrk);
    tcase_add_test(tc_strpbrk, test_02_s21_strpbrk);
    tcase_add_test(tc_strpbrk, test_03_s21_strpbrk);
    suite_add_tcase(suite, tc_strpbrk);

    return suite;
}