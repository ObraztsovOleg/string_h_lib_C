#include "s21_tests_suite.h"

// <STRCMP>

// strings eq
START_TEST(test_01_s21_strcmp) {
    char str1[10] = "strcmp";
    char str2[10] = "strcmp";

    ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
} END_TEST

// strings not eq version1
START_TEST(test_02_s21_strcmp) {
    char str1[10] = "cmpstr";
    char str2[10] = "strcmp";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

// strings not eq version2
START_TEST(test_03_s21_strcmp) {
    char str1[10] = "strcmp";
    char str2[10] = "cmpstr";

    ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
} END_TEST

// </STRCMP>

Suite * s21_strcmp_suite(void) {
    Suite * suite = suite_create("group of strcmp tests");

    // STRCMP
    TCase * tc_strcmp = tcase_create("strcmp_tests");

    tcase_add_test(tc_strcmp, test_01_s21_strcmp);
    tcase_add_test(tc_strcmp, test_02_s21_strcmp);
    tcase_add_test(tc_strcmp, test_03_s21_strcmp);
    suite_add_tcase(suite, tc_strcmp);

    return suite;
}