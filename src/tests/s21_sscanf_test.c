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
    char str[] = "123.11e-1 -11.5 +0.123 999.12 0.1";
    float a = 0, b = 0, c = -1, d = 0, e = 0;
    int status = s21_sscanf(str, "%f %f %*f %2f %f %f",
                            &a, &b, &c, &d, &e);
    ck_assert_int_eq(status, 5);
    ck_assert_float_eq_tol(a, 12.311, 1e-6);
    ck_assert_float_eq_tol(b, -11.5, 1e-6);
    ck_assert_float_eq_tol(c, 99.0, 1e-6);
    ck_assert_float_eq_tol(d, 9.12, 1e-6);
    ck_assert_float_eq_tol(e, 0.1, 1e-6);

} END_TEST


START_TEST(sscanf_test3_i) {
    char str[] = "123 -11 28384 0112340x01032afe 0x00001bcd";
    int a = 0, b = 0, c = -1, d = 0, e = 0;
    int status = s21_sscanf(str, "%i %i %*i %6i %i %i",
                            &a, &b, &c, &d, &e);
    ck_assert_int_eq(status, 5);
    ck_assert_int_eq(a, 123);
    ck_assert_int_eq(b, -11);
    ck_assert_int_eq(c, 4764);
    ck_assert_int_eq(d, 16984830);
    ck_assert_int_eq(e, 7117);

} END_TEST

START_TEST(sscanf_test3_u) {
    char str[] = "123 -11 28384 11111111 777 228";
    unsigned int a1 = 0, b1 = 0, c1 = -1, d1 = 0, e1 = 0;
    unsigned int a2 = 0, b2 = 0, c2 = -1, d2 = 0, e2 = 0;
    int n1 = 0, n2 = 0; 
    int status1 = sscanf(str, "%u %u %*u %6u %u %n %u",
                            &a1, &b1, &c1, &d1, &n1, &e1);
    int status2 = s21_sscanf(str, "%u %u %*u %6u %u %n %u",
                            &a2, &b2, &c2, &d2, &n2, &e2);
    ck_assert_int_eq(status1, status2);
    ck_assert_int_eq(a1, a2);
    ck_assert_int_eq(b1, b2);
    ck_assert_int_eq(c1, c2);
    ck_assert_int_eq(d1, d2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(e1, e2);

} END_TEST

START_TEST(sscanf_test4_s) {
    char str[] = "Helloworld sss sss aboba";
    char str11[11] = {'\0'};
    char str12[10] = {'\0'};
    char str13[10] = {'\0'};
    char str21[11] = {'\0'};
    char str22[10] = {'\0'};
    char str23[10] = {'\0'};
    int status1 = sscanf(str, "%s %*s %2s %s", str11, str12, str13);
    int status2 = s21_sscanf(str, "%s %*s %2s %s", str21, str22, str23);
    
    ck_assert_int_eq(status1, status2);
    ck_assert_str_eq(str11, str21);
    ck_assert_str_eq(str12, str22);
    ck_assert_str_eq(str13, str23);

} END_TEST

START_TEST(sscanf_test5_c) {
    char str[] = "Helloworld sss sss aboba";
    char str11;
    char str12;
    char str13[10] = {'\0'};
    char str21;
    char str22;
    char str23[10] = {'\0'};
    int status1 = sscanf(str, "%c %*c %2c %c", &str11, str13, &str12);
    int status2 = s21_sscanf(str, "%c %*c %2c %c", &str21, str23, &str22);
    
    ck_assert_int_eq(status1, status2);
    ck_assert_int_eq(str11, str21);
    ck_assert_int_eq(str12, str22);
    ck_assert_str_eq(str13, str23);

} END_TEST

START_TEST(sscanf_test6_f) {
    char str[] = "  \n\t 123.11e-1 \t   -0112 +0123 +7712 0.1";
    float a = 0, e = 0;
    int b = 0, d = 0, c = 0;
    int status = s21_sscanf(str, "%f %o %*f %3o %o %f",
                            &a, &b, &c, &d, &e);
    ck_assert_int_eq(status, 5);
    ck_assert_float_eq_tol(a, 12.311, 1e-6);
    ck_assert_int_eq(b, -74);
    ck_assert_int_eq(c, 63);
    ck_assert_float_eq_tol(d, 10, 1e-6);
    ck_assert_float_eq_tol(e, 0.1, 1e-6);

} END_TEST

START_TEST(sscanf_test7_X) {
    char str[] = "0x01010abc 0x10234e +0x11 11aB";
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0,
        b1 = 0, b2 = 0, b3 = 0, b4 = 0;
    int status1 = sscanf(str, "%x %X %x %x", &a1, &a2, &a3, &a4);
    int status2 = s21_sscanf(str, "%x %X %x %x", &b1, &b2, &b3, &b4);
    // ck_assert_int_eq(status1, status2);
    ck_assert_int_eq(a1, b1);
    ck_assert_int_eq(a4, b4);
    ck_assert_int_eq(a3, b3);
    ck_assert_int_eq(a2, b2);
} END_TEST

START_TEST(sscanf_test8_p) {
    int a = 10;
    int *p1 = &a;
    int *p2 = &a;
    char str[] = "0x001eca01";
    int status1 = sscanf(str, "%p", &p1);
    int status2 = s21_sscanf(str, "%p", &p2);
    ck_assert_int_eq(status1, status2);
    ck_assert_ptr_eq(p1, p2);
} END_TEST

Suite *suite_sscanf() {
    Suite *s = suite_create("suite_sscanf");
    TCase *tc = tcase_create("sscanf_tc");

    tcase_add_test(tc, sscanf_test1_d);
    tcase_add_test(tc, sscanf_test2_f);
    tcase_add_test(tc, sscanf_test3_i);
    tcase_add_test(tc, sscanf_test3_u);
    tcase_add_test(tc, sscanf_test4_s);
    tcase_add_test(tc, sscanf_test5_c);
    tcase_add_test(tc, sscanf_test6_f);
    tcase_add_test(tc, sscanf_test7_X);
    tcase_add_test(tc, sscanf_test8_p);
    suite_add_tcase(s, tc);
    return s;
}
