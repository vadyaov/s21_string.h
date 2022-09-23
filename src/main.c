#include <stdio.h>
#include "s21_string.h"


int main() {
  float p;
  int n = 0, a = 0;
  int *q = &a;
  char arr[] = "-243.3 11     0x12345AA    ";
  int status = s21_sscanf(arr, " %f %d %n %p", &p, &a, &n, &q);
  printf("status = %d\np = %f\na = %d\nn = %d\nq = %p\n", status, p, a, n, q);
  return 0;
}
