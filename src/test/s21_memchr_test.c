#include "s21_tests_suite.h"

// </MEMCHR>

START_TEST(test_01_s21_memchr) {
    char src[15] = "1234567890";
    char src_21[15] = "1234567890";

    char * sym, * sym_s21;

    sym = memchr(src, '4', 10);
    sym_s21 = s21_memchr(src_21, '4', 10);

    if (sym != NULL)
        sym[0] = '!';

    if (sym != NULL)
        sym_s21[0] = '!';

    ck_assert_str_eq(src, src_21);
} END_TEST

START_TEST(test_02_s21_memchr) {
    char src[15] = "1234567890";
    char src_21[15] = "1234567890";

    char * sym, * sym_s21;

    sym = memchr(src, 'f', 10);
    sym_s21 = s21_memchr(src_21, 'f', 10);

    ck_assert_ptr_eq(sym, sym_s21);
} END_TEST

// </MEMCHR>

Suite * s21_memchr_suite(void) {
    Suite * suite = suite_create("group of memchr tests");

    // MEMCHR
    TCase * tc_memchr = tcase_create("memchr_tests");

    tcase_add_test(tc_memchr, test_01_s21_memchr);
    tcase_add_test(tc_memchr, test_02_s21_memchr);
    suite_add_tcase(suite, tc_memchr);

    return suite;
}