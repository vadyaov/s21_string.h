#include "s21_string.h"

int hexnum(char c) {
  int result = 0;
  if (c == 'A' || c == 'a') {
    result = 10;
  } else if (c == 'B' || c == 'b') {
    result = 11;
  } else if (c == 'C' || c == 'c') {
    result = 12;
  } else if (c == 'D' || c == 'd') {
    result = 13;
  } else if (c == 'E' || c == 'e') {
    result = 14;
  } else if (c == 'F' || c == 'f') {
    result = 15;
  }
  return result;
}

int toSkip(const char *format) {
  return (*format == ' ' || *format == '\n' || *format == '\t' ||
          *format == '%');
}

int is_octal_number(const char *buf) { return (*buf >= '0' && *buf <= '8'); }

long long itos_long(const char *string, int *length, info *s, int sign,
                    int *n) {
  *length = 0;
  const char *start = string;
  long long result = 0;
  int pow = 1;
  while (is_number(string)) {
    *length += 1;
    string++;
  }
  string--;
  int wid = s->width > 0 && s->width <= *length ? *length - s->width : -1;
  do {
    result += pow * (*string - '0');
    pow *= 10;
  } while (string-- != start);
  if (sign == -1 && wid > 0)
    wid++;
  while (wid > 0) {
    result /= 10;
    wid--;
  }
  if (!s->star)
    *n += 1;
  return result;
}

int err(int sign, info *s) { return !(sign == -1 && s->width == 1); }

const char *dRead(const char *string, int *error, int *n, info *s,
                  long long *result, int *count) {
  *result = 0;
  const char *buf = string;
  const char *start = s21_NULL;
  const char *end = s21_NULL;
  int width = s->width;
  int sign = 0;
  while (toSkip(buf)) {
    buf++;
    *count += 1;
  }
  if (*buf == '-' || *buf == '+') {
    if (*buf == '-')
      sign = 1;
    buf++;
    width--;
    *count += 1;
  }
  if (*buf == '0' && *(buf + 1) == 'x') {
    unsigned long long res = 0;
    end = xRead(string, error, n, s, &res, count);
    *result = res;
  } else if (*buf == '0' && is_number(buf + 1)) {
    long long res = 0;
    end = oRead(buf, error, n, s, &res, count);
    *result = pow(-1, sign) * res;
  } else if (is_number(buf) && width) {
    start = buf;
    while (is_number(buf) && width) {
      buf++;
      width--;
      *count += 1;
    }
    end = buf;
    buf--;
    for (int i = 0; buf >= start; buf--, i++)
      *result += (*buf - '0') * pow(10.0, i);
    *result *= pow(-1, sign);
    if (!s->star)
      *n += 1;
  } else {
    *error = 1;
  }
  return end;
}

const char *sRead(const char *string, info *s, char *str, int *count,
                  stringp *sp) {
  int len = 0;
  int i = 0;
  int to_skip = 0;
  const char *end = s21_NULL;
  const char *buf = string;
  while (toSkip(buf) && *buf) {
    to_skip++;
    buf++;
    *count += 1;
  }
  const char *start = buf;
  while (!toSkip(buf) && *buf && s->width) {
    len += 1;
    buf++;
    s->width--;
    *count += 1;
  }
  end = buf;
  buf--;
  str = malloc(len + 1);
  sp->str = str;
  while (start <= buf) {
    str[i] = *start;
    i++;
    start++;
  }
  str[i] = '\0';
  return end;
}

const char *cRead(const char *string, char *c, int *count) {
  *c = *string;
  string++;
  *count += 1;
  return string;
}

const char *uRead(const char *string, int *error, int *n, info *s,
                  unsigned long *result, int *count) {
  int len_number = 0;
  int sign = 0;
  int cd = 0;
  while (toSkip(string)) {
    string++;
    *count += 1;
  }
  if (*string == '-' && is_number(string + 1)) {
    sign = -1;
    string++;
    *count += 1;
    if (!s->star)
      cd = 1;
  }
  if (is_number(string) && !sign) {
    sign = 1;
  }
  if (!err(sign, s))
    *error = 1;
  if (is_number(string) && !*error) {
    *result = sign * itos_long(string, &len_number, s, sign, n);
    *count += len_number;
  }
  return s->width > 0 && s->width < len_number + cd ? string + s->width - cd
                                                    : string + len_number;
}

char *float_str_len(const char *str, int *int_part, int *float_part) {
  int i_len = 0, f_len = 0;
  for (; is_number(str); i_len++, str++)
    ;
  if (*str == '.') {
    str++;
    while (is_number(str)) {
      f_len++;
      str++;
    }
  }
  *int_part = i_len;
  *float_part = f_len;
  return (char *)str;
}

float GetFloatFromString(const char *string, info *s) {
  char *tmp = (char *)string;
  float num = 0.0, float_part = 0.0;
  int int_part_length = 0, float_part_length = 0;
  string = float_str_len(string, &int_part_length, &float_part_length);
  int f_len_cpy = float_part_length;
  if (s->width != -1 && s->width < int_part_length + float_part_length + 1) {
    int int_p_cpy_w = int_part_length - s->width;
    while (s->width && is_number(tmp)) {
      num += (float)(*tmp - '0') * powf(10.0f, int_part_length - 1);
      tmp++;
      int_part_length--;
      s->width--;
    }
    if (!s->width)
      num /= powf(10.0f, int_p_cpy_w);
    if (*tmp == '.' && s->width) {
      tmp++;
      s->width--;
      f_len_cpy = float_part_length;
      while (s->width && is_number(tmp)) {
        float_part += (float)(*tmp - '0') * powf(10.0f, float_part_length - 1);
        tmp++;
        float_part_length--;
        s->width--;
      }
      float_part /= powf(10.0f, f_len_cpy);
    }
  } else {
    while (is_number(tmp)) {
      num += (float)(*tmp - '0') * powf(10.0f, int_part_length - 1);
      tmp++;
      int_part_length--;
    }
    if (*tmp == '.') {
      tmp++;
      while (is_number(tmp)) {
        float_part += (float)(*tmp - '0') * powf(10.0f, float_part_length - 1);
        tmp++;
        float_part_length--;
      }
      float_part /= powf(10.0f, f_len_cpy - float_part_length);
    }
  }
  num += float_part;
  return num;
}

const char *fRead(const char *string, int *error, int *n, info *s,
                  float *result, int *count) {
  int sign = 0;
  char *tmp = (char *)string;
  char *ret = s21_NULL;
  while (toSkip(tmp)) {
    tmp++;
    *count += 1;
  }
  if (*tmp == '-' && is_number(tmp + 1) && s->width) {
    sign = 1;
    s->width--;
    tmp++;
    *count += 1;
  } else if ((*tmp == '+' && is_number(tmp + 1)) || is_number(tmp)) {
    sign = 0;
    if (*tmp == '+') {
      tmp++;
      s->width--;
      *count += 1;
    }
  } else {
    *error = 1;
  }
  char *end = tmp;
  for (int point = 0, width = s->width;
       point < 2 && width && (is_number(end) || *end == '.') && !*error;
       end++) {
    if (*end == '.')
      point++;
    width--;
  }
  ret = end;
  if (!*error) {
    *result = GetFloatFromString(tmp, s);
    if ((*end == 'e' || *end == 'E') && s->width) {
      int st = 0;
      int sign1 = 1;
      end++;
      s->width--;
      if (*end == '-' || *end == '+') {
        if (*end == '-')
          sign1 = -1;
        end++;
        s->width--;
      }
      if (is_number(end) && s->width) {
        char *strt = end;
        while (*end && is_number(end) && s->width) {
          end++;
          s->width--;
        }
        ret = end;
        end--;
        for (int i = 0; end >= strt; i++) {
          st += (*end - '0') * pow(10.0, i);
          end--;
        }
        *result *= pow(10, sign1 * st);
      }
    }
    if (sign)
      *result *= -1.0;
    if (s->star == 0)
      *n += 1;
  }
  return ret;
}

const char *oRead(const char *string, int *error, int *n, info *s,
                  long long *result, int *count) {
  *result = 0;
  const char *buf = string;
  const char *end = s21_NULL;
  int width = s->width;
  while (toSkip(buf)) {
    buf++;
    *count += 1;
  }
  if ((is_octal_number(buf) || *buf == '-' || *buf == '+') && width) {
    int sign = 0;
    if (*buf == '-') {
      sign = 1;
      buf++;
      *count += 1;
      width--;
    } else if (*buf == '+') {
      buf++;
      *count += 1;
      width--;
    }
    if (is_octal_number(buf) && width) {
      const char *start = buf;
      while (is_octal_number(buf) && *buf && width) {
        buf++;
        *count += 1;
        width--;
      }
      end = buf;
      buf--;
      for (int i = 0; buf >= start; i++, buf--) {
        *result += (*buf - '0') * (long long)pow(8, i);
      }
      if (sign)
        *result *= -1;
    } else {
      *error = 1;
    }
    if (!s->star)
      *n += 1;
  } else {
    *error = 1;
  }
  return end;
}

int is_hex_letter(const char *buf) {
  return (*buf == 'A' || *buf == 'B' || *buf == 'C' || *buf == 'D' ||
          *buf == 'E' || *buf == 'F' || *buf == 'a' || *buf == 'b' ||
          *buf == 'c' || *buf == 'd' || *buf == 'e' || *buf == 'f');
}

char *makeResult(const char *start, const char *buf, info *s, int width,
                 unsigned long long *result, int *count) {
  start = buf;
  while ((is_number(buf) || is_hex_letter(buf)) && width && *buf) {
    buf++;
    *count += 1;
    width--;
  }
  char *end = (char *)buf;
  buf--;
  for (int i = 0; buf >= start; i++) {
    unsigned long long int resCpy = *result;
    if (is_number(buf)) {
      *result += (*buf - '0') * (unsigned long long)pow(16.0, i);
    } else {
      *result += (hexnum(*buf)) * (unsigned long long)pow(16.0, i);
    }
    if ((*result < resCpy || (*result == resCpy && (*buf - '0'))) &&
        (s->type == 'x' || s->type == 'X')) {
      *result = 4294967295;
      break;
    }
    buf--;
  }
  return end;
}

const char *xRead(const char *string, int *error, int *n, info *s,
                  unsigned long long int *result, int *count) {
  *result = 0;
  const char *buf = string;
  const char *end = s21_NULL;
  const char *start = s21_NULL;
  int width = s->width;
  while (toSkip(buf)) {
    buf++;
    *count += 1;
  }
  if ((*buf == '+' || *buf == '-' || (*buf == '0' && *(buf + 1) == 'x') ||
       is_number(buf)) &&
      width) {
    int sign = 0;
    if (*buf == '-' || *buf == '+') {
      if (*buf == '-')
        sign = 1;
      buf++;
      *count += 1;
      width--;
    }
    if (*buf == '0' && *(buf + 1) == 'x') {
      if (width != 1 && width != 2) {
        buf += 2;
        *count += 2;
        width -= 2;
        end = makeResult(start, buf, s, width, result, count);
      } else {
        *result = 0;
      }
    } else {
      end = makeResult(start, buf, s, width, result, count);
    }
    *result *= pow(-1, sign);
    if (s->star != 1)
      *n += 1;
  } else {
    *error = 1;
  }
  return end;
}

const char *pRead(const char *string, int *error, int *n, info *s,
                  unsigned long long int *result, int *count) {
  return xRead(string, error, n, s, result, count);
}

const char *readString(const char *string, va_list *ap, int *n, info *s,
                       int *err, int *symb_count) {
  *err = 0;
  switch (s->type) {
  case 'd':
  case 'i': {
    long long res;
    int *adress = s21_NULL;
    if (!s->star)
      adress = va_arg(*ap, int *);
    string = dRead(string, err, n, s, &res, symb_count);
    if (!s->star) {
      if (*err)
        res = *adress;
      *adress = res;
    }
    break;
  }
  case 's': {
    char *buffer = s21_NULL;
    char *str = s21_NULL;
    stringp sp;
    if (!s->star)
      str = va_arg(*ap, char *);
    string = sRead(string, s, buffer, symb_count, &sp);
    if (!s->star) {
      s21_strcpy(str, sp.str);
      *n += 1;
    }
    free(sp.str);
    break;
  }
  case 'c': {
    if (s->width == -1) {
      char c;
      char *symbol = s21_NULL;
      if (!s->star)
        symbol = va_arg(*ap, char *);
      string = cRead(string, &c, symb_count);
      if (!s->star) {
        *symbol = c;
        *n += 1;
      }
    }
    if (s->width > 0) {
      char *buffer = s21_NULL;
      char *str = s21_NULL;
      stringp sp;
      if (!s->star)
        str = va_arg(*ap, char *);
      string = sRead(string, s, buffer, symb_count, &sp);
      if (!s->star) {
        s21_strcpy(str, sp.str);
        *n += 1;
      }
      free(sp.str);
    }
    break;
  }
  case 'u': {
    unsigned long u;
    unsigned int *adress = s21_NULL;
    if (!s->star)
      adress = va_arg(*ap, unsigned int *);
    string = uRead(string, err, n, s, &u, symb_count);
    if (!s->star) {
      if (*err)
        u = *adress;
      *adress = u;
    }
    break;
  }
  case 'e':
  case 'E':
  case 'f':
  case 'g':
  case 'G': {
    float f;
    float *adress = s21_NULL;
    if (!s->star)
      adress = va_arg(*ap, float *);
    string = fRead(string, err, n, s, &f, symb_count);
    if (!s->star) {
      if (*err)
        f = *adress;
      *adress = f;
    }
    break;
  }
  case 'o': {
    long long number;
    int *pointer = s21_NULL;
    if (!s->star)
      pointer = va_arg(*ap, int *);
    string = oRead(string, err, n, s, &number, symb_count);
    if (!s->star) {
      if (*err)
        number = *pointer;
      *pointer = number;
    }
    break;
  }
  case 'x':
  case 'X': {
    unsigned long long int number;
    unsigned int *pointer = s21_NULL;
    if (!s->star)
      pointer = va_arg(*ap, unsigned int *);
    string = xRead(string, err, n, s, &number, symb_count);
    if (!s->star) {
      if (*err)
        number = *pointer;
      *(unsigned long long int *)pointer = number;
    }
    break;
  }
  case 'p': {
    void *pointer = s21_NULL;
    unsigned long long int number;
    if (!s->star)
      pointer = va_arg(*ap, void *);
    string = pRead(string, err, n, s, &number, symb_count);
    if (!s->star) {
      if (*err)
        number = *(unsigned long long int *)pointer;
      *(unsigned long long int *)pointer = number;
    }
    break;
  }
  case 'n': {
    int *adress = s21_NULL;
    if (!s->star)
      adress = va_arg(*ap, int *);
    *symb_count -= 1;
    if (!s->star) {
      *adress = *symb_count;
    }
    break;
  }
  default:
    break;
  }
  return string;
}
