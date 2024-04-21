#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int code = CODE_TRUE;
  if (get_scale(value) == 0)
    *result = value;
  else {
    s21_decimal truncated;
    s21_truncate(value, &truncated);
    s21_decimal ost = {0};
    s21_sub(value, truncated, &ost);
    if (zero_equal(ost)) {
      int isPositive = get_sign(value);
      if (isPositive == 0) {
        *result = truncated;
      } else {
        s21_simple_add(truncated, (s21_decimal){{1}}, result);
        set_sign(result, 1);
      }
    } else
      *result = truncated;
  }

  return code;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int code = CODE_TRUE;
  if (result == NULL) {
    code = 1;
  } else {
    initial_num(result);
    memcpy(result->bits, value.bits, sizeof(value.bits));
    int scale = get_scale(value);
    if (scale > 0) {
      for (int i = 0; i < scale; i++) {
        unsigned long long overflow = 0;
        for (int j = 2; j >= 0; j--) {
          unsigned long long dividend = (overflow << 32) + result->bits[j];
          unsigned long long quotient = dividend / 10;
          overflow = dividend % 10;
          result->bits[j] = quotient;
        }
        set_scale(result, 0);
      }
    }
  }
  return code;
}

int s21_truncate_b(s21_big value, s21_big *result) {
  int code = CODE_TRUE;
  if (result == NULL) {
    code = 1;
  } else {
    initial_num_b(result);
    memcpy(result->bits, value.bits, sizeof(value.bits));
    int scale = get_scale_b(value);
    if (scale > 0) {
      for (int i = 0; i < scale; i++) {
        unsigned long long overflow = 0;
        for (int j = 5; j >= 0; j--) {
          unsigned long long dividend = (overflow << 32) + result->bits[j];
          unsigned long long quotient = dividend / 10;
          overflow = dividend % 10;
          result->bits[j] = quotient;
        }
        set_scale_b(result, 0);
      }
    }
  }
  return code;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int code = CODE_TRUE;
  if (!result) return CODE_FALSE;

  if (result == NULL) return CODE_FALSE;

  s21_decimal one_num = {{1, 0, 0, 0}};
  int sign = get_sign(value);
  if (sign == 1) set_sign(&value, 0);

  s21_decimal truncated = {0};
  s21_truncate(value, &truncated);
  s21_decimal ost = {0};
  s21_decimal five = {{5, 0, 0, 0}};
  set_scale(&five, 1);

  s21_sub(value, truncated, &ost);

  if (s21_is_greater_or_equal(ost, five)) {
    s21_add(truncated, one_num, result);
  } else {
    *result = truncated;
  }
  set_sign(result, sign);
  return code;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int code = CODE_TRUE;
  *result = value;

  int sign = get_sign(*result);
  set_sign(result, !sign);
  return code;
}
