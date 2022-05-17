#include "s21_tests_suite.h"

// <STRNCAT>

START_TEST(test_01_s21_strncat) {
    s21_size_t n = 2;
    char str_strncat[10] = "str";
    char str_s21_strncat[10] = "str";
    const char str_2[10] = "ncat";

    (void) strncat(str_strncat, str_2, n);
    (void) s21_strncat(str_s21_strncat, str_2, n);

    ck_assert_str_eq(str_strncat, str_s21_strncat);
} END_TEST

START_TEST(test_02_s21_strncat) {
    s21_size_t n = 10;
    char str_strncat[10] = "str";
    char str_s21_strncat[10] = "str";
    const char str_2[10] = "ncat";

    (void) strncat(str_strncat, str_2, n);
    (void) s21_strncat(str_s21_strncat, str_2, n);

    ck_assert_str_eq(str_strncat, str_s21_strncat);
} END_TEST

// </STRNCAT>

Suite * s21_strncat_suite(void) {
    Suite * suite = suite_create("group of strncat tests");
    
    // STRNCAT
    TCase * tc_strncat = tcase_create("strncat_tests");

    tcase_add_test(tc_strncat, test_01_s21_strncat);
    tcase_add_test(tc_strncat, test_02_s21_strncat);
    suite_add_tcase(suite, tc_strncat);

    return suite;
}
