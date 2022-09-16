#include <stdio.h>
#include "s21_string.h"


int main() {
  char arr[] = " ";
  char c;
  int status = sscanf(arr, "%c", &c);
  printf("status = %d\nc = %c.\n", status, c);
  return 0;
}
