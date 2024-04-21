#include "s21_decimal.h"
/*---------------------int to decimal---------------------*/
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int code = CODE_TRUE;
  initial_num(dst);
  if (src < 0) {
    set_sign(dst, 1);
    src *= -1;
  }
  dst->bits[0] = src;
  return code;
}
/*---------------------decimal to int---------------------*/
int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = CODE_FALSE, so_small_div = 0;
  if (dst) {
    s21_decimal temp_dec = src;
    int scale_dec = get_scale(temp_dec);
    while (scale_dec > 0 && so_small_div == 0) {
      division_10(&temp_dec, &scale_dec, &so_small_div);
    }
    if (so_small_div) *dst = 0;

    int count_null = 0;
    for (int i = 2; i >= 1; i--) {
      if ((src.bits[i]) == 0) count_null++;
    }
    if (count_null == 2 && get_scale(temp_dec) == 0) error = CODE_TRUE;

    int count_ind_for_max = 0;
    for (int j = 30; j >= 0; j--) {
      if (get_bit(temp_dec, j) == 1) count_ind_for_max++;
    }
    if (get_bit(temp_dec, 31) == 0 && count_ind_for_max == 31 &&
        get_sign(temp_dec)) {
      temp_dec.bits[0] = ~(temp_dec.bits[0]);
      *dst = temp_dec.bits[0];
    }

    if (get_bit(temp_dec, 31) == 0 && error == CODE_TRUE) {
      *dst = temp_dec.bits[0];
      if (get_sign(temp_dec)) *dst *= -1;
    }
  }
  return error;
}
/*---------------------float to decimal---------------------*/

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int code = CODE_TRUE;
  int sign = 0;

  if (dst == NULL || incorrect_float(src)) {
    code = CODE_FALSE;
  } else if (src == 0.0) {
    code = CODE_TRUE;
    initial_num(dst);

  } else {
    initial_num(dst);
    char str[500] = {0};

    if (src < 0) {
      src = src * -1;
      sign = 1;
    }
    if (src != 0.0) {
      sprintf(str, "%.6E", src);
      int exp = exp_float(str);
      if (exp < -22) {
        exp += 28;
        sprintf(str, "%.*E", exp, src);
      }
      from_str_to_decimal(str, dst);
    }
  }
  set_sign(dst, sign);

  return code;
}

void from_str_to_decimal(char str[500], s21_decimal *dst) {
  int plus = 0;
  int minus = 0;
  int i = 0;
  int exp = 0;
  int scale = 0;
  int end_int = 0;

  for (; str[i] != 'E'; i++) {
    if (str[i] == '.') {
      end_int = 1;
      continue;
    }
    norm(dst, 1);
    dst->bits[0] += str[i] - '0';
    if (end_int) scale++;
  }

  i++;
  if (str[i] == '+') plus = 1;
  if (str[i] == '-') minus = 1;

  for (i += 1; str[i] != '\0'; i++) {
    exp *= 10;
    exp += str[i] - '0';
  }

  if (plus) {
    scale -= exp;
  } else if (minus) {
    scale += exp;
  }

  if (scale < 0) {
    norm(dst, -(scale));
    scale = 0;
  }

  set_scale(dst, scale);
}

int exp_float(char str[500]) {
  int exp = 0;
  int flag = 0;
  char *s = str;
  char num[100] = {0};
  char *n = num;

  while (*s != '\0') {
    if (flag == 1) {
      *n = *s;
      n++;
    }
    if (*s == 'E') flag = 1;
    s++;
  }

  int minus = 0;

  for (int i = 0; num[i] != '\0'; i++) {
    exp *= 10;
    if (num[i] == '-')
      minus = 1;
    else
      exp += num[i] - '0';
  }

  if (minus) exp *= -1;

  return exp;
}

int incorrect_float(float src) {
  int code = 0;

  if (src > MAX_DECIMAL || src < MIN_DECIMAL || isnan(src) || isinf(src))
    code = 1;

  return code;
}

/*--------------------decimal to float----------------------*/
int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  *dst = 0;
  double buf = 0;
  for (int i = 0; i < 96; i++) {
    buf += get_bit(src, i) * pow(2, i);
  }
  double power = pow(10, get_scale(src));
  buf /= power;
  if (get_sign(src) == 1) buf *= -1;
  *dst = buf;
  return 0;
}