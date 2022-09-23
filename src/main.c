#include <stdio.h>
#include "s21_string.h"


int main() {
  float p;
  int n = 0, a = 0;
  char arr[] = "-243.3 11";
  int status = sscanf(arr, "    %f  %d  %n", &p, &a, &n);
  printf("status = %d\np = %f\na = %d\nn = %d\n", status, p, a, n);
  return 0;
}
