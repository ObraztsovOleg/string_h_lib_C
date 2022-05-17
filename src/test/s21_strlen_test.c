#include <check.h>
#include "../s21_string.h"
#include <string.h>
#include "s21_tests_suite.h"

// <STRLEN>

START_TEST(test_01_s21_strlen) {
    const char str[10] = "21_shool";

    ck_assert_int_eq(s21_strlen(str), strlen(str));
} END_TEST

START_TEST(test_02_s21_strlen) {
    const char str[10] = "     ";

    ck_assert_int_eq(s21_strlen(str), strlen(str));
} END_TEST

// </STRLEN>

Suite * s21_strlen_suite(void) {
    Suite * suite = suite_create("group of strlen tests");

    // STRLEN
    TCase * tc_strlen = tcase_create("strlen_tests");

    tcase_add_test(tc_strlen, test_01_s21_strlen);
    tcase_add_test(tc_strlen, test_02_s21_strlen);
    suite_add_tcase(suite, tc_strlen);

    return suite;
}