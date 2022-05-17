#include "s21_tests_suite.h"

// <STRNCMP>

// 2 symbols of strings eq
START_TEST(test_01_s21_strncmp) {
    char str1[10] = "strncmp";
    char str2[10] = "strncmp";
    s21_size_t n = 2;

    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));;
} END_TEST

// strings full eq
START_TEST(test_02_s21_strncmp) {
    char str1[10] = "strncmp";
    char str2[10] = "strncmp";
    s21_size_t n = 8;

    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
} END_TEST

// strings not eq version1
START_TEST(test_03_s21_strncmp) {
    char str1[10] = "cmpstrn";
    char str2[10] = "strncmp";
    s21_size_t n = 2;

    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
} END_TEST

// strings not eq version2
START_TEST(test_04_s21_strncmp) {
    char str1[10] = "strncmp";
    char str2[10] = "cmpstrn";
    s21_size_t n = 2;

    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
} END_TEST

// </STRNCMP>

Suite * s21_strncmp_suite(void) {
    Suite * suite = suite_create("group of strncmp tests");

    // STRNCMP
    TCase * tc_strncmp = tcase_create("strncmp_tests");

    tcase_add_test(tc_strncmp, test_01_s21_strncmp);
    tcase_add_test(tc_strncmp, test_02_s21_strncmp);
    tcase_add_test(tc_strncmp, test_03_s21_strncmp);
    tcase_add_test(tc_strncmp, test_04_s21_strncmp);
    suite_add_tcase(suite, tc_strncmp);

    return suite;
} 