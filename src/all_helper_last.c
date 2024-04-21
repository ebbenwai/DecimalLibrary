#include "s21_decimal.h"

/**
 * @brief возвращает значение определенного бита
 *
 * | принимает значение decimal и index бита, который нужно узнать
 */
int get_bit(s21_decimal value, int index) {
  int bit;
  if (!(value.bits[index / 32] & (1U << (index % 32)))) {
    bit = 0;
  } else {
    bit = 1;
  }
  return bit;
}

int get_bit_b(s21_big value, int index) {
  int bit;
  if (!(value.bits[index / 32] & (1U << (index % 32)))) {
    bit = 0;
  } else {
    bit = 1;
  }
  return bit;
}
/**
 * @brief меняет определенный бит decimal
 *
 * | принимает значение decimal,index бита и номер переменной
 */
void set_bit(s21_decimal *decimal, int index, int value) {
  int block = index / 32;
  int pos = index % 32;

  if (value == 1) {  // Установка бита в 1
    decimal->bits[block] |= (1 << pos);
  } else {
    decimal->bits[block] &= ~(1 << pos);  // Установка бита в 0
  }
}

void set_bit_b(s21_big *decimal, int index, int value) {
  int block = index / 32;
  int pos = index % 32;

  if (value == 1) {  // Установка бита в 1
    decimal->bits[block] |= (1 << pos);
  } else {
    decimal->bits[block] &= ~(1 << pos);  // Установка бита в 0
  }
}

/**
 * @brief возвращает знак decimal
 *
 * 1 - отрицательное число
 * 0 - положительное число
 */
int get_sign(s21_decimal value) {
  return !!(value.bits[3] & (1U << 31)) ? 1 : 0;
}

int get_sign_b(s21_big value) { return !!(value.bits[6] & (1U << 31)) ? 1 : 0; }
/**
 * @brief меняет знак decimal
 *
 * | принимает значения указатель на decimal и знак на который нужно поменять |
 *
 * 1 - отрицательное число
 * 0 - положительное число
 */
void set_sign(s21_decimal *value, int sign) { set_bit(value, 127, sign); }

void set_sign_b(s21_big *value, int sign) { set_bit_b(value, 223, sign); }

/**
 * @brief возвращает значение scale (степень)
 */
int get_scale(s21_decimal value) {
  int scale = 0;
  if (get_sign(value) == 1) {
    set_sign(&value, 0);
  }
  value.bits[3] >>= 16;
  scale = value.bits[3];
  return scale;
}

int get_scale_b(s21_big value) {
  int scale = 0;
  if (get_sign_b(value) == 1) {
    set_sign_b(&value, 0);
  }
  value.bits[6] >>= 16;
  scale = value.bits[6];
  return scale;
}

/**
 * @brief устанавливает значение scale (степень) в decimal
 */
void set_scale(s21_decimal *value, int scale) {
  for (int i = 111; i < 120; i++) {  //на 7 битов было 207 и 216
    set_bit(value, i, 0);
  }
  scale <<= 16;
  value->bits[3] = value->bits[3] | scale;
}

void set_scale_b(s21_big *value, int scale) {
  for (int i = 207; i < 216; i++) {
    set_bit_b(value, i, 0);
  }
  scale <<= 16;
  value->bits[6] = value->bits[6] | scale;
}

/**
 * @brief обнуляет весь decimal
 */
void initial_num(s21_decimal *num) {
  for (int i = 0; i < 4; i++) {
    num->bits[i] = 0;
  }
}

void initial_num_b(s21_big *num) {
  for (int i = 0; i < 7; i++) {
    num->bits[i] = 0;
  }
}

/**
 * @brief  умножает на 10, часть нормализации
 */
void norm(s21_decimal *value, int diff_scl) {
  for (int d = 0; d < diff_scl; d++) {
    s21_decimal buff = {0};
    s21_decimal buff1 = {0};
    for (int i = 3; i < 96; i++) {
      set_bit(&buff, i, get_bit(*value, i - 3));
    }

    for (int j = 1; j < 96; j++) {
      set_bit(&buff1, j, get_bit(*value, j - 1));
    }

    s21_simple_add(buff1, buff, value);
  }
}
void norm_b(s21_big *value, int diff_scl) {
  s21_big buff = {0};
  s21_big buff1 = {0};

  for (int d = 0; d < diff_scl; d++) {
    for (int i = 3; i < 192; i++) {
      set_bit_b(&buff, i, get_bit_b(*value, i - 3));
    }

    for (int j = 1; j < 192; j++) {
      set_bit_b(&buff1, j, get_bit_b(*value, j - 1));
    }
    s21_simple_add_b(buff1, buff, value);
  }
}

/**
 * @brief часть для уравнивания скейла и использования нормализации
 */
void comp_and_norm(s21_decimal *scl1, s21_decimal *scl2) {
  int diff;
  if (get_scale(*scl1) < get_scale(*scl2)) {
    diff = get_scale(*scl2) - get_scale(*scl1);

    norm(scl1, diff);
    set_scale(scl1, get_scale(*scl1) + diff);
  } else if (get_scale(*scl1) > get_scale(*scl2)) {
    diff = get_scale(*scl1) - get_scale(*scl2);
    norm(scl2, diff);
    set_scale(scl2, get_scale(*scl2) + diff);
  }
}

/**
 *
 * @brief часть для уравнивания скейла и использования нормализации
 *
 */
void comp_and_norm_b(s21_big *scl1, s21_big *scl2) {
  int diff;
  if (get_scale_b(*scl1) < get_scale_b(*scl2)) {
    diff = get_scale_b(*scl2) - get_scale_b(*scl1);
    norm_b(scl1, diff);
    set_scale_b(scl1, get_scale_b(*scl1) + diff);
  } else if (get_scale_b(*scl1) > get_scale_b(*scl2)) {
    diff = get_scale_b(*scl1) - get_scale_b(*scl2);
    norm_b(scl2, diff);
    set_scale_b(scl2, get_scale_b(*scl2) + diff);
  }
}

/**
 * @brief из 7 в 4
 */
void four_to_seven(s21_big *value_big, s21_decimal value_small) {
  for (int i = 0; i < 3; i++) {
    value_big->bits[i] = value_small.bits[i];
  }
  value_big->bits[6] = value_small.bits[3];

  (void)value_small;
}

/**
 * @brief  Перевод из 7 в 4 инта, успешно? (0 - да, 1 - нет)
 *
 */
int from_7_to_4_ints(s21_big *value, s21_decimal *result) {
  int res = 0;
  if (is_overflow(value))
    res = 1;
  else {
    for (int i = 0; i < 96; i++) {
      set_bit(result, i, get_bit_b(*value, i));
    }
    set_scale(result, get_scale_b(*value));
    set_sign(result, get_sign_b(*value));
  }
  return res;
}

/**
 * @brief  При переводе из 7 в 4 инта есть ли переполнение? (1 - есть
 * переполнение, 0 - нет)
 *
 */
int is_overflow(s21_big *value) {
  int res = 0;
  int so_small_div = 0;
  int scale = get_scale_b(*value);
  while (scale > 28 && so_small_div == 0) {
    division_10_b(value, &scale, &so_small_div);
  }
  if (scale < 29) {
    for (int i = 5; i > 2; i--) {
      if (value->bits[i] != 0) {
        res = 1;
        i = 2;
      }
    }
  }
  return res;
}

int start_num_index(s21_decimal value) {
  int i = 95;
  while (get_bit(value, i) == 0) {
    i--;
  }
  return i;
}

int start_num_index_b(s21_big value) {
  int i = 191;
  while (get_bit_b(value, i) == 0) {
    i--;
  }
  return i;
}

void division_10(s21_decimal *temporary_max, int *max_scale,
                 int *so_small_max) {
  s21_decimal ten = {{10, 0, 0, 0}}, temp_buf = *temporary_max, result = {0};
  int sign = get_sign(*temporary_max);
  set_scale(&temp_buf, 0);
  set_sign(&temp_buf, 0);
  if ((start_num_index(temp_buf) >= start_num_index(ten)) &&
      (s21_simple_less(ten, temp_buf) || s21_simple_equal(ten, temp_buf))) {
    left_shift(&ten, start_num_index(temp_buf) - start_num_index(ten));
    while (start_num_index(ten) > 3) {
      if (s21_simple_less(ten, temp_buf) || s21_simple_equal(ten, temp_buf)) {
        s21_sub_simple(temp_buf, ten, &temp_buf);
        set_bit(&result, 0, 1);
        left_shift(&result, 1);
      } else {
        left_shift(&result, 1);
      }
      right_shift(&ten, 1);
    }
    if (temp_buf.bits[0] >= 10) set_bit(&result, 0, 1);
  } else {
    *so_small_max = 1;
  }
  if (*so_small_max != 1) {
    *max_scale = *max_scale - 1;
    set_scale(&result, *max_scale);
  }
  *temporary_max = result;
  set_sign(temporary_max, sign);
}

void division_10_b(s21_big *temporary_max, int *max_scale, int *so_small_max) {
  s21_big ten = {{10, 0, 0, 0, 0, 0, 0}}, temp_buf = *temporary_max,
          result = {0};
  int sign = get_sign_b(*temporary_max);
  set_scale_b(&temp_buf, 0);
  set_sign_b(&temp_buf, 0);
  if ((start_num_index_b(temp_buf) >= start_num_index_b(ten)) &&
      (s21_simple_less_b(ten, temp_buf) || s21_simple_equal_b(ten, temp_buf))) {
    left_shift_b(&ten, start_num_index_b(temp_buf) - start_num_index_b(ten));
    while (start_num_index_b(ten) > 3) {
      if (s21_simple_less_b(ten, temp_buf) ||
          s21_simple_equal_b(ten, temp_buf)) {
        s21_sub_simple_b(temp_buf, ten, &temp_buf);
        set_bit_b(&result, 0, 1);
        left_shift_b(&result, 1);
      } else {
        left_shift_b(&result, 1);
      }
      right_shift_b(&ten, 1);
    }
    if (temp_buf.bits[0] >= 10) set_bit_b(&result, 0, 1);
  } else {
    *so_small_max = 1;
  }
  if (*so_small_max != 1) {
    *max_scale = *max_scale - 1;
    set_scale_b(&result, *max_scale);
  }
  *temporary_max = result;
  set_sign_b(temporary_max, sign);
}

/**
 * @brief функция для обработки кода ошибок
 */
int errors(s21_big result_b, s21_decimal *result) {
  int code = CODE_OK;
  int res = from_7_to_4_ints(&result_b, result);

  if (res == 1) {
    s21_bank_b(result_b, &result_b);
    res = from_7_to_4_ints(&result_b, result);
    if (res == 1 && get_sign_b(result_b) == 0) {
      code = CODE_PLUS_INF;
    } else if (res == 1 && get_sign_b(result_b) == 1)
      code = CODE_MINUS_INF;
  }

  return code;
}

void left_shift(s21_decimal *value, int position) {
  s21_decimal buff_num = {0};
  for (int i = position; i < 95; i++) {
    set_bit(&buff_num, i, get_bit(*value, i - position));
  }
  *value = buff_num;
}

void right_shift(s21_decimal *value, int positions) {
  s21_decimal copy_value = {0};
  for (int i = 95; i >= 0; i--) {
    set_bit(&copy_value, i, get_bit(*value, i + positions));
  }
  *value = copy_value;
}

void left_shift_b(s21_big *value, int position) {
  s21_big buff_num = {0};
  for (int i = position; i < 192; i++) {
    set_bit_b(&buff_num, i, get_bit_b(*value, i - position));
  }
  *value = buff_num;
}

void right_shift_b(s21_big *value, int positions) {
  s21_big copy_value = {0};
  for (int i = 192; i >= 0; i--) {
    set_bit_b(&copy_value, i, get_bit_b(*value, i + positions));
  }
  *value = copy_value;
}

int s21_bank_b(s21_big value, s21_big *result) {
  int even = 0;
  int code = 0;
  initial_num_b(result);
  s21_big five = {{5, 0, 0, 0}};
  s21_big truncate = {0}, ost = {0}, last_ost_us = {0}, int_ost = {0},
          ost_int_2 = {0};
  s21_big num_one = {{1, 0, 0, 0, 0, 0, 0}};
  int sign = get_sign_b(value);
  set_sign_b(&value, 0);
  *result = value;
  while (
      get_scale_b(*result) > 0 &&
      (result->bits[5] != 0 || result->bits[4] != 0 || result->bits[3] != 0)) {
    value = *result;
    unsigned long long overflow = 0;
    for (int j = 5; j >= 0; j--) {
      unsigned long long dividend = (overflow << 32) + result->bits[j];
      unsigned long long quotient = dividend / 10;
      overflow = dividend % 10;
      result->bits[j] = quotient;
    }
    set_scale_b(result, get_scale_b(*result) - 1);
    s21_truncate_b(value, &truncate);
    s21_sub_b(value, truncate, &ost);
    if (get_scale_b(ost) > 1) {
      set_scale_b(&ost, get_scale_b(ost) - (get_scale_b(ost) - 1));
      s21_truncate_b(ost, &int_ost);
      s21_sub_b(ost, int_ost, &last_ost_us);
      set_scale_b(&last_ost_us, 0);
      set_scale_b(&int_ost, 1);
      s21_truncate_b(int_ost, &ost_int_2);
      set_scale_b(&ost_int_2, 0);
      even = ost_int_2.bits[0] % 2 == 0 ? 1 : 0;
    } else {
      even = truncate.bits[0] % 2 == 0 ? 0 : 1;
    }
    if (even && s21_is_greater_b(last_ost_us, five)) {
      set_scale_b(&num_one, get_scale_b(*result));
      s21_add_b(*result, num_one, result);
    } else if (even && s21_is_greater_or_equal_b(last_ost_us, five)) {
      set_scale_b(&num_one, get_scale_b(*result));
      s21_add_b(*result, num_one, result);
    }
  }
  set_sign_b(result, sign);
  return code;
}