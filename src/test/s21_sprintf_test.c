#include "s21_tests_suite.h"

#define compare_sprintf_func(original_fun, str_sprintf, n_sprintf,              \
                            s21_fun, str_s21_sprintf, n_s21_sprintf , fmt, ...) \
    n_sprintf = original_fun(str_sprintf, fmt, __VA_ARGS__);                    \
    n_s21_sprintf = s21_fun(str_s21_sprintf, fmt, __VA_ARGS__);                 \
    ck_assert_str_eq(str_sprintf, str_s21_sprintf);                             \
    ck_assert_int_eq(n_sprintf, n_s21_sprintf);

// <SPRINTF>

char str_sprintf[512];
char str_s21_sprintf[512];
int n_sprintf, n_s21_sprintf;
const char * NULL_STR = NULL;

// INT test
START_TEST(test_01_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %d", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "%d:%d:%d", 7, 4, 0);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "MAX %d", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "MIN %d", INT_MIN);
} END_TEST

// %i test
START_TEST(test_02_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %i", 3534555);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %+d", 3534555);
} END_TEST

// %i padding test
START_TEST(test_03_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5d'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5d'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5d'", INT_MIN);
} END_TEST

// %i padding lead zero test
START_TEST(test_04_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05d'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05d'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05d'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_05_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5d'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5d'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5d'", INT_MIN);
} END_TEST

// %i precision test & long
START_TEST(test_06_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5d'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5ld'", 4294967295);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5d'", INT_MIN);
} END_TEST

// %i precision test
START_TEST(test_07_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5d'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5d'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5d'", INT_MIN);
} END_TEST

// %i precision left-justify test
START_TEST(test_08_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5d'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5d'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5d'", INT_MIN);
} END_TEST

// Unsigned integers test
START_TEST(test_09_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %u", 7U);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "%u:%u:%u", 7U, 4U, 0U);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "MAX %lu", UINT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "MIN %u", 0U);
} END_TEST

// Unsigned integers padding test
START_TEST(test_10_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5u'", 7U);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5lu'", UINT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5u'", 0U);
} END_TEST

// Unsigned integers padding left-justify test
START_TEST(test_11_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5u'", 7U);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5lu'", UINT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5u'", 0U);
} END_TEST

// Unsigned integers precision test
START_TEST(test_12_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5u'", 7U);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5lu'", UINT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5u'", 0U);
} END_TEST

// Unsigned integers precision left-justify test
START_TEST(test_13_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5u'", 7U);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5lu'", UINT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5u'", 0U);
} END_TEST

// Unsigned integers precision right-justify test
START_TEST(test_14_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5u'", 7U);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5lu'", UINT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5u'", 0U);
} END_TEST

START_TEST(test_15_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %s", "Mundo");
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "%s:%s:%s", "Mi Mundo", "es", "asin");
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Nothing '%s'", "");
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "NULL '%s'", NULL_STR);
} END_TEST

START_TEST(test_16_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5s'", "bar");
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5s'", "barfoobar");
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5s'", "bar");
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5s'", "barfoobar");
} END_TEST

START_TEST(test_17_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5s'", "bar");
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5s'", "barfoobar");
} END_TEST

// %f test
START_TEST(test_18_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %f", 353.4555);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %+f", 353.4555);
} END_TEST

// % padding test
START_TEST(test_19_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5.5f'", 7423423.4233423423442344234230);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5f'", PRINTF_MAX_FLOAT);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5f'", -PRINTF_MAX_FLOAT);
} END_TEST

// %i padding lead zero test
START_TEST(test_20_s21_sprintf) {
    double inf = 2 * DBL_MAX;
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%#05f'", 7.03423423423);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05f'", inf);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05f'", -inf);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%f'", S21_NAN);
} END_TEST

// %i padding left-justify test
START_TEST(test_21_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '% -5f'", 7.034523423423);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5f'", PRINTF_MAX_FLOAT);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5f'", -PRINTF_MAX_FLOAT);
} END_TEST

// %i padding left-justify test
START_TEST(test_22_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.0f'", 7.034523423423);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.4f'", 7.3445632);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%f'", 8.);
} END_TEST

// %i padding left-justify test
START_TEST(test_23_s21_sprintf) {
    s21_sprintf(str_s21_sprintf, "'%.4f'", DBL_MAX);
    ck_assert_str_eq(str_s21_sprintf, "'null'");
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.10f'", 7.3445632);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.1f'", 0.99);
} END_TEST

// %i padding left-justify test
START_TEST(test_24_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %x", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "%X:%x:%X", 7, 11, 11);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "MAX %x", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                    str_s21_sprintf, n_s21_sprintf, "MIN %x", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_25_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %x", 3534555);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %#x", 3534555);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %#X", 3534555);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5x'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5x'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5x'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_26_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05x'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05x'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05x'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_27_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5x'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5x'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5x'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_28_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5X'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5x'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%.5x'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_29_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5x'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5x'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%3.5x'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_30_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5x'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5x'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "precision '%-3.5x'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_31_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %o", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "%o:%o:%o", 7, 11, 11);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "MAX %o", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "MIN %o", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_32_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "Hola %o", 3534555);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5o'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5o'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%5o'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_33_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05o'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05o'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%05o'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_34_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5o'", 7);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5o'", INT_MAX);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "padding '%-5o'", INT_MIN);
} END_TEST

// %i padding left-justify test
START_TEST(test_35_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "char '%c'", 'A');
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "char '%3c'", 'a');
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "char '%-3c'", 'a');
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "char '%c'", '\34');
} END_TEST

// rest test
START_TEST(test_36_s21_sprintf) {
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "'%%' %s", NULL_STR);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "'%hd'", (short) 123);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "'%*.*f'", 4, 4, 123123.123123);
    compare_sprintf_func(sprintf, str_sprintf, n_sprintf, s21_sprintf, \
                        str_s21_sprintf, n_s21_sprintf, "'%*.*f'", -4, -4, 123123.1231233);
} END_TEST

// </SPRINTF>

Suite * s21_sprintf_suite(void) {
    Suite * suite = suite_create("group of sprintf tests");

    // SPRINTF
    TCase * ts21_sprintf = tcase_create("sprintf_tests");

    tcase_add_test(ts21_sprintf, test_01_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_02_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_03_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_04_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_05_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_06_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_07_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_08_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_09_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_10_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_11_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_12_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_13_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_14_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_15_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_16_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_17_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_18_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_19_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_20_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_21_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_22_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_23_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_24_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_25_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_26_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_27_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_28_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_29_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_30_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_31_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_32_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_33_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_34_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_35_s21_sprintf);
    tcase_add_test(ts21_sprintf, test_36_s21_sprintf);

    suite_add_tcase(suite, ts21_sprintf);

    return suite;
}