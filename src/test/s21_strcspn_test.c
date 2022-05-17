#include "s21_tests_suite.h"

// <STRCSPN>

START_TEST(test_01_s21_strcspn) {
    char str1[10] = "012345678";
    char str2[10] = "876";

    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
} END_TEST

START_TEST(test_02_s21_strcspn) {
    char str1[10] = "0123456";
    char str2[10] = "978";

    ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1, str2));
} END_TEST

// </STRCSPN>

Suite * s21_strcspn_suite(void) {
    Suite * suite = suite_create("group of strcspn tests");

    // STRCSPN
    TCase * tc_strcspn = tcase_create("strcspn_tests");

    tcase_add_test(tc_strcspn, test_01_s21_strcspn);
    tcase_add_test(tc_strcspn, test_02_s21_strcspn);
    suite_add_tcase(suite, tc_strcspn);

    return suite;
}