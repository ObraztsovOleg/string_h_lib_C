#include "s21_tests_suite.h"

// <STRCHR>

// access func
START_TEST(test_01_s21_strchr) {
    char str_strchr[10] = "str chr";
    char str_s21_strchr[10] = "str chr";
    const char ch = ' ';

    (void) strchr(str_strchr, ch);
    (void) s21_strchr(str_s21_strchr, ch);

    ck_assert_str_eq(str_strchr, str_s21_strchr);
} END_TEST

// failed func
START_TEST(test_02_s21_strchr) {
    char str_strchr[10] = "str chr";
    char str_s21_strchr[10] = "str chr";
    const char ch = '!';

    (void) strchr(str_strchr, ch);
    (void) s21_strchr(str_s21_strchr, ch);

    ck_assert_str_eq(str_strchr, str_s21_strchr);
} END_TEST

// </STRCHR>

Suite * s21_strchr_suite(void) {
    Suite * suite = suite_create("group of strchr tests");
    
    // STRCHR
    TCase * tc_strchr = tcase_create("strchr_tests");

    tcase_add_test(tc_strchr, test_01_s21_strchr);
    tcase_add_test(tc_strchr, test_02_s21_strchr);
    suite_add_tcase(suite, tc_strchr);

    return suite;
}