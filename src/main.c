#include <stdio.h>
#include "s21_string.h"


int main() {
  unsigned long long int a = 123;
  unsigned long long *p = &a;
  printf("p = %p\n *p = %lldd\n", p, *p);
  char arr[] = "0xAAAAAAAc8b9fffb49";
  int status = s21_sscanf(arr, "%p", &p);
  printf("status = %d\np = %p\n", status, p);
  return 0;
}
