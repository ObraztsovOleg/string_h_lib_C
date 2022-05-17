#include "s21_tests_suite.h"

// <MEMCMP>

START_TEST(test_01_s21_memcmp) {
    char first[]  = "12345678901234567890";
    char second[] = "12345678901234567891";

    int result = memcmp(first, second, 19);
    int result_s21 = s21_memcmp(first, second, 19);

    ck_assert_int_eq(result, result_s21);
} END_TEST

START_TEST(test_02_s21_memcmp) {
    char first[]  = "12345678901234567890";
    char second[] = "12345678901234567891";

    int result = memcmp(first, second, 0);
    int result_s21 = s21_memcmp(first, second, 0);

    ck_assert_int_eq(result, result_s21);
} END_TEST

START_TEST(test_03_s21_memcmp) {
    char first[]  = "12345678901234567890";
    char second[] = "12345678901234567891";

    int result = memcmp(first, second, 0);
    int result_s21 = s21_memcmp(first, second, 0);

    ck_assert_int_eq(result, result_s21);
} END_TEST

// </MEMCMP>

Suite * s21_memcmp_suite(void) {
    Suite * suite = suite_create("group of memcmp tests");

    // MEMCMP
    TCase * tc_memcmp = tcase_create("memcmp_tests");

    tcase_add_test(tc_memcmp, test_01_s21_memcmp);
    tcase_add_test(tc_memcmp, test_02_s21_memcmp);
    tcase_add_test(tc_memcmp, test_03_s21_memcmp);
    suite_add_tcase(suite, tc_memcmp);

    return suite;
}