#include <stdio.h>
#include "s21_string.h"


int main() {
  char arr[] = "%abcd";
  char c[5] = {'\0'};
  int status = sscanf(arr, "%%%s", c);
  printf("status = %d\np = %s\n", status, c);
  return 0;
}
