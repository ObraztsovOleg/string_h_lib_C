#include "s21_tests_suite.h"

// <STRCPY>

START_TEST(test_01_s21_strcpy) {
    char dest[10] = "";
    char src[10] = "src";

    char dest_s21[10] = "";
    char src_s21[10] = "src";

    ck_assert_str_eq(strcpy(dest, src), s21_strcpy(dest_s21, src_s21));
} END_TEST

// </STRCPY>

Suite * s21_strcpy_suite(void) {
    Suite * suite = suite_create("group of strcpy tests");

    // STRCPY
    TCase * tc_strcpy = tcase_create("strcpy_tests");

    tcase_add_test(tc_strcpy, test_01_s21_strcpy);
    suite_add_tcase(suite, tc_strcpy);

    return suite;
}