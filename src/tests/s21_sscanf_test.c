#include "test.h"

START_TEST(sscanf_test1_d) {
    char str[] = "123 -11 0 999.12";
    int a = 0, b = 0, c = -1, d = 0, e = 0;
    int status = s21_sscanf(str, "%d %d %*d %2d %d %d",
                            &a, &b, &c, &d, &e);
    ck_assert_int_eq(status, 4);
    ck_assert_int_eq(a, 123);
    ck_assert_int_eq(b, -11);
    ck_assert_int_eq(c, 99);
    ck_assert_int_eq(d, 9);
    ck_assert_int_eq(e, 0);

} END_TEST


START_TEST(sscanf_test2_f) {
    char str[] = "123.11 -11.5 0.123 999.12 0.1";
    float a = 0, b = 0, c = -1, d = 0, e = 0;
    int status = s21_sscanf(str, "%f %f %*f %2f %f %f",
                            &a, &b, &c, &d, &e);
    ck_assert_int_eq(status, 5);
    ck_assert_int_eq(a, 123.11);
    ck_assert_int_eq(b, -11.5);
    ck_assert_int_eq(c, 99.0);
    ck_assert_int_eq(d, 9.12);
    ck_assert_int_eq(e, 0.1);

} END_TEST


START_TEST(sscanf_test3_i) {
    char str[] = "123 -11 28384 0112340x01032afe 555";
    int a = 0, b = 0, c = -1, d = 0, e = 0;
    int status = s21_sscanf(str, "%i %i %*i %6i %i %i",
                            &a, &b, &c, &d, &e);
    printf("status = %d\n", status);
    ck_assert_int_eq(status, 5);
    ck_assert_int_eq(a, 123);
    ck_assert_int_eq(b, -11);
    ck_assert_int_eq(c, 4764);
    ck_assert_int_eq(d, 16984830);
    ck_assert_int_eq(e, 555);

} END_TEST

Suite *suite_sscanf() {
    Suite *s = suite_create("suite_sscanf");
    TCase *tc = tcase_create("sscanf_tc");

    tcase_add_test(tc, sscanf_test1_d);
    tcase_add_test(tc, sscanf_test2_f);
    tcase_add_test(tc, sscanf_test3_i);

    suite_add_tcase(s, tc);
    return s;
}
