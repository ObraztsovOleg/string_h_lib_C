#include "s21_tests_suite.h"
#include <stdlib.h>

// <TO_LOWER>

START_TEST(test_01_s21_to_lower) {
    char str1[] = "DAWDA WDAFG";
    char res[] = "dawda wdafg";
    char *cop_fun = s21_to_lower(str1);
    ck_assert_str_eq(cop_fun, res);
    if (cop_fun) free(cop_fun);
} END_TEST

START_TEST(test_02_s21_to_lower) {
    char str1[] = "1350353";
    char res[] = "1350353";
    char *cop_fun = s21_to_lower(str1);
    ck_assert_str_eq(cop_fun, res);
    if (cop_fun) free(cop_fun);
} END_TEST

START_TEST(test_03_s21_to_lower) {
    char str1[] = " ";
    char res[] = " ";
    char *cop_fun = s21_to_lower(str1);
    ck_assert_str_eq(cop_fun, res);
    if (cop_fun) free(cop_fun);
} END_TEST

START_TEST(test_04_s21_to_lower) {
    char * str1 = S21_NULL;
    char * res = S21_NULL;
    char *cop_fun = s21_to_lower(str1);
    ck_assert_ptr_eq(cop_fun, res);
    if (cop_fun) free(cop_fun);
} END_TEST

// </TO_LOWER>


Suite * s21_to_lower_suite(void) {
    Suite * suite = suite_create("group of to lower tests");

    // TO_LOWER
    TCase * to_lower = tcase_create("to_lower_tests");

    tcase_add_test(to_lower, test_01_s21_to_lower);
    tcase_add_test(to_lower, test_02_s21_to_lower);
    tcase_add_test(to_lower, test_03_s21_to_lower);
    tcase_add_test(to_lower, test_04_s21_to_lower);
    suite_add_tcase(suite, to_lower);

    return suite;
}