#include "s21_tests_suite.h"

// <STRCAT>

START_TEST(test_01_s21_strcat) {
    char str_strcat[10] = "str";
    char str_s21_strcat[10] = "str";
    const char str_2[10] = "cat";

    (void) strcat(str_strcat, str_2);
    (void) s21_strcat(str_s21_strcat, str_2);

    ck_assert_str_eq(str_strcat, str_s21_strcat);
} END_TEST

// </STRCAT>

Suite * s21_strcat_suite(void) {
    Suite * suite = suite_create("group of strcat tests");

    // STRCAT
    TCase * tc_strcat = tcase_create("strcat_tests");

    tcase_add_test(tc_strcat, test_01_s21_strcat);
    suite_add_tcase(suite, tc_strcat);

    return suite;
}