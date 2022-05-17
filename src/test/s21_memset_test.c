#include "s21_tests_suite.h"

// <MEMSET>

START_TEST(test_01_s21_memset) {
    char str[] = "almost every programmer should know memset!";
    char str_s21[] = "almost every programmer should know memset!";

    memset(str, '-', 6);
    s21_memset(str_s21, '-', 6);

    ck_assert_str_eq(str, str_s21);
} END_TEST

// </MEMSET>

Suite * s21_memset_suite(void) {
    Suite * suite = suite_create("group of memset tests");

    // MEMSET
    TCase * tc_memset = tcase_create("memset_tests");

    tcase_add_test(tc_memset, test_01_s21_memset);
    suite_add_tcase(suite, tc_memset);

    return suite;
}