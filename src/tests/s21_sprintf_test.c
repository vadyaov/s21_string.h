#include "test.h"

START_TEST(s21_sprintf_test1_d) {  // int n = 777;
    int n = 777;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%d", n);
    int b = sprintf(str2, "%d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test2_d) {  // int n = 000;
    int n = 000;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%d", n);
    int b = sprintf(str2, "%d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test3_d) {  // int n = -123
    int n = -123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%d", n);
    int b = sprintf(str2, "%d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test4_d) {  // int n = 0, " %d"
    int n = 0;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %d", n);
    int b = sprintf(str2, " %d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test5_d) {  // int n = -0, " %d"
    int n = -0;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %d", n);
    int b = sprintf(str2, " %d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test6_d) {  // int n = 123, " %+d"
    int n = 123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %+d", n);
    int b = sprintf(str2, " %+d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test7_d) {  // int n = 123, "%+d"
    int n = 123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%+d", n);
    int b = sprintf(str2, "%+d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test8_d) {  // int n = 123, "-d%"
    int n = 123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%-d", n);
    int b = sprintf(str2, "%-d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test9_d) {  // int n = 123, " %-d"
    int n = 123;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %-d", n);
    int b = sprintf(str2, " %-d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test10_d) {  // int n = 123, " %-10d"
    int n = 123;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%-10d", n);
    int b = sprintf(str2, "%-10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test11_d) {  // int n = 100, "%10d"
    int n = 100;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%10d", n);
    int b = sprintf(str2, "%10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test12_d) {  // int n = 100, "%+10d"
    int n = 100;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%+10d", n);
    int b = sprintf(str2, "%+10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test13_d) {  // int n = 100, " %+10d"
    int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%d", n);
    int b = sprintf(str2, "%d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test14_d) {  // int n = 100, ".20d"
    int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.20d", n);
    int b = sprintf(str2, "%.20d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test15_d) {  // int n = 100, "%+.20d"
    int n = -100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%++++++++++++++++.20d", n);
    int b = sprintf(str2, "%+.20d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test16_d) {  // int n = 100, "%+-.20d"
    int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%+----.20d", n);
    int b = sprintf(str2, "%+-.20d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test17_d) {  // int n = -0, "%+.10d"
    int n = -0;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%+.10d", n);
    int b = sprintf(str2, "%+.10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test18_d) {  // int n = -9990, "%10d"
    int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%10d", n);
    int b = sprintf(str2, "%10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test19_d) {  // int n = -9990, "+-.%10d"
    int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% +-.10d", n);
    int b = sprintf(str2, "%+-.10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test20_d) {  // int n = -9990, "% -10d"
    int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% -10d", n);
    int b = sprintf(str2, "% -10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test21_d) {  // int n = 9990, "% 10d"
    int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% 10d", n);
    int b = sprintf(str2, "% 10d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test22_d) {  // int n = -9990, "% 10d"
    int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% 2d", n);
    int b = sprintf(str2, "% 2d", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test23_d) {  // int n = 9990, "%-.09d"
    int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-.09d..", n);
    int b = sprintf(str2, "%-.09d..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test24_d) {  // int n = 9990, "%-.09d"
    int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.d..", n);
    int b = sprintf(str2, "%.d..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test25_d) {  // int n = 9990, "%-+.10ld.."
    long int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10ld..", n);
    int b = sprintf(str2, "%-+.10ld..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test26_d) {  // int n = -9990, "%-+.10hd.."
    short int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10hd..", n);
    int b = sprintf(str2, "%-+.10hd..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

// Тесты %s
START_TEST(s21_sprintf_test1_s) {  // "%s%c","BIBA_BOBA", 'q'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%s%c", "BIBA_BOBA", 'q');
    int b = sprintf(str2, "%s%c", "BIBA_BOBA", 'q');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test2_s) {  //  %s%c","BIBA_BOBA", 'q'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %s%c", "BIBA_BOBA", 'q');
    int b = sprintf(str2, " %s%c", "BIBA_BOBA", 'q');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test3_s) {  // " %s%c"," ", ' '
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %s%c", " ", ' ');
    int b = sprintf(str2, " %s%c", " ", ' ');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test4_s) {  // " %10s%10c"," ",'q'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %10s%-10lc", " ", 'q');
    int b = sprintf(str2, " %10s%-10lc", " ", 'q');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test5_s) {  // " %10s", "GO TO B   "
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %10s", "GO TO B   ");
    int b = sprintf(str2, " %10s", "GO TO B   ");

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test6_s) {  // " %10s","GO TO B  W ")
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %10s", "GO TO B  W ");
    int b = sprintf(str2, " %10s", "GO TO B  W ");

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test7_s) {  // "GO TO SHORT  ", 'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-10s%1c", "GO TO SHORT  ", 'W');
    int b = sprintf(str2, " %-10s%1c", "GO TO SHORT  ", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST


START_TEST(s21_sprintf_test8_s) {  // " %-10s%-1c","GO TO SHORT  ",'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-10s%-1c", "GO TO SHORT  ", 'W');
    int b = sprintf(str2, " %-10s%-1c", "GO TO SHORT  ", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test9_s) {  // " %-10s%-10c","GO TO SHORT  ",'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-10s%-10c", "GO TO SHORT  ", 'W');
    int b = sprintf(str2, " %-10s%-10c", "GO TO SHORT  ", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test10_s) {  // " %-s1%9c", "GO TO SHORT", 'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-s1%9c", "GO TO SHORT", 'W');
    int b = sprintf(str2, " %-s1%9c", "GO TO SHORT", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test11_s) {  // " %-.1s%9c", "GO TO S H O R T", 'W'
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-.1s%1c", "GO TO S H O R T", 'W');
    int b = sprintf(str2, " %-.1s%1c", "GO TO S H O R T", 'W');

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test12_s) {  // " %-.1s%1c%.1d%.1lu%.1hu.....wqwq", "GO TO S H O R T", 'W', i, l, us);
    short int i = 10;
    unsigned long l = 100;
    unsigned short us = 20;
    long int li = 100;
    short int si = 20;

    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);
    int b = sprintf(str2, " %-.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq", L"GO TO S H O R T", 'W', i, l, us, li, si);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test13_s) {  // " %-.1s%1c%.1d%.1lu%.1hu.....wqwq", "GO TO S H O R T", 'W', i, l, us);
    short int i = 10;
    unsigned long l = 100;
    unsigned short us = 20;
    long int li = 100;
    short int si = 20;

    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %%%-.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);
    int b = sprintf(str2, " %%%-.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test14_s) {  // " %-.1s%1c%.1d%.1lu%.1hu.....wqwq", "GO TO S H O R T", 'W', i, l, us);
    short int i = 10;
    unsigned long l = 100;
    unsigned short us = 20;

    long int li = 100;
    short int si = 20;

    char str1[120];
    char str2[120];

    int a = s21_sprintf(str1, " %%%-50ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);
    int b = sprintf(str2, " %%%-50ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test15_s) {  // " %-.1s%1c%.1d%.1lu%.1hu.....wqwq", "GO TO S H O R T", 'W', i, l, us);
    short int i = 10;
    unsigned long l = 100;
    unsigned short us = 20;
    long int li = 100;
    short int si = 20;

    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %%%15.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);
    int b = sprintf(str2, " %%%15.10ls%1lc%.1d%.1lu%.1hu%ld%hd.wqwq",
                        L"GO TO S H O R T", 'W', i, l, us, li, si);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

// Тесты %u
START_TEST(s21_sprintf_test1_u) {  // unsigned int n = 7777777; "%u"
    unsigned int n = 7777777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%u", n);
    int b = sprintf(str2, "%u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test2_u) {  // unsigned int n = 000000; "%u"
    unsigned int n = 000000;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%u", n);
    int b = sprintf(str2, "%u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test3_u) {  // unsigned int n = -100; "%u"
    unsigned int n = -100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%u", n);
    int b = sprintf(str2, "%u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test4_u) {  // unsigned int n = 0, " %u"
    unsigned int n = 0;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, " %u", n);
    int b = sprintf(str2, " %u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test5_u) {  // unsigned int n = 7777777, " %u"
    unsigned int n = 7777777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %u", n);
    int b = sprintf(str2, " %u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test6_u) {  // unsigned int n = 123, " %-u"
    unsigned int n = 777777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-u", n);
    int b = sprintf(str2, " %-u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test7_u) {  // unsigned int n = -0, " %-u"
    unsigned int  n = -0;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %-u", n);
    int b = sprintf(str2, " %-u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test8_u) {  // unsigned int n = 12322; "%-10u"
    unsigned int n = 12322;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%-10u", n);
    int b = sprintf(str2, "%-10u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test9_u) {  // unsigned int n = 10023;, " %-10u"
    unsigned int n = 10023;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%-10u", n);
    int b = sprintf(str2, "%-10u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test10_u) {  // unsigned int n = 100, "%10u"
    unsigned int n = 10000;
    char str1[60];
    char str2[60];

    int a = s21_sprintf(str1, "%10u", n);
    int b = sprintf(str2, "%10u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test11_u) {  // unsigned int n = 100;, "%.20u"
    unsigned int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.20u", n);
    int b = sprintf(str2, "%.20u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test12_u) {  // unsigned int n = 102220;, "%-.20d"
    unsigned int n = 102220;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-.20u", n);
    int b = sprintf(str2, "%-.20u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test13_u) {  // unsigned int n = 100; "%.20u"
    unsigned int n = 100;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.20u", n);
    int b = sprintf(str2, "%.20u", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test14_u) {  // unsigned int n = 9990;  "%.u.."
    unsigned int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.u..", n);
    int b = sprintf(str2, "%.u..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test15_u) {  // unsigned int n = 00001;  "%.01uVADIM   PAPA""
    unsigned int n = 00001;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%.01uVADIM   PAPA", n);
    int b = sprintf(str2, "%.01uVADIM   PAPA", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test16_u) {  // unsigned int n = 00001;  "%.0uVADIM   PAPA""
    unsigned int n = 00001;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %.0uVADIM   PAPA", n);
    int b = sprintf(str2, " %.0uVADIM   PAPA", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test17_u) {  // unsigned int n = 00001;  "%%%.01uVADIM   PAPA"
    unsigned int n = 00001;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%%%.01uVADIM   PAPA", n);
    int b = sprintf(str2, "%%%.01uVADIM   PAPA", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test18_u) {  // int n = 9990, "%-+.10ld.."
    unsigned long int n = 9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-.01lu.!.", n);
    int b = sprintf(str2, "%-.01lu.!.", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test19_u) {  // int n = 9990, "%-+.10ld.."
    unsigned short int n = -9990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-.0hui.!.", n);
    int b = sprintf(str2, "%-.0hui.!.", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

// Тесты  %f
START_TEST(s21_sprintf_test1_f) {  // float n = 777;  "%f"
    double n = 777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test2_f) {  // float n = 000; "%f"
    double n = 000;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test3_f) {  // float n = -777; "%f"
    double n = -777;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test4_f) {  // float n = -0000; "%f"
    double n = -0000;
    char str1[10];
    char str2[10];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test5_f) {  // float n = -0000; "%+-f"
    double n = -0000;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%+-f", n);
    int b = sprintf(str2, "%+-f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test6_f) {  // float n = -022200; " % f"
    double n = -022200;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, " %f", n);
    int b = sprintf(str2, " %f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test7_f) {  // float n = -022200; "100--/0\n%.2f"
    double n = -022200;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "100--/0\n%.2f", n);
    int b = sprintf(str2, "100--/0\n%.2f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test8_f) {  // float n = 02.212200; "%-+.10lf.."
    double n = 02.212200;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10lf..", n);
    int b = sprintf(str2, "%-+.10lf..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test9_f) {  // float n = 02.212200;, "%-+.10lf.."
    double n = 02.212200;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10lf..", n);
    int b = sprintf(str2, "%-+.10lf..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test10_f) {  // float n = -99.290, "% -10f"
    double n = -99.290;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% -10f", n);
    int b = sprintf(str2, "% -10f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test11_f) {  // float n = -99.290, "% -10f"
    double n = 99.290;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "% -10f", n);
    int b = sprintf(str2, "% -10f", n);

    ck_assert_int_eq(a, b);
    ck_assert_pstr_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test12_f) {  // int n = -9990, "%-+.10hd.."
    double n = -9.1990;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+.10f..", n);
    int b = sprintf(str2, "%-+.10f..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test13_f) {  // int n = -9990, "%-+.10hd.."
    double n = -9.199000000000214324;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%-+20.11f..", n);
    int b = sprintf(str2, "%-+20.11f..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test14_f) {  // int n = -9990, "%-+.10hd.."
    double n = -9.199000000000216;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%20.14f..", n);
    int b = sprintf(str2, "%20.14f..", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(s21_sprintf_test15_f) {  // int n = -9990, "%-+.10hd.."
    double n = -0.0;
    char str1[100];
    char str2[100];

    int a = s21_sprintf(str1, "%f", n);
    int b = sprintf(str2, "%f", n);

    ck_assert_int_eq(a, b);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(simple_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "This is a simple value %d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%5d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5i";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+12d";
    int val = 69;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char format[] = "%0.i %d %4.i %13d %d";
    int val = 69;
    ck_assert_int_eq(
        s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
        sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%+5.31li";
    long int val = 698518581899;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-16.9hi";
    short int val = 6958;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.0d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% d";
    int val = 0;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-16u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% 5.51u";
    unsigned int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%hu";
    unsigned short int val = 14140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%lu, %u, %hu, %.5u, %5.u";
    unsigned long int val = 949149114140;
    ck_assert_int_eq(s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
                     sprintf(str2, format, val, (unsigned)14,
                             (unsigned short)1441, (unsigned)14414,
                             (unsigned)9681));

    ck_assert_str_eq(str1, str2);
}
END_TEST


START_TEST(one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%c";
    char val = 'X';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "% -5c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                     sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-5.3c";
    char val = 'c';
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%.15s";
    char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%15s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%-15.9s";
    char *val = "69 IS MY FAVORITE NUMBER";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    char *format = "%s%s%s%s";
    char *val =
        "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
    char *s1 = "";
    char *s2 = "87418347813748913749871389480913";
    char *s3 = "HAHAABOBASUCKER";
    ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                     sprintf(str2, format, val, s1, s2, s3));

    ck_assert_str_eq(str1, str2);
}

START_TEST(string_width_huge) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char *val = "kjafdiuhfjahfjdahf";
    char *format = "%120s";
    ck_assert_int_eq(s21_sprintf(str1, format, val),
                     sprintf(str2, format, val));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                     sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                     sprintf(str2, "%s", "Drop Sega PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
        sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                     sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                     sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                     sprintf(str2, "%f", 0.0001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
        sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                     sprintf(str2, "%u", (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                     sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                             (unsigned)666, (unsigned)100));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'),
                     sprintf(str2, "%8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                     sprintf(str2, "%-8c", '\t'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];

    ck_assert_int_eq(
        s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
        sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%10ld";

    ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%1.1f";

    ck_assert_int_eq(s21_sprintf(str1, format, 1.1),
                     sprintf(str2, format, 1.1));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%8.3c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
                     sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+5.5d aboba";

    int val = 10000;
    int a = s21_sprintf(str1, format, val);
    int b = sprintf(str2, format, val);
    ck_assert_int_eq(a, b);

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf6) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%7.7f";

    ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                     sprintf(str2, format, 11.123456));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%7.4s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                     sprintf(str2, format, "aboba floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%6.6u";

    ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                     sprintf(str2, format, 12341151));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf9) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%li%ld%lu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                     sprintf(str2, format, 666666666666, 777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf10) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%hi%hd%hu";

    ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                     sprintf(str2, format, 666, -777, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf11) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+li%+lu%+d%+lf";

    ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                     sprintf(str2, format, -123, 321, -5555, -1213.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf12) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-11.11li%-35.5lu%-3.5ld%33.15f";
    double k = 333.33213;

    ck_assert_int_eq(
        s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
        sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf14) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
        sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf15) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
        sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf16) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% c";

    ck_assert_int_eq(s21_sprintf(str1, format, 'a'),
                     sprintf(str2, format, 'a'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf17) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% s";

    ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                     sprintf(str2, format, "aboba likes floppa"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf18) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "% s% c";

    ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                     sprintf(str2, format, "", 'f'));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf19) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%210s";

    ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                     sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf20) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-115s";

    ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                     sprintf(str2, format, "Nick her"));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf24) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

    ck_assert_int_eq(
        s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                    "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
        sprintf(str2, format, 'f', 21, 42, 666.666,
                "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf25) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%.f";

    ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                     sprintf(str2, format, 121.123));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf26) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%%";

    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf27) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%%%%%%%%";

    ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf29) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.f";

    ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                     sprintf(str2, format, 111.111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf30) {
    char str1[BUFF_SIZE];
    char str2[BUFF_SIZE];
    char format[] = "%-.1d";

    ck_assert_int_eq(s21_sprintf(str1, format, 111),
                     sprintf(str2, format, 111));

    ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *suite_sprintf() {
    Suite *s = suite_create("suite_sprintf");
    TCase *tc = tcase_create("sprintf_tc");
    tcase_add_test(tc, simple_int);
    tcase_add_test(tc, precise_int);
    tcase_add_test(tc, width_int);
    tcase_add_test(tc, minus_width_int);
    tcase_add_test(tc, plus_width_int);
    tcase_add_test(tc, many_flags_many_ints);
    tcase_add_test(tc, flags_long_int);
    tcase_add_test(tc, flags_short_int);
    tcase_add_test(tc, zero_precision_zero_int);
    tcase_add_test(tc, space_flag_int);
    tcase_add_test(tc, unsigned_val);
    tcase_add_test(tc, unsigned_val_width);
    tcase_add_test(tc, unsigned_val_flags);
    tcase_add_test(tc, unsigned_val_precision);
    tcase_add_test(tc, unsigned_val_many_flags);
    tcase_add_test(tc, unsigned_val_short);
    tcase_add_test(tc, unsigned_val_long);
    tcase_add_test(tc, unsigned_val_many);
    tcase_add_test(tc, one_char);
    tcase_add_test(tc, one_precision);
    tcase_add_test(tc, one_flags);
    tcase_add_test(tc, one_width);
    tcase_add_test(tc, one_many);
    tcase_add_test(tc, one_many_flags);
    tcase_add_test(tc, string);
    tcase_add_test(tc, string_precision);
    tcase_add_test(tc, string_width);
    tcase_add_test(tc, string_flags);
    tcase_add_test(tc, string_long);
    tcase_add_test(tc, string_many);
    tcase_add_test(tc, string_width_huge);
    tcase_add_test(tc, all_empty);
    tcase_add_test(tc, empty_format_and_parameters);
    tcase_add_test(tc, test_one_char);
    tcase_add_test(tc, test_many_char);
    tcase_add_test(tc, test_one_string);
    tcase_add_test(tc, test_many_string);
    tcase_add_test(tc, test_one_dec);
    tcase_add_test(tc, test_many_dec);
    tcase_add_test(tc, test_one_int);
    tcase_add_test(tc, test_many_int);
    tcase_add_test(tc, test_one_float);
    tcase_add_test(tc, test_many_float);
    tcase_add_test(tc, test_one_unsigned_dec);
    tcase_add_test(tc, test_many_unsigned_dec);
    tcase_add_test(tc, test_one_char_with_alignment_left);
    tcase_add_test(tc, test_one_char_with_alignment_right);
    tcase_add_test(tc, test_many_char_with_alignment);
    tcase_add_test(tc, test_sprintf1);
    tcase_add_test(tc, test_sprintf2);
    tcase_add_test(tc, test_sprintf3);
    tcase_add_test(tc, test_sprintf4);
    tcase_add_test(tc, test_sprintf6);
    tcase_add_test(tc, test_sprintf7);
    tcase_add_test(tc, test_sprintf8);
    tcase_add_test(tc, test_sprintf9);
    tcase_add_test(tc, test_sprintf10);
    tcase_add_test(tc, test_sprintf11);
    tcase_add_test(tc, test_sprintf12);
    tcase_add_test(tc, test_sprintf14);
    tcase_add_test(tc, test_sprintf15);
    tcase_add_test(tc, test_sprintf16);
    tcase_add_test(tc, test_sprintf17);
    tcase_add_test(tc, test_sprintf18);
    tcase_add_test(tc, test_sprintf19);
    tcase_add_test(tc, test_sprintf20);
    tcase_add_test(tc, test_sprintf24);
    tcase_add_test(tc, test_sprintf25);
    tcase_add_test(tc, test_sprintf29);
    tcase_add_test(tc, test_sprintf30);
    tcase_add_test(tc, test_sprintf26);
    tcase_add_test(tc, test_sprintf27);
    suite_add_tcase(s, tc);
    return s;
}


Suite *s21_Suite_sprintf() {
    Suite *s;

    s = suite_create("Sprintf Unit Test");

    TCase *tc1_s21_sprintf_test1_f = tcase_create("test1_s21_strsprintf_f");
    TCase *tc2_s21_sprintf_test2_f = tcase_create("test2_s21_strsprintf_f");
    TCase *tc3_s21_sprintf_test3_f = tcase_create("test3_s21_strsprintf_f");
    TCase *tc4_s21_sprintf_test4_f = tcase_create("test4_s21_strsprintf_f");
    TCase *tc5_s21_sprintf_test5_f = tcase_create("test5_s21_strsprintf_f");
    TCase *tc6_s21_sprintf_test6_f = tcase_create("test6_s21_strsprintf_f");
    TCase *tc7_s21_sprintf_test7_f = tcase_create("test7_s21_strsprintf_f");
    TCase *tc8_s21_sprintf_test8_f = tcase_create("test8_s21_strsprintf_f");
    TCase *tc9_s21_sprintf_test9_f = tcase_create("test9_s21_strsprintf_f");
    TCase *tc10_s21_sprintf_test10_f = tcase_create("test10_s21_strsprintf_f");
    TCase *tc11_s21_sprintf_test11_f = tcase_create("test11_s21_strsprintf_f");
    TCase *tc12_s21_sprintf_test12_f = tcase_create("test12_s21_strsprintf_f");
    TCase *tc13_s21_sprintf_test13_f = tcase_create("test13_s21_strsprintf_f");
    TCase *tc14_s21_sprintf_test14_f = tcase_create("test14_s21_strsprintf_f");
    TCase *tc15_s21_sprintf_test15_f = tcase_create("test15_s21_strsprintf_f");

    tcase_add_test(tc1_s21_sprintf_test1_f, s21_sprintf_test1_f);
    tcase_add_test(tc2_s21_sprintf_test2_f, s21_sprintf_test2_f);
    tcase_add_test(tc3_s21_sprintf_test3_f, s21_sprintf_test3_f);
    tcase_add_test(tc4_s21_sprintf_test4_f, s21_sprintf_test4_f);
    tcase_add_test(tc5_s21_sprintf_test5_f, s21_sprintf_test5_f);
    tcase_add_test(tc6_s21_sprintf_test6_f, s21_sprintf_test6_f);
    tcase_add_test(tc7_s21_sprintf_test7_f, s21_sprintf_test7_f);
    tcase_add_test(tc8_s21_sprintf_test8_f, s21_sprintf_test8_f);
    tcase_add_test(tc9_s21_sprintf_test9_f, s21_sprintf_test9_f);
    tcase_add_test(tc10_s21_sprintf_test10_f, s21_sprintf_test10_f);
    tcase_add_test(tc11_s21_sprintf_test11_f, s21_sprintf_test11_f);
    tcase_add_test(tc12_s21_sprintf_test12_f, s21_sprintf_test12_f);
    tcase_add_test(tc13_s21_sprintf_test13_f, s21_sprintf_test13_f);
    tcase_add_test(tc14_s21_sprintf_test14_f, s21_sprintf_test14_f);
    tcase_add_test(tc15_s21_sprintf_test15_f, s21_sprintf_test15_f);

    suite_add_tcase(s, tc1_s21_sprintf_test1_f);
    suite_add_tcase(s, tc2_s21_sprintf_test2_f);
    suite_add_tcase(s, tc3_s21_sprintf_test3_f);
    suite_add_tcase(s, tc4_s21_sprintf_test4_f);
    suite_add_tcase(s, tc5_s21_sprintf_test5_f);
    suite_add_tcase(s, tc6_s21_sprintf_test6_f);
    suite_add_tcase(s, tc7_s21_sprintf_test7_f);
    suite_add_tcase(s, tc8_s21_sprintf_test8_f);
    suite_add_tcase(s, tc9_s21_sprintf_test9_f);
    suite_add_tcase(s, tc10_s21_sprintf_test10_f);
    suite_add_tcase(s, tc11_s21_sprintf_test11_f);
    suite_add_tcase(s, tc12_s21_sprintf_test12_f);
    suite_add_tcase(s, tc13_s21_sprintf_test13_f);
    suite_add_tcase(s, tc14_s21_sprintf_test14_f);
    suite_add_tcase(s, tc15_s21_sprintf_test15_f);

    TCase *tc1_s21_sprintf_test1_d = tcase_create("test1_s21_strsprintf");
    TCase *tc2_s21_sprintf_test2_d = tcase_create("test2_s21_strsprintf");
    TCase *tc3_s21_sprintf_test3_d = tcase_create("test3_s21_strsprintf");
    TCase *tc4_s21_sprintf_test4_d = tcase_create("test4_s21_strsprintf");
    TCase *tc5_s21_sprintf_test5_d = tcase_create("test5_s21_strsprintf");
    TCase *tc6_s21_sprintf_test6_d = tcase_create("test6_s21_strsprintf");
    TCase *tc7_s21_sprintf_test7_d = tcase_create("test7_s21_strsprintf");
    TCase *tc8_s21_sprintf_test8_d = tcase_create("test8_s21_strsprintf");
    TCase *tc9_s21_sprintf_test9_d = tcase_create("test9_s21_strsprintf");
    TCase *tc10_s21_sprintf_test10_d = tcase_create("test10_s21_strsprintf");
    TCase *tc11_s21_sprintf_test11_d = tcase_create("test11_s21_strsprintf");
    TCase *tc12_s21_sprintf_test12_d = tcase_create("test12_s21_strsprintf");
    TCase *tc13_s21_sprintf_test13_d = tcase_create("test13_s21_strsprintf");
    TCase *tc14_s21_sprintf_test14_d = tcase_create("test14_s21_strsprintf");
    TCase *tc15_s21_sprintf_test15_d = tcase_create("test15_s21_strsprintf");
    TCase *tc16_s21_sprintf_test16_d = tcase_create("test16_s21_strsprintf");
    TCase *tc17_s21_sprintf_test17_d = tcase_create("test17_s21_strsprintf");
    TCase *tc18_s21_sprintf_test18_d = tcase_create("test18_s21_strsprintf");
    TCase *tc19_s21_sprintf_test19_d = tcase_create("test19_s21_strsprintf");
    TCase *tc20_s21_sprintf_test20_d = tcase_create("test20_s21_strsprintf");
    TCase *tc21_s21_sprintf_test21_d = tcase_create("test21_s21_strsprintf");
    TCase *tc22_s21_sprintf_test22_d = tcase_create("test22_s21_strsprintf");
    TCase *tc23_s21_sprintf_test23_d = tcase_create("test23_s21_strsprintf");
    TCase *tc24_s21_sprintf_test24_d = tcase_create("test24_s21_strsprintf");
    TCase *tc25_s21_sprintf_test25_d = tcase_create("test25_s21_strsprintf");
    TCase *tc26_s21_sprintf_test26_d = tcase_create("test26_s21_strsprintf");

    tcase_add_test(tc1_s21_sprintf_test1_d, s21_sprintf_test1_d);
    tcase_add_test(tc2_s21_sprintf_test2_d, s21_sprintf_test2_d);
    tcase_add_test(tc3_s21_sprintf_test3_d, s21_sprintf_test3_d);
    tcase_add_test(tc4_s21_sprintf_test4_d, s21_sprintf_test4_d);
    tcase_add_test(tc5_s21_sprintf_test5_d, s21_sprintf_test5_d);
    tcase_add_test(tc6_s21_sprintf_test6_d, s21_sprintf_test6_d);
    tcase_add_test(tc7_s21_sprintf_test7_d, s21_sprintf_test7_d);
    tcase_add_test(tc8_s21_sprintf_test8_d, s21_sprintf_test8_d);
    tcase_add_test(tc9_s21_sprintf_test9_d, s21_sprintf_test9_d);
    tcase_add_test(tc10_s21_sprintf_test10_d, s21_sprintf_test10_d);
    tcase_add_test(tc11_s21_sprintf_test11_d, s21_sprintf_test11_d);
    tcase_add_test(tc12_s21_sprintf_test12_d, s21_sprintf_test12_d);
    tcase_add_test(tc13_s21_sprintf_test13_d, s21_sprintf_test13_d);
    tcase_add_test(tc14_s21_sprintf_test14_d, s21_sprintf_test14_d);
    tcase_add_test(tc15_s21_sprintf_test15_d, s21_sprintf_test15_d);
    tcase_add_test(tc16_s21_sprintf_test16_d, s21_sprintf_test16_d);
    tcase_add_test(tc17_s21_sprintf_test17_d, s21_sprintf_test17_d);
    tcase_add_test(tc18_s21_sprintf_test18_d, s21_sprintf_test18_d);
    tcase_add_test(tc19_s21_sprintf_test19_d, s21_sprintf_test19_d);
    tcase_add_test(tc20_s21_sprintf_test20_d, s21_sprintf_test20_d);
    tcase_add_test(tc21_s21_sprintf_test21_d, s21_sprintf_test21_d);
    tcase_add_test(tc22_s21_sprintf_test22_d, s21_sprintf_test22_d);
    tcase_add_test(tc23_s21_sprintf_test23_d, s21_sprintf_test23_d);
    tcase_add_test(tc24_s21_sprintf_test24_d, s21_sprintf_test24_d);
    tcase_add_test(tc25_s21_sprintf_test25_d, s21_sprintf_test25_d);
    tcase_add_test(tc26_s21_sprintf_test26_d, s21_sprintf_test26_d);

    suite_add_tcase(s, tc1_s21_sprintf_test1_d);
    suite_add_tcase(s, tc2_s21_sprintf_test2_d);
    suite_add_tcase(s, tc3_s21_sprintf_test3_d);
    suite_add_tcase(s, tc4_s21_sprintf_test4_d);
    suite_add_tcase(s, tc5_s21_sprintf_test5_d);
    suite_add_tcase(s, tc6_s21_sprintf_test6_d);
    suite_add_tcase(s, tc7_s21_sprintf_test7_d);
    suite_add_tcase(s, tc8_s21_sprintf_test8_d);
    suite_add_tcase(s, tc9_s21_sprintf_test9_d);
    suite_add_tcase(s, tc10_s21_sprintf_test10_d);
    suite_add_tcase(s, tc11_s21_sprintf_test11_d);
    suite_add_tcase(s, tc12_s21_sprintf_test12_d);
    suite_add_tcase(s, tc13_s21_sprintf_test13_d);
    suite_add_tcase(s, tc14_s21_sprintf_test14_d);
    suite_add_tcase(s, tc15_s21_sprintf_test15_d);
    suite_add_tcase(s, tc16_s21_sprintf_test16_d);
    suite_add_tcase(s, tc17_s21_sprintf_test17_d);
    suite_add_tcase(s, tc18_s21_sprintf_test18_d);
    suite_add_tcase(s, tc19_s21_sprintf_test19_d);
    suite_add_tcase(s, tc20_s21_sprintf_test20_d);
    suite_add_tcase(s, tc21_s21_sprintf_test21_d);
    suite_add_tcase(s, tc22_s21_sprintf_test22_d);
    suite_add_tcase(s, tc23_s21_sprintf_test23_d);
    suite_add_tcase(s, tc24_s21_sprintf_test24_d);
    suite_add_tcase(s, tc25_s21_sprintf_test25_d);
    suite_add_tcase(s, tc26_s21_sprintf_test26_d);

    TCase *tc1_s21_sprintf_test1_s = tcase_create("test1_s21_strsprintf_s");
    TCase *tc2_s21_sprintf_test2_s = tcase_create("test2_s21_strsprintf_s");
    TCase *tc3_s21_sprintf_test3_s = tcase_create("test3_s21_strsprintf_s");
    TCase *tc4_s21_sprintf_test4_s = tcase_create("test4_s21_strsprintf_s");
    TCase *tc5_s21_sprintf_test5_s = tcase_create("test5_s21_strsprintf_s");
    TCase *tc6_s21_sprintf_test6_s = tcase_create("test6_s21_strsprintf_s");
    TCase *tc7_s21_sprintf_test7_s = tcase_create("test7_s21_strsprintf_s");
    TCase *tc8_s21_sprintf_test8_s = tcase_create("test8_s21_strsprintf_s");
    TCase *tc9_s21_sprintf_test9_s = tcase_create("test9_s21_strsprintf_s");
    TCase *tc10_s21_sprintf_test10_s = tcase_create("test10_s21_strsprintf_s");
    TCase *tc11_s21_sprintf_test11_s = tcase_create("test11_s21_strsprintf_s");
    TCase *tc12_s21_sprintf_test12_s = tcase_create("test12_s21_strsprintf_s");
    TCase *tc13_s21_sprintf_test13_s = tcase_create("test13_s21_strsprintf_s");
    TCase *tc14_s21_sprintf_test14_s = tcase_create("test14_s21_strsprintf_s");
    TCase *tc15_s21_sprintf_test15_s = tcase_create("test15_s21_strsprintf_s");

    tcase_add_test(tc1_s21_sprintf_test1_s, s21_sprintf_test1_s);
    tcase_add_test(tc2_s21_sprintf_test2_s, s21_sprintf_test2_s);
    tcase_add_test(tc3_s21_sprintf_test3_s, s21_sprintf_test3_s);
    tcase_add_test(tc4_s21_sprintf_test4_s, s21_sprintf_test4_s);
    tcase_add_test(tc5_s21_sprintf_test5_s, s21_sprintf_test5_s);
    tcase_add_test(tc6_s21_sprintf_test6_s, s21_sprintf_test6_s);
    tcase_add_test(tc7_s21_sprintf_test7_s, s21_sprintf_test7_s);
    tcase_add_test(tc8_s21_sprintf_test8_s, s21_sprintf_test8_s);
    tcase_add_test(tc9_s21_sprintf_test9_s, s21_sprintf_test9_s);
    tcase_add_test(tc10_s21_sprintf_test10_s, s21_sprintf_test10_s);
    tcase_add_test(tc11_s21_sprintf_test11_s, s21_sprintf_test11_s);
    tcase_add_test(tc12_s21_sprintf_test12_s, s21_sprintf_test12_s);
    tcase_add_test(tc13_s21_sprintf_test13_s, s21_sprintf_test13_s);
    tcase_add_test(tc14_s21_sprintf_test14_s, s21_sprintf_test14_s);
    tcase_add_test(tc15_s21_sprintf_test15_s, s21_sprintf_test15_s);

    suite_add_tcase(s, tc1_s21_sprintf_test1_s);
    suite_add_tcase(s, tc2_s21_sprintf_test2_s);
    suite_add_tcase(s, tc3_s21_sprintf_test3_s);
    suite_add_tcase(s, tc4_s21_sprintf_test4_s);
    suite_add_tcase(s, tc5_s21_sprintf_test5_s);
    suite_add_tcase(s, tc6_s21_sprintf_test6_s);
    suite_add_tcase(s, tc7_s21_sprintf_test7_s);
    suite_add_tcase(s, tc8_s21_sprintf_test8_s);
    suite_add_tcase(s, tc9_s21_sprintf_test9_s);
    suite_add_tcase(s, tc10_s21_sprintf_test10_s);
    suite_add_tcase(s, tc11_s21_sprintf_test11_s);
    suite_add_tcase(s, tc12_s21_sprintf_test12_s);
    suite_add_tcase(s, tc13_s21_sprintf_test13_s);
    suite_add_tcase(s, tc14_s21_sprintf_test14_s);
    suite_add_tcase(s, tc15_s21_sprintf_test15_s);

    TCase *tc1_s21_sprintf_test1_u = tcase_create("test1_s21_strsprintf_u");
    TCase *tc2_s21_sprintf_test2_u = tcase_create("test2_s21_strsprintf_u");
    TCase *tc3_s21_sprintf_test3_u = tcase_create("test3_s21_strsprintf_u");
    TCase *tc4_s21_sprintf_test4_u = tcase_create("test4_s21_strsprintf_u");
    TCase *tc5_s21_sprintf_test5_u = tcase_create("test5_s21_strsprintf_u");
    TCase *tc6_s21_sprintf_test6_u = tcase_create("test6_s21_strsprintf_u");
    TCase *tc7_s21_sprintf_test7_u = tcase_create("test7_s21_strsprintf_u");
    TCase *tc8_s21_sprintf_test8_u = tcase_create("test8_s21_strsprintf_u");
    TCase *tc9_s21_sprintf_test9_u = tcase_create("test9_s21_strsprintf_u");
    TCase *tc10_s21_sprintf_test10_u = tcase_create("test10_s21_strsprintf_u");
    TCase *tc11_s21_sprintf_test11_u = tcase_create("test11_s21_strsprintf_u");
    TCase *tc12_s21_sprintf_test12_u = tcase_create("test12_s21_strsprintf_u");
    TCase *tc13_s21_sprintf_test13_u = tcase_create("test13_s21_strsprintf_u");
    TCase *tc14_s21_sprintf_test14_u = tcase_create("test14_s21_strsprintf_u");
    TCase *tc15_s21_sprintf_test15_u = tcase_create("test14_s21_strsprintf_u");
    TCase *tc16_s21_sprintf_test16_u = tcase_create("test16_s21_strsprintf_u");
    TCase *tc17_s21_sprintf_test17_u = tcase_create("test17_s21_strsprintf_u");
    TCase *tc18_s21_sprintf_test18_u = tcase_create("test18_s21_strsprintf_u");
    TCase *tc19_s21_sprintf_test19_u = tcase_create("test19_s21_strsprintf_u");

    tcase_add_test(tc1_s21_sprintf_test1_u, s21_sprintf_test1_u);
    tcase_add_test(tc2_s21_sprintf_test2_u, s21_sprintf_test2_u);
    tcase_add_test(tc3_s21_sprintf_test3_u, s21_sprintf_test3_u);
    tcase_add_test(tc4_s21_sprintf_test4_u, s21_sprintf_test4_u);
    tcase_add_test(tc5_s21_sprintf_test5_u, s21_sprintf_test5_u);
    tcase_add_test(tc6_s21_sprintf_test6_u, s21_sprintf_test6_u);
    tcase_add_test(tc7_s21_sprintf_test7_u, s21_sprintf_test7_u);
    tcase_add_test(tc8_s21_sprintf_test8_u, s21_sprintf_test8_u);
    tcase_add_test(tc9_s21_sprintf_test9_u, s21_sprintf_test9_u);
    tcase_add_test(tc10_s21_sprintf_test10_u, s21_sprintf_test10_u);
    tcase_add_test(tc11_s21_sprintf_test11_u, s21_sprintf_test11_u);
    tcase_add_test(tc12_s21_sprintf_test12_u, s21_sprintf_test12_u);
    tcase_add_test(tc13_s21_sprintf_test13_u, s21_sprintf_test13_u);
    tcase_add_test(tc14_s21_sprintf_test14_u, s21_sprintf_test14_u);
    tcase_add_test(tc15_s21_sprintf_test15_u, s21_sprintf_test15_u);
    tcase_add_test(tc16_s21_sprintf_test16_u, s21_sprintf_test16_u);
    tcase_add_test(tc17_s21_sprintf_test17_u, s21_sprintf_test17_u);
    tcase_add_test(tc18_s21_sprintf_test18_u, s21_sprintf_test18_u);
    tcase_add_test(tc19_s21_sprintf_test19_u, s21_sprintf_test19_u);

    suite_add_tcase(s, tc1_s21_sprintf_test1_u);
    suite_add_tcase(s, tc2_s21_sprintf_test2_u);
    suite_add_tcase(s, tc3_s21_sprintf_test3_u);
    suite_add_tcase(s, tc4_s21_sprintf_test4_u);
    suite_add_tcase(s, tc5_s21_sprintf_test5_u);
    suite_add_tcase(s, tc6_s21_sprintf_test6_u);
    suite_add_tcase(s, tc7_s21_sprintf_test7_u);
    suite_add_tcase(s, tc8_s21_sprintf_test8_u);
    suite_add_tcase(s, tc9_s21_sprintf_test9_u);
    suite_add_tcase(s, tc10_s21_sprintf_test10_u);
    suite_add_tcase(s, tc11_s21_sprintf_test11_u);
    suite_add_tcase(s, tc12_s21_sprintf_test12_u);
    suite_add_tcase(s, tc13_s21_sprintf_test13_u);
    suite_add_tcase(s, tc14_s21_sprintf_test14_u);
    suite_add_tcase(s, tc15_s21_sprintf_test15_u);
    suite_add_tcase(s, tc16_s21_sprintf_test16_u);
    suite_add_tcase(s, tc17_s21_sprintf_test17_u);
    suite_add_tcase(s, tc18_s21_sprintf_test18_u);
    suite_add_tcase(s, tc19_s21_sprintf_test19_u);

    return s;
}
