#include "./test/s21_tests_suite.h"

int run_tests(SRunner * runner, Suite * suite, Suite * (*suite_tests)(void)) {
    int no_failed = 0;

    suite = suite_tests();
    runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);

    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return no_failed;
}

int main(void) {
    int no_failed = 0;

    Suite * suite = NULL;
    SRunner * runner = NULL;

    for (int i = 0; i < ARRAY_SUITE_LEN; i++) {
        if (run_tests(runner, suite, SUITE_FUNCS[i])) {
            no_failed = 1;
        }
    }

    return (no_failed == 0) ? 0 : 1;
}
