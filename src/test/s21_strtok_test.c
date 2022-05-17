#include "s21_tests_suite.h"

// <STRTOK>

START_TEST(test_01_s21_strtok) {
    char strs[] = "test1/test2/test3/test4";
    char sep[] = "/";
    ck_assert_str_eq(s21_strtok(strs, sep), strtok(strs, sep));
} END_TEST

START_TEST(test_02_s21_strtok) {
    char strs[] = "mama_mula_ramu";
    char sep[] = "_";
    ck_assert_str_eq(s21_strtok(strs, sep), strtok(strs, sep));
} END_TEST

START_TEST(test_03_s21_strtok) {
    char strs[] = "mama_mula_ramu";
    char sep[] = "mama_mula_ramu";

    char * ret = strtok(strs, sep);
    char * ret_s21 = s21_strtok(strs, sep);
    int ret_num = 0;
    int ret_num_s21 = 0;

    if (ret_s21 == 0)
        ret_num_s21 = 1;
    if (ret == 0)
        ret_num = 1;

    ck_assert_int_eq(ret_num, ret_num_s21);
} END_TEST

START_TEST(test_04_s21_strtok) {
    char strs[] = "";
    char sep[] = "234";

    char * ret = strtok(strs, sep);
    char * ret_s21 = s21_strtok(strs, sep);
    int ret_num = 0;
    int ret_num_s21 = 0;

    if (ret_s21 == 0)
        ret_num_s21 = 1;
    if (ret == 0)
        ret_num = 1;

    ck_assert_int_eq(ret_num, ret_num_s21);
} END_TEST

START_TEST(test_05_s21_strtok) {
    char strs[4] = "234";
    char sep[1] = "";

    char * ret = strtok(strs, sep);
    char * ret_s21 = s21_strtok(strs, sep);
    int ret_num = 0;
    int ret_num_s21 = 0;

    if (ret_s21 == 0)
        ret_num_s21 = 1;
    if (ret == 0)
        ret_num = 1;

    ck_assert_int_eq(ret_num, ret_num_s21);
} END_TEST

START_TEST(test_06_s21_strtok) {
    char strs[1] = "";
    char sep[1] = "";

    char * ret = strtok(strs, sep);
    char * ret_s21 = s21_strtok(strs, sep);
    int ret_num = 0;
    int ret_num_s21 = 0;

    if (ret_s21 == 0)
        ret_num_s21 = 1;
    if (ret == 0)
        ret_num = 1;

    ck_assert_int_eq(ret_num, ret_num_s21);
} END_TEST

// </STRTOK>

Suite * s21_strtok_suite(void) {
    Suite * suite = suite_create("group of strtok tests");

    // <STRTOK>
    TCase * tc_strtok = tcase_create("strtok_tests");

    tcase_add_test(tc_strtok, test_01_s21_strtok);
    tcase_add_test(tc_strtok, test_02_s21_strtok);
    tcase_add_test(tc_strtok, test_03_s21_strtok);
    tcase_add_test(tc_strtok, test_04_s21_strtok);
    tcase_add_test(tc_strtok, test_05_s21_strtok);
    tcase_add_test(tc_strtok, test_06_s21_strtok);
    suite_add_tcase(suite, tc_strtok);

    return suite;
} 