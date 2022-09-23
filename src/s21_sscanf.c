#include "s21_string.h"

const char *xRead(const char *string, int *error, int *n, info *s, unsigned long long int *result, int *count);
const char *oRead(const char *string, int *error, int *n, info *s, long long *result, int *count);

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
    return (*format == ' ' || *format == '\n' || *format == '\t' || *format == '%');
}

int is_octal_number(const char *buf) {
    return (*buf >= '0' && *buf <= '8');
}

long long itos_long(const char *string, int *length, info *s, int sign, int *n) {
    *length = 0;
    const char* start = string;
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
    if (sign == -1 && wid > 0) wid++;
    while (wid > 0) {
        result /= 10;
        wid--;
    }
    if (!s->star)
        *n += 1;
    return result;
}

int len_f_number(const char *str, int *ipart, int *fpart) {
    int result = 0;
    while (is_number(str)) {
        *ipart += 1;
        str++;
    }
    if (*str == '.') {
        str++;
        while (is_number(str)) {
            *fpart += 1;
            str++;
        }
    }
    if (*fpart < 6) *fpart = 6;
    result = *ipart + *fpart + 1;
    return result;
}

float ftos(const char *string, int *length, info *s) {
    *length = 0;
    int ipartlen = 0;
    int floatpartlen = 0;
    // const char *start = string;
    float result = 0;
    *length = len_f_number(string, &ipartlen, &floatpartlen);
    int iwid = s->width > 0 && s->width < ipartlen ? s->width : ipartlen;
    int fwid = s->width > ipartlen && s->width < *length ? *length - s->width : floatpartlen;
    // printf("iwid = %d\nfwid = %d\n", iwid, fwid);
    int ipart = itos(string, length);
    // printf("ipart = %d\n", ipart);
    long long int fpart;
    if (is_number(string + iwid + 1)) {
        fpart = itos(string + iwid + 1, length);
    } else {
        fpart = 0;
    }
    // printf("fpart = %d\n", fpart);
    float f_fpart = fpart / powf(10.0, (float)fwid);
    result = ipart + f_fpart;
    return result;
}

int err(int sign, info *s) {
    return !(sign == -1 && s->width == 1);
}

const char* dRead(const char *string, int *error, int *n, info *s, long long *result, int *count) {
    *result = 0;
    const char *buf = string;
    // printf("buf = %c %d\n", *buf, *buf);
    const char * start = s21_NULL;
    const char * end = s21_NULL;
    int width = s->width;
    int sign = 0;
    while (toSkip(buf)) {
        buf++;
        *count += 1;
    }
    if (*buf == '0' && *(buf + 1) == 'x') {
        unsigned long long res = 0;
        end = xRead(string, error, n, s, &res, count);
        *result = res;
    } else if ((*buf == '+' || *buf == '-') && (*buf == '0' && is_number(buf + 1))) {
        if (*buf == '+' || *buf == '-') {
            if (*buf == '-') sign = 1;
            buf++;
            *count += 1;
        }
        long long res = 0;
        end = oRead(buf, error, n, s, &res, count);
        *result = pow(-1, sign) * res;
    } else if ((is_number(buf) || *buf == '+' || * buf == '-') && width) {
        // printf("*buf = %c\n", *buf);
        if (*buf == '-' || *buf == '+') {
            if (*buf == '-') sign = 1;
            buf++;
            width--;
            *count += 1;
        }
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
        // printf("sign = %d\n", sign);
        *result *= pow(-1, sign);
        *n += 1;
    } else {
        *error = 1;
    }
    return end;
}

const char *sRead(const char *string, info *s, char *str, int *count) {
    int len = 0;
    int i = 0;
    int to_skip =  0;
    const char *buf = string;
    while (toSkip(buf) && *buf) {
        to_skip++;
        buf++;
        *count += 1;
    }
    while (!toSkip(buf) && *buf) {
        len += 1;
        buf++;
    }
    int wid = s->width > 0 ? s->width : len;
    str = realloc(str, wid + 1);
    buf = string + to_skip;
    while (i < len && wid > 0) {
        str[i] = *buf;
        buf++;
        *count += 1;
        i++;
        wid--;
    }
    str[i] = '\0';
    return s->width > 0 && s->width < len ? string + s->width + to_skip : string + len + to_skip;
}

const char *cRead(const char *string, char *c, int *count) {
    *c = *string;
    string++;
    *count += 1;
    return string;
}

const char *uRead(const char *string, int *error, int *n, info *s, unsigned long *result, int *count) {
    long long d_number;
    int len_number;
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
        if (!s->star) cd = 1;
    }
    if(is_number(string) && !sign) {
        sign = 1;
    }
    if (!err(sign, s)) *error = 1;
    if (is_number(string) && !*error) {
        d_number = sign * itos_long(string, &len_number, s, sign, n);
        *result = d_number;
        *count += len_number;
    }
    return s->width > 0 && s->width < len_number + cd ? string + s->width - cd : string + len_number;
}
// length with a '.' symbol if it exists
char* float_str_len(const char *str, int *int_part, int *float_part) {
    int i_len = 0, f_len = 0;
    for (; is_number(str); i_len++, str++);
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

float GetFloatFromString(const char *string, int width, int *add_to_string) {
    *add_to_string = 0;
    char *tmp = (char *)string;
    float num = 0.0, float_part = 0.0;
    int int_part_length = 0, float_part_length = 0;
    int widthcpy = width;
    string = float_str_len(string, &int_part_length, &float_part_length);
    int f_len_cpy = float_part_length, int_p_cpy = int_part_length;
    if (width != -1 && width < int_part_length + float_part_length + 1) {
        int int_p_cpy_w = int_part_length - width;
        while (width && is_number(tmp)) {
            num += (float)(*tmp -'0') * powf(10.0f, int_part_length - 1);
            tmp++;
            int_part_length--;
            width--;
        }
        if (!width) num /= powf(10.0f, int_p_cpy_w);
        if (*tmp == '.' && width) {
            tmp++;
            width--;
            int f_len_cpy = float_part_length;
            while (width && is_number(tmp)) {
                float_part += (float)(*tmp - '0') * powf(10.0f, float_part_length - 1);
                tmp++;
                float_part_length--;
                width--;
            }
            float_part /= powf(10.0f, f_len_cpy);
        }
    } else {
        while (is_number(tmp)) {
            num += (float)(*tmp -'0') * powf(10.0f, int_part_length - 1);
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
    *add_to_string = (tmp == string) ? int_p_cpy + f_len_cpy : widthcpy;
    if ((*tmp == 'e' || *tmp == 'E') && width) {
        int st = 0;
        int sign = 1;
        tmp++;
        width--;
        *add_to_string += 1;
        if (*tmp == '-' || *tmp == '+') {
            if (*tmp == '-') sign = -1;
            tmp++;
            width--;
            *add_to_string += 1;
        }
        if (is_number(tmp) && width) {
            char *strt = tmp;
            while (*tmp && is_number(tmp) && width) {
                tmp++;
                *add_to_string += 1;
                width--;
            }
            tmp--;
            for (int i = 0; tmp >= strt; i++) {
                st += (*tmp -'0') * pow(10.0, i);
                tmp--;
            }
            num *= pow(10, sign * st);
        }
    }
    return num;
}

const char *fRead(const char *string, int *error, int *n, info *s, float *result, int *count) {
    int sign = 0;
    int to_add = 0;
    while (toSkip(string)) {
        string++;
        *count += 1;
    }
    if (*string == '-' && is_number(string + 1)) {
        sign = 1;
        string++;
        *count += 1;
    } else if ((*string == '+' && is_number(string + 1)) || is_number(string)) {
        sign = 0;
        if (*string == '+') {
            string++;
            *count += 1;
        }
    } else {
        *error = 1; 
    }
    char *tmp = (char *)string;
    for (int point = 0; point < 2 && (is_number(tmp) || *tmp == '.') && !*error; tmp++) {
        if (*tmp == '.') point++;
    }
    // printf("???tmp = %c\n", *tmp);
    if (!*error) {
        *result = GetFloatFromString(string, s->width, &to_add);
        if (sign) *result *= -1.0;
        *n += 1;
        *count += to_add + 1;
    }
    return (s->width > 0 && (string + s->width) < tmp) ? string + s->width : tmp;
}

const char *oRead(const char *string, int *error, int *n, info *s, long long *result, int *count) {
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
                *result += (*buf -'0') * (long long)pow(8, i);
            }
            if (sign) *result *= -1;
            *n += 1;
        } else {
            *error = 1;
        }
    } else {
        *error = 1;
    }
    return end;
}

int is_hex_letter(const char *buf) {
    return (*buf == 'A' || *buf == 'B' || *buf == 'C' || 
            *buf == 'D' || *buf == 'E' || *buf == 'F' ||
            *buf == 'a' || *buf == 'b' || *buf == 'c' || 
            *buf == 'd' || *buf == 'e' || *buf == 'f');
}

const char *xRead(const char *string, int *error, int *n, info *s, unsigned long long int *result, int *count) {
    *result = 0;
    unsigned long long int resCpy = *result;
    const char *buf = string;
    const char *end = s21_NULL;
    const char *start = s21_NULL;
    int width = s->width;
    int sign = 0;
    printf("str = %c\n", *string);
    while (toSkip(buf)) {
        buf++;
        *count += 1;
    }
    if ((*buf == '+' || *buf == '-' || (*buf == '0' && *(buf + 1) == 'x') || is_number(buf)) && width) {
        if (*buf == '-' || *buf == '+') {
            if (*buf == '-') sign = 1;
            buf++;
            *count += 1;
            width--;
        }
        if (*buf == '0' && *(buf + 1) == 'x') {
            if (width != 1 && width != 2) {
                buf += 2;
                *count += 2;
                width -= 2;
                start = buf;
                while ((is_number(buf) || is_hex_letter(buf)) && width && *buf) {
                    buf++;
                    *count += 1;
                    width--;
                }
                end = buf;
                buf--;
                for (int i = 0; buf >= start; i++) {
                    resCpy = *result;
                    if (is_number(buf)) {
                        *result += (*buf - '0') * (unsigned long long)pow(16.0, i);
                    } else {
                        *result += (hexnum(*buf)) * (unsigned long long)pow(16.0, i);
                    }
                    // printf("%llu\t%llu\n", *result, (unsigned long long)pow(16.0, i));
                    if ((*result < resCpy || (*result == resCpy && (*buf - '0'))) /*&& (s->type == 'x' || s->type == 'X')*/) {
                        if ((s->type == 'x' || s->type == 'X')) *result = 4294967295;
                        else if (s->type == 'p') {
                            *result = 18446744073709551615ULL;
                            printf("SDFSDF\n");
                        }
                        break;
                    }
                    buf--;
                }
            } else {
                *result = 0;
            }
        } else {
            start = buf;
            while ((is_number(buf) || is_hex_letter(buf)) && width && *buf) {
                buf++;
                *count += 1;
                width--;
            }
            end = buf;
            buf--;
            for (int i = 0; buf >= start; i++) {
                resCpy = *result;
                if (is_number(buf)) {
                    *result += (*buf - '0') * (unsigned long long)pow(16.0, i);
                } else {
                    *result += (hexnum(*buf)) * (unsigned long long)pow(16.0, i);
                }
                if ((*result < resCpy || (*result == resCpy && (*buf - '0'))) && (s->type == 'x' || s->type == 'X')) {
                    *result = 4294967295;
                    break;
                }
                buf--;
            }
        }
        *result *= pow(-1, sign);
        *n += 1;
    } else {
        *error = 1;
    }
    return end;
}

const char *pRead(const char *string, int *error, int *n, info *s, unsigned long long int *result, int *count) {
    return xRead(string, error, n, s, result, count);
}

const char *readString(const char *string, va_list *ap, int *n, info *s, int *err) {
    *err = 0;
    static int symb_count = 0;
    switch (s->type) {
    case 'd':
    case 'i': {
        long long res;
        int *adress = s21_NULL;
        if (!s->star)
            adress = va_arg(*ap, int *);
        string = dRead(string, err, n, s, &res, &symb_count);
        if (!s->star) {
            if (*err) res = *adress;
            *adress = res;
        }
        break;
    }
    case 's': {
        char *buffer = malloc(1);
        char *str = s21_NULL;
        if (!s->star)
            str = va_arg(*ap, char *);
        string = sRead(string, s, buffer, &symb_count);
        s21_strcpy(str, buffer);
        if (!s->star) *n += 1;
        free(buffer);
        break;
    }
    case 'c': {
        if (s->width == -1) {
            char c;
            char *symbol = s21_NULL;
            if (!s->star)
                symbol = va_arg(*ap, char *);
            string = cRead(string, &c, &symb_count);
            if (!s->star) {
                *symbol = c;
                *n += 1;
            }
        }
        if (s->width > 0) {
            char *buffer = malloc(1);
            char *str = s21_NULL;
            if (!s->star)
                str = va_arg(*ap, char *);
            string = sRead(string, s, buffer, &symb_count);
            s21_strcpy(str, buffer);
            if (!s->star) *n += 1;
            free(buffer);
        }
        break;
    }
    case 'u': {
        unsigned long u;
        unsigned int *adress = s21_NULL;
        if (!s->star)
            adress = va_arg(*ap, unsigned int *);
        string = uRead(string, err, n, s, &u, &symb_count);
        if (!s->star) {
            if (*err) u = *adress;
            *adress = u;
        }
        break;
    }
    // тут должно все работать одновеменно, и считыаться флоат число и научная нотация если это она
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G': {
        float f;
        float *adress = s21_NULL;
        if (!s->star)
            adress = va_arg(*ap, float *);
        string = fRead(string, err, n, s, &f, &symb_count);
        printf("string = %c\n", *string);
        if (!s->star) {
            if (*err) f = *adress;
            *adress = f;
        }
        break;
    }
    case 'o': {
        long long number;
        int *pointer = s21_NULL;
        if (!s->star)
            pointer = va_arg(*ap, int *);
        string = oRead(string, err, n, s, &number, &symb_count);
        if (!s->star) {
            if (*err) number = *pointer;
            *pointer = number;
        }
        break;
    }
    case 'x':
    case 'X': {
        unsigned long long int number;
        unsigned int *pointer = s21_NULL;
        if (!s->star)
            pointer = va_arg(*ap, unsigned int*);
        string = xRead(string, err, n, s, &number, &symb_count);
        if (!s->star) {
            if (*err) number = *pointer;
            *(unsigned long long int *)pointer = number;
        }
        break;
    }
    case 'p': {
        void *pointer = s21_NULL;
        unsigned long long int number;
        if (!s->star)
            pointer = va_arg(*ap, void *);
        string = pRead(string, err, n, s, &number, &symb_count);
        if (!s->star) {
            if (*err) number = *(unsigned long long int *)pointer;
            *(unsigned long long int *)pointer = number;
        }
        break;
    }
    case 'n': {
        int *adress = s21_NULL;
        if (!s->star)
            adress = va_arg(*ap, int *);
        while (toSkip(string)) {
            string++;
            symb_count++;
        }
        if (!s->star) {
            *adress = symb_count;
        }
        break;
    }
    default:
        break;
    }
    return string;
}
/*
char input[] = "25 54.32E-1 Thompson 56789 0123 56ß水";

     parse as follows:
       %d: an integer
       %f: a floating-point value
       %9s: a string of at most 9 non-whitespace characters
       %2d: two-digit integer (digits 5 and 6)
       %f:  a floating-point value (digits 7, 8, 9)
       %*d: an integer which isn't stored anywhere
       ' ': all consecutive whitespace
       %3[0-9]: a string of at most 3 decimal digits (digits 5 and 6)
       %2lc: two wide characters, using multibyte to wide conversion 

    int ret = sscanf(input, "%d%f%9s%2d%f%*d %3[0-9]%2lc",
                     &i, &x, str1, &j, &y, str2, warr);
*/
int s21_sscanf(const char *str, const char *format, ...) {
    int toReturn = 0;
    int erorr = 0;
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
            print_s(&inf);
            if (inf.flag1 || inf.flag2 || inf.flag3) break;
            buf = readString(buf, &ap, &toReturn, &inf, &erorr);
            format = next + 1;
        } else {
            break;
        }
        if (erorr) break;
    }
    va_end(ap);
    return toReturn;
}
