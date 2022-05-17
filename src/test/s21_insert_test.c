#include "s21_tests_suite.h"
#include <stdlib.h>

START_TEST(test_01_s21_insert) {
    char str_test0[] = "01234";
    char src_test0[] = "56789";
    char expect[] = "0123567894";
    char * got = s21_insert(src_test0, str_test0, 4);
    ck_assert_str_eq(got, expect);

	if (got != S21_NULL) free(got);
} END_TEST



START_TEST(test_02_s21_insert) {
    char str_test1[] = "0123 1234";
    char src_test1[] = "567_89";

    char expect[] = "0123 567_891234";
    char * got = s21_insert(src_test1, str_test1, 5);
    ck_assert_str_eq(got, expect);

	free(got);
} END_TEST


START_TEST(test_03_s21_insert) {
    char str_test2[] = "H4444kj";
    char src_test2[] = "56712312__89";
    char * expect = S21_NULL;
    char *got = s21_insert(src_test2, str_test2, 122);
    ck_assert_ptr_eq(got, expect);

	free(got);
} END_TEST

START_TEST(test_04_s21_insert) {
    char str_test3[] = "Hello";
    char src_test3[] = ",World!";
    char expect[] = "Hello,World!";
    char * got = s21_insert(src_test3, str_test3, 5);
    ck_assert_str_eq(got, expect);

	free(got);
} END_TEST

START_TEST(test_05_s21_insert) {
    char str_test4[] = " 1231                23";
    char src_test4[] = "inserted123  ";
    char expect[] = " 1231            inserted123      23";
    char *got = s21_insert(src_test4, str_test4, 17);
    ck_assert_str_eq(got, expect);

	free(got);
} END_TEST


START_TEST(test_06_s21_insert) {
char str_test5[] = "123";
char src_test5[] = "K123123illM123333";
char *expect = S21_NULL;
char *got = s21_insert(src_test5, str_test5, -1);
ck_assert_ptr_eq(got, expect);
if (got)
	free(got);
} END_TEST

Suite * s21_insert_suite(void) {
	Suite * suite = suite_create("group of insert tests");

    // <INSERT>
    TCase * tc_insert = tcase_create("insert_tests");
    
    tcase_add_test(tc_insert, test_01_s21_insert);
    tcase_add_test(tc_insert, test_02_s21_insert);
    tcase_add_test(tc_insert, test_03_s21_insert);
    tcase_add_test(tc_insert, test_04_s21_insert);
    tcase_add_test(tc_insert, test_05_s21_insert);
    tcase_add_test(tc_insert, test_06_s21_insert);
    suite_add_tcase(suite, tc_insert);

	return suite;
}
