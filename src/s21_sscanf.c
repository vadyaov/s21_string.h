#include "s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  int toReturn = 0;
  int erorr = 0, symb_count = 0;
  info inf;
  va_list ap;
  va_start(ap, format);
  const char *buf = str;
  char *next = s21_NULL;
  while (*format) {
    if (*format == ' ' || *format == '\n' || *format == '\t') {
      format++;
    } else if (*format == '%') {
      next = get_info(format, &inf);
      //            print_s(&inf);
      if (inf.flag1 || inf.flag2 || inf.flag3)
        break;
      buf = readString(buf, &ap, &toReturn, &inf, &erorr, &symb_count);
      format = next + 1;
    } else {
      break;
    }
    if (erorr)
      break;
  }
  va_end(ap);
  return toReturn;
}
