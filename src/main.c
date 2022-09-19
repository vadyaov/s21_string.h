#include <stdio.h>
#include "s21_string.h"


int main() {
  int a = 0;
  int *p = &a;
  printf("p = %p\n&p = %p\n", p, &p);
  char arr[] = "0x1111112afc1";
  int status = sscanf(arr, "%p", &p);
  printf("status = %d\np = %p\n", status, p);
  return 0;
}
