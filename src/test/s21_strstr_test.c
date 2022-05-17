#include "s21_tests_suite.h"

// <STRSTR>

START_TEST(test_01_s21_strstr) {
    char str1[] = "0123456789";
    char str2[] = "456";
    ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
} END_TEST

START_TEST(test_02_s21_strstr) {
    char str1[] = "";
    char str2[] = "";
    ck_assert_str_eq(s21_strstr(str1, str2), strstr(str1, str2));
} END_TEST

START_TEST(test_03_s21_strstr) {
    char str1[] = "234";
    char str2[] = "1";
    char * ret = strstr(str1, str2);
    char * ret_s21 = s21_strstr(str1, str2);
    int ret_num = 0;
    int ret_num_s21 = 0;

    if (ret_s21 == 0)
        ret_num_s21 = 1;
    if (ret == 0)
        ret_num = 1;

    ck_assert_int_eq(ret_num, ret_num_s21);
} END_TEST

// </STRSTR>

Suite * s21_strstr_suite(void) {
    Suite * suite = suite_create("group of strstr tests");

    // <STRSTR>
    TCase * tc_strstr = tcase_create("strstr_tests");

    tcase_add_test(tc_strstr, test_01_s21_strstr);
    tcase_add_test(tc_strstr, test_02_s21_strstr);
    tcase_add_test(tc_strstr, test_03_s21_strstr);
    suite_add_tcase(suite, tc_strstr);

    return suite;
} 