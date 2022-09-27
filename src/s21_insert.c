#include "s21_string.h"

void *s21_insert(const char *src, const char *str, size_t start_index) {
  char *res = s21_NULL;
  size_t src_len = 0;
  if (src)
    src_len = s21_strlen(src);
  if (src && start_index <= src_len && str) {
    s21_size_t common_len;
    common_len = src_len + s21_strlen(str) + 1;
    res = (char *)malloc(sizeof(char) * common_len);
    if (res) {
      size_t i = 0;
      while (i < start_index) {
        res[i] = *src;
        i++;
        src++;
      }
      while (*str) {
        res[i] = *str;
        i++;
        str++;
      }
      while (*src) {
        res[i] = *src;
        src++;
        i++;
      }
      res[i] = '\0';
    }
  }
  return (void *)res;
}
