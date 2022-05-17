#include "s21_tests_suite.h"

// </STRERROR>

START_TEST(test_01_s21_strerror) {
    ck_assert_str_eq(s21_strerror(10), strerror(10));
} END_TEST

START_TEST(test_02_s21_strerror) {
    ck_assert_str_eq(s21_strerror(200), strerror(200));
} END_TEST

START_TEST(test_03_s21_strerror) {
    ck_assert_str_eq(s21_strerror(-1), strerror(-1));
} END_TEST

// </STRERROR>

Suite * s21_strerror_suite(void) {
    Suite * suite = suite_create("group of strerror tests");

    // STRERROR
    TCase * tc_strerror = tcase_create("strerror_tests");

    tcase_add_test(tc_strerror, test_01_s21_strerror);
    tcase_add_test(tc_strerror, test_02_s21_strerror);
    tcase_add_test(tc_strerror, test_03_s21_strerror);
    suite_add_tcase(suite, tc_strerror);

    return suite;
} 