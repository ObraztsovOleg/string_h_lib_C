#include "s21_tests_suite.h"
#include <stdlib.h>

START_TEST(trim_test1) {
    char *str = "_-_!Test_1-!";
    char *trim_ch = "!-_";
    char *expect = "Test_1";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST


START_TEST(trim_test2) {
    char *str = "Test_210";
    char *trim_ch = "01";
    char *expect = "Test_2";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST

START_TEST(trim_test3) {
    char *str = "Test_3";
    char *trim_ch = "_";
    char *expect = "Test_3";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST

START_TEST(trim_test4) {
    char *str = "!._ .Test_4!. _";
    char *trim_ch = ".!_ ";
    char *expect = "Test_4";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST

START_TEST(trim_test5) {
    char *str = " Test_5  ";
    char *trim_ch = " ";
    char *expect = "Test_5";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST

START_TEST(trim_test6) {
    char *str = "";
    char *trim_ch = "";
    char *expect = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST

START_TEST(trim_test7) {
    char *str = "";
    char *trim_ch = "Test_7";
    char *expect = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST

START_TEST(trim_test8) {
    char *str = "Test_8";
    char *trim_ch = "";
    char *expect = "Test_8";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST

START_TEST(trim_test9) {
    char *str = "Test_9";
    char *trim_ch = "Test_9";
    char *expect = "";
    char *got = s21_trim(str, trim_ch);
    ck_assert_str_eq(got, expect);
    if (got)
        free(got);
} END_TEST

Suite *s21_trim_suite(void) {
    Suite *s = suite_create("group of trim tests");
    TCase *tc = tcase_create("trim_tests");

    tcase_add_test(tc, trim_test1);
    tcase_add_test(tc, trim_test2);
    tcase_add_test(tc, trim_test3);
    tcase_add_test(tc, trim_test4);
    tcase_add_test(tc, trim_test5);
    tcase_add_test(tc, trim_test6);
    tcase_add_test(tc, trim_test7);
    tcase_add_test(tc, trim_test8);
    tcase_add_test(tc, trim_test9);

    suite_add_tcase(s, tc);

    return s;
}
