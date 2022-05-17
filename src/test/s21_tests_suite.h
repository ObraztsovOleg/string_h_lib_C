#ifndef SRC_S21_TESTS_SUITE_H_
#define SRC_S21_TESTS_SUITE_H_

#include <check.h>
#include "../s21_string.h"
#include <string.h>
#include <stdio.h>
#include <float.h>

Suite * s21_sprintf_suite(void);
Suite * s21_strlen_suite(void);
Suite * s21_strcat_suite(void);
Suite * s21_strcpy_suite(void);
Suite * s21_strncpy_suite(void);
Suite * s21_strncat_suite(void);
Suite * s21_strchr_suite(void);
Suite * s21_strcspn_suite(void);
Suite * s21_memchr_suite(void);
Suite * s21_memcmp_suite(void);
Suite * s21_memcpy_suite(void);
Suite * s21_memmove_suite(void);
Suite * s21_memset_suite(void);
Suite * s21_strpbrk_suite(void);
Suite * s21_strcmp_suite(void);
Suite * s21_strerror_suite(void);
Suite * s21_strncmp_suite(void);
Suite * s21_strrchr_suite(void);
Suite * s21_strsnp_suite(void);
Suite * s21_strstr_suite(void);
Suite * s21_strtok_suite(void);
Suite * s21_trim_suite(void);
Suite * s21_insert_suite(void);
Suite * s21_to_upper_suite(void);
Suite * s21_to_lower_suite(void);

#define SUITE_FUNCS (Suite*(*[])(void)){s21_sprintf_suite, \
                                        s21_strlen_suite,  \
                                        s21_strcat_suite,  \
                                        s21_strcpy_suite,  \
                                        s21_strchr_suite,  \
                                        s21_strncat_suite, \
                                        s21_strncpy_suite, \
                                        s21_strcspn_suite, \
                                        s21_memchr_suite,  \
                                        s21_memcmp_suite,  \
                                        s21_memcpy_suite,  \
                                        s21_memmove_suite, \
                                        s21_memset_suite,  \
                                        s21_strpbrk_suite,  \
                                        s21_strcmp_suite,  \
                                        s21_strerror_suite, \
                                        s21_strncmp_suite, \
                                        s21_strrchr_suite, \
                                        s21_strsnp_suite,  \
                                        s21_strstr_suite,  \
                                        s21_strtok_suite,  \
                                        s21_to_upper_suite, \
                                        s21_to_lower_suite, \
                                        s21_insert_suite,  \
                                        s21_trim_suite}

#define ARRAY_SUITE_LEN 25


#endif  // SRC_S21_TESTS_SUITE_H_
