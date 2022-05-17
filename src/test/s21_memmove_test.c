#include "s21_tests_suite.h"

// <MEMMOVE>

START_TEST(test_01_s21_memmove) {
    char str[] = "Geeks";
    char str_s21[] = "Geeks";
    char str2[] = "Quiz";

    memmove(str, str2, sizeof(str2));
    s21_memmove(str_s21, str2, sizeof(str2));

    ck_assert_str_eq(str, str_s21);
} END_TEST

START_TEST(test_02_s21_memmove) {
    char str2[6] = "Geeks";
    char str[6] = "";
    char str_s21[6] = "";

    memmove(str, str2, 5);
    s21_memmove(str_s21, str2, 5);

    ck_assert_str_eq(str, str_s21);
} END_TEST

START_TEST(test_03_s21_memmove) {
    char str1[] = "Geek";
    char str1_s21[] = "Geek";
    char str2[] = "Quiz";
    char str2_s21[] = "Quiz";
    s21_memmove(str1_s21, str2_s21, sizeof(str2_s21));
    memmove(str1, str2, sizeof(str2));

    ck_assert_str_eq(str1, str1_s21);
} END_TEST

// </MEMMOVE>

Suite * s21_memmove_suite(void) {
    Suite * suite = suite_create("group of memmove tests");

    // MEMMOVE
    TCase * tc_memmove = tcase_create("memmove_tests");

    tcase_add_test(tc_memmove, test_01_s21_memmove);
    tcase_add_test(tc_memmove, test_02_s21_memmove);
    tcase_add_test(tc_memmove, test_03_s21_memmove);
    suite_add_tcase(suite, tc_memmove);

    return suite;
}