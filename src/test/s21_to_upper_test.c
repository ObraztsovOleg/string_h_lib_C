#include "s21_tests_suite.h"
#include <stdlib.h>

// <TO_UPPER>

START_TEST(test_01_s21_to_upper) {
    char str1[] = "dfgsdfDS";
    char res[] = "DFGSDFDS";
    char *cop_fun = s21_to_upper(str1);
    ck_assert_str_eq(cop_fun, res);
    if (cop_fun) free(cop_fun);
} END_TEST

START_TEST(test_02_s21_to_upper) {
    char str1[] = "243#3";
    char res[] = "243#3";
    char *cop_fun = s21_to_upper(str1);
    ck_assert_str_eq(cop_fun, res);
    if (cop_fun) free(cop_fun);
} END_TEST

START_TEST(test_03_s21_to_upper) {
    char str1[] = "";
    char res[] = "";
    char *cop_fun = s21_to_upper(str1);
    ck_assert_str_eq(cop_fun, res);
    if (cop_fun) free(cop_fun);
} END_TEST

START_TEST(test_04_s21_to_upper) {
    char * str1 = S21_NULL;
    char * res = S21_NULL;
    char *cop_fun = s21_to_upper(str1);
    ck_assert_ptr_eq(cop_fun, res);
    if (cop_fun) free(cop_fun);
} END_TEST

// </TO_UPPER>

Suite * s21_to_upper_suite(void) {
    Suite * suite = suite_create("group of to upper tests");

    // TO_UPPER
    TCase * to_upper = tcase_create("to_upper_tests");

    tcase_add_test(to_upper, test_01_s21_to_upper);
    tcase_add_test(to_upper, test_02_s21_to_upper);
    tcase_add_test(to_upper, test_03_s21_to_upper);
    tcase_add_test(to_upper, test_04_s21_to_upper);
    suite_add_tcase(suite, to_upper);

    return suite;
}