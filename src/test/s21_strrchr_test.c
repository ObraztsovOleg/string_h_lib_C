#include "s21_tests_suite.h"

// <STRRCHR>

START_TEST(test_01_s21_strrchr) {
    char str[20] = "123456743";
    int c = '3';
    ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
} END_TEST

START_TEST(test_02_s21_strrchr) {
    char str[] = "1350353";
    int c = '0';
    ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
} END_TEST

START_TEST(test_03_s21_strrchr) {
    char str[] = "Hello friend";
    int c = 'e';
    ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
} END_TEST

START_TEST(test_04_s21_strrchr) {
    char str[] = "";
    int c = '1';
    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
} END_TEST

// </STRRCHR>

Suite * s21_strrchr_suite(void) {
    Suite * suite = suite_create("group of strrchr tests");

    // <STRRCHR>
    TCase * tc_strrchr = tcase_create("strrchr_tests");

    tcase_add_test(tc_strrchr, test_01_s21_strrchr);
    tcase_add_test(tc_strrchr, test_02_s21_strrchr);
    tcase_add_test(tc_strrchr, test_03_s21_strrchr);
    tcase_add_test(tc_strrchr, test_04_s21_strrchr);
    suite_add_tcase(suite, tc_strrchr);
    
    return suite;
} 