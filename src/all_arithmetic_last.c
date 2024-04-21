#include "s21_decimal.h"
/***********************************/
/*************** ADD ***************/
/***********************************/
/**
 * @brief основная функция сложения
 */

int s21_add(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
  int code = CODE_OK;
  s21_big value1_b = {0};
  s21_big value2_b = {0};
  s21_big result_b = {0};

  four_to_seven(&value1_b, value1);
  four_to_seven(&value2_b, value2);
  initial_num(result);

  if (zero_equal_b(value1_b) == 0) {
    for (int i = 0; i < 4; i++) {
      result_b.bits[i] = value2_b.bits[i];
    }
    set_scale_b(&result_b, get_scale_b(value2_b));
    set_sign_b(&result_b, get_sign_b(value2_b));

  } else if (zero_equal_b(value2_b) == 0) {
    for (int i = 0; i < 4; i++) {
      result_b.bits[i] = value1_b.bits[i];
    }
    set_scale_b(&result_b, get_scale_b(value1_b));
    set_sign_b(&result_b, get_sign_b(value1_b));

  } else {
    comp_and_norm_b(&value1_b, &value2_b);
    s21_add_sign_b(value1_b, value2_b, &result_b);
    set_scale_b(&result_b, get_scale_b(value1_b));
  }

  code = errors(result_b, result);

  return code;
}
/**
 * @brief проверяю равна ли переменная нулю или нет
 * если переменная не равна 0, функция вернет 1
 */
int zero_equal(s21_decimal value) {
  int code = 0;
  for (int i = 2; i > -1 && code != 1; i--) {
    if (value.bits[i] != 0) {
      code = 1;
    }
  }
  return code;
}

/**
 * @brief  сложение ТОЛЬКО чисел
 */
void s21_simple_add(s21_decimal value1, s21_decimal value2,
                    s21_decimal *result) {
  int temp = 0;
  for (int i = 0; i < 96; i++) {
    int bit1 = get_bit(value1, i);
    int bit2 = get_bit(value2, i);
    int sum = bit1 + bit2 + temp;

    if (sum == 0) {
      set_bit(result, i, 0);
      temp = 0;
    }
    if (sum == 1) {
      set_bit(result, i, 1);
      temp = 0;
    }
    if (sum == 2) {
      set_bit(result, i, 0);
      temp = 1;
    }
    if (sum == 3) {
      set_bit(result, i, 1);
      temp = 1;
    }
  }
}
/**
 * @brief сложение с учетом знаков
 */
void s21_add_sign(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
  if (get_sign(value1) == get_sign(value2)) {
    s21_simple_add(value1, value2, result);
    set_sign(result, get_sign(value1));
  } else if (get_sign(value1) != get_sign(value2)) {
    int sign1 = get_sign(value1);
    int sign2 = get_sign(value2);
    if (s21_is_greater(value1, value2) == 1) {
      set_sign(result, sign1);
    } else
      set_sign(result, sign2);

    set_sign(&value1, 0);
    set_sign(&value2, 0);
    s21_sub(value2, value1, result);
  }
}
/**
 * @brief основная функция сложения 7 битов
 */
int s21_add_b(s21_big value1, s21_big value2, s21_big *result) {
  initial_num_b(result);
  comp_and_norm_b(&value1, &value2);
  if (zero_equal_b(value1) == 0) {
    for (int i = 0; i < 6; i++) {
      result->bits[i] = value2.bits[i];
    }
    set_sign_b(result, get_sign_b(value2));
  } else if (zero_equal_b(value2) == 0) {
    for (int i = 0; i < 6; i++) {
      result->bits[i] = value1.bits[i];
    }
    set_sign_b(result, get_sign_b(value1));
  } else
    s21_add_sign_b(value1, value2, result);
  set_scale_b(result, get_scale_b(value1));

  return 0;
}

/**
 * @brief проверка равна переменная нулю или нет 7 битов
 * если переменная не равна 0, функция вернет 1
 */
int zero_equal_b(s21_big value) {
  int code = 0;
  for (int i = 5; i > -1 && code != 1; i--) {
    if (value.bits[i] != 0) {
      code = 1;
    }
  }
  return code;
}
/**
 * @brief  сложение ТОЛЬКО чисел
 */
void s21_simple_add_b(s21_big value1, s21_big value2, s21_big *result) {
  int temp = 0;

  for (int i = 0; i < 192; i++) {
    int bit1 = get_bit_b(value1, i);
    int bit2 = get_bit_b(value2, i);
    int sum = bit1 + bit2 + temp;

    if (sum == 0) {
      set_bit_b(result, i, 0);
      temp = 0;
    }
    if (sum == 1) {
      set_bit_b(result, i, 1);
      temp = 0;
    }
    if (sum == 2) {
      set_bit_b(result, i, 0);
      temp = 1;
    }
    if (sum == 3) {
      set_bit_b(result, i, 1);
      temp = 1;
    }
  }
}

/**
 * @brief сложение с учетом знаков 7 битов
 */
void s21_add_sign_b(s21_big value1, s21_big value2, s21_big *result) {
  if (get_sign_b(value1) == get_sign_b(value2)) {
    s21_simple_add_b(value1, value2, result);
    set_sign_b(result, get_sign_b(value1));
  } else if (get_sign_b(value1) != get_sign_b(value2)) {
    int sign1 = get_sign_b(value1);
    int sign2 = get_sign_b(value2);

    set_sign_b(&value1, 0);
    set_sign_b(&value2, 0);

    if (s21_is_greater_b(value1, value2)) {
      s21_sub_b(value1, value2, result);
      set_sign_b(result, sign1);
    } else if (s21_is_greater_b(value2, value1)) {
      s21_sub_b(value2, value1, result);
      set_sign_b(result, sign2);
    } else {
      set_sign_b(result, sign1);
    }
  }
}
/***********************************/
/*************** SUB ***************/
/***********************************/
int s21_sub(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
  int code = CODE_OK;

  s21_big value_1_b = {0};
  s21_big value_2_b = {0};
  s21_big result_b = {0};

  four_to_seven(&value_1_b, value1);
  four_to_seven(&value_2_b, value2);
  initial_num(result);

  comp_and_norm_b(&value_1_b, &value_2_b);

  s21_sub_sign(value_1_b, value_2_b, &result_b);

  set_scale_b(&result_b, get_scale_b(value_1_b));
  code = errors(result_b, result);

  return code;
}

int s21_sub_b(s21_big value1, s21_big value2, s21_big *result) {
  initial_num_b(result);

  comp_and_norm_b(&value1, &value2);
  s21_sub_simple_b(value1, value2, result);
  set_scale_b(result, get_scale_b(value1));

  return 0;
}

int s21_sub_simple(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int count = 0;
  int greater = s21_is_greater(value_1, value_2);
  if (!greater) {
    s21_decimal temp = value_1;
    value_1 = value_2;
    value_2 = temp;
  }
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);

  if (sign_1 == 0 && sign_2 == 1) {
    s21_simple_add(value_1, value_2, result);

  } else {
    if (sign_1 == 1 && sign_2 == 0) {
      set_sign(result, 1);
    } else {
      if (greater) {
        set_sign(result, sign_1);
      } else {
        set_sign(result, sign_1 == 0 ? 1 : 0);
      }
    }
    for (int i = 0; i < 96; i++) {
      int bit_1 = get_bit(value_1, i);
      int bit_2 = get_bit(value_2, i);
      int diff = bit_1 - bit_2 - count;
      if (diff == 0) {
        set_bit(result, i, 0);
        count = 0;
      } else if (diff == 1) {
        set_bit(result, i, 1);
        count = 0;
      } else if (diff == -1) {
        set_bit(result, i, 1);
        count = 1;
      } else if (diff == -2) {
        set_bit(result, i, 0);
        count = 1;
      }
    }
  }
  return 0;
}

/**
 * @brief вычитание ТОЛЬКО чисел
 */
int s21_sub_simple_b(s21_big value_1, s21_big value_2, s21_big *result) {
  int count = 0;

  for (int i = 0; i < 192; i++) {
    int bit_1 = get_bit_b(value_1, i);
    int bit_2 = get_bit_b(value_2, i);
    int diff = bit_1 - bit_2 - count;

    if (diff == 0) {
      set_bit_b(result, i, 0);
      count = 0;
    } else if (diff == 1) {
      set_bit_b(result, i, 1);
      count = 0;
    } else if (diff == -1) {
      set_bit_b(result, i, 1);
      count = 1;
    } else if (diff == -2) {
      set_bit_b(result, i, 0);
      count = 1;
    }
  }

  return 0;
}
/**
 * @brief вычитание с учетом знаков
 */
void s21_sub_sign(s21_big value_1, s21_big value_2, s21_big *result) {
  int sign_1 = get_sign_b(value_1);
  int sign_2 = get_sign_b(value_2);
  set_sign_b(&value_1, 0);
  set_sign_b(&value_2, 0);
  if (sign_1 == sign_2) {
    if (s21_is_greater_b(value_1, value_2)) {
      s21_sub_simple_b(value_1, value_2, result);
      set_sign_b(result, sign_1);
    } else {
      s21_sub_simple_b(value_2, value_1, result);
      set_sign_b(result, !sign_2);
    }
  } else {
    s21_add_b(value_1, value_2, result);
    set_sign_b(result, sign_1);
  }

  if (!zero_equal_b(*result)) {
    set_sign_b(result, 0);
  }
}

/***********************************/
/*************** MUL ***************/
/***********************************/
/**
 * @brief основная функция умножения
 */
int s21_mul(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
  int code = CODE_OK;

  s21_big value_1_b = {0};
  s21_big value_2_b = {0};
  s21_big result_b = {0};

  four_to_seven(&value_1_b, value1);
  four_to_seven(&value_2_b, value2);

  initial_num(result);
  set_scale_b(&result_b, get_scale_b(value_1_b) + get_scale_b(value_2_b));
  s21_mul_simple_b(value_1_b, value_2_b, &result_b);
  int sign = get_sign(value1) ^ get_sign(value2);

  set_sign_b(&result_b, sign);

  code = errors(result_b, result);

  set_sign(result, sign);

  return code;
}

/**
 * @brief умножение ТОЛЬКО чисел
 */
int s21_mul_simple_b(s21_big value_1, s21_big value_2, s21_big *result) {
  set_sign_b(&value_1, 0);
  set_sign_b(&value_2, 0);

  for (int i = 0; i < 192; i++) {
    if (get_bit_b(value_1, i) == 1) {
      s21_big temp = value_2;
      left_shift_b(&temp, i);
      s21_simple_add_b(*result, temp, result);
    }
  }
  return 0;
}
/***********************************/
/*************** DIV ***************/
/***********************************/

/**
 * @brief основная функция деления
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int code = CODE_OK;

  s21_big value_1_big = {0};
  s21_big value_2_big = {0};
  s21_big result_big = {0};

  initial_num(result);
  four_to_seven(&value_1_big, value_1);
  four_to_seven(&value_2_big, value_2);
  comp_and_norm_b(&value_1_big, &value_2_big);

  s21_big copy_value_2 = value_2_big;
  s21_big copy_value_1 = value_1_big;

  set_sign_b(&copy_value_1, 0);
  set_sign_b(&copy_value_2, 0);

  set_scale_b(&copy_value_1, 0);
  set_scale_b(&copy_value_2, 0);

  s21_big num_null = {0};

  s21_big num_one = {0};
  num_one.bits[0] = 1;

  if (s21_is_equal_b(num_null, copy_value_2))
    code = CODE_NAN;
  else if (s21_is_equal_b(num_null, copy_value_1))
    code = CODE_OK;
  else if (s21_is_equal_b(copy_value_1, copy_value_2))
    result_big.bits[0] = 1;
  else if (s21_is_equal_b(num_one, copy_value_2))
    result_big = value_1_big;
  else
    code = s21_simple_div(copy_value_1, copy_value_2, &result_big);

  int sign = get_sign(value_1) ^ get_sign(value_2);
  set_sign_b(&result_big, sign);
  if (code != CODE_NAN) code = errors(result_big, result);

  return code;
}
/**
 * @brief деление ТОЛЬКО чисел
 */
int s21_simple_div(s21_big value_1, s21_big value_2, s21_big *result) {
  int code = CODE_OK;
  s21_big copy_value_2 = value_2;
  s21_big copy_value_1 = value_1;
  s21_big num_null = {0};
  int scale = 0;
  int flag = 0;
  index_equalization(copy_value_1, &copy_value_2);
  while (!s21_is_equal_b(num_null, copy_value_1) && flag == 0) {
    if (s21_is_less_b(copy_value_1, value_2) &&
        !s21_is_equal_b(copy_value_1, num_null)) {
      ostatok(copy_value_1, value_2, result, &scale);
      flag = 1;
    } else {
      move_rigth_index(copy_value_1, &copy_value_2, result);
      sub_for_div(&copy_value_1, copy_value_2, result);
      removing_zeros(copy_value_1, &copy_value_2, value_2, result);
      flag = dividend_less_divisor(copy_value_1, value_2, &copy_value_2, result,
                                   &scale);
      if (!s21_is_equal_b(copy_value_2, value_2))
        right_shift_b(&copy_value_2, 1);
    }
  }
  set_scale_b(result, scale);
  return code;
}

/**
 * @brief вычисляет остаток от деления
 */
void ostatok(s21_big copy_value_1, s21_big value_2, s21_big *result,
             int *scale) {
  s21_big result_ostatok = {0};
  s21_big num_null = {0};
  s21_big copy_value_2 = value_2;
  s21_big value_1 = {0};
  while (s21_is_less_b(copy_value_1, value_2)) {
    *scale += 1;
    norm_b(&copy_value_1, 1);
    value_1 = copy_value_1;
  }
  while (!s21_is_equal_b(num_null, copy_value_1) && *scale <= 28) {
    move_rigth_index(copy_value_1, &copy_value_2, &result_ostatok);
    index_equalization(copy_value_1, &copy_value_2);
    sub_for_div(&copy_value_1, copy_value_2, &result_ostatok);
    removing_zeros(copy_value_1, &copy_value_2, value_2, &result_ostatok);
    add_scale(&copy_value_1, &value_1, value_2, &result_ostatok, scale);
    if (!s21_is_equal_b(copy_value_2, value_2)) right_shift_b(&copy_value_2, 1);
  }

  // *scale = -1;
  norm_b(result, *scale);
  s21_add_b(*result, result_ostatok, result);
}

/**
 * @brief если делимое меньше делителя, то уходит в остаток
 * возвращает: 1 - если остаток есть
 *             0 - если нет остатка
 */
int dividend_less_divisor(s21_big copy_value_1, s21_big value_2,
                          s21_big *copy_value_2, s21_big *result, int *scale) {
  s21_big num_null = {0};
  int code = 0;
  if (s21_is_less_b(copy_value_1, value_2) &&
      !s21_is_equal_b(copy_value_1, num_null)) {
    while (!s21_is_equal_b(*copy_value_2, value_2)) {
      right_shift_b(copy_value_2, 1);
      left_shift_b(result, 1);
    }
    ostatok(copy_value_1, value_2, result, scale);
    code = 1;
  }
  return code;
}
/**
 * @brief проводит вычитание и записывает в результат единицу
 */
void sub_for_div(s21_big *copy_value_1, s21_big copy_value_2, s21_big *result) {
  s21_sub_simple_b(*copy_value_1, copy_value_2, copy_value_1);
  left_shift_b(result, 1);
  set_bit_b(result, 0, 1);
}

/**
 * @brief двигаем индекс второго числа и в результат дописываем нули
 */
void move_rigth_index(s21_big copy_value_1, s21_big *copy_value_2,
                      s21_big *result) {
  while (s21_is_less_b(copy_value_1, *copy_value_2)) {
    right_shift_b(copy_value_2, 1);
    left_shift_b(result, 1);
  }
}
/**
 * @brief прибавляем скейл
 */
void add_scale(s21_big *copy_value_1, s21_big *value_1, s21_big value_2,
               s21_big *result_ostatok, int *scale) {
  s21_big num_null = {0};

  if (s21_is_less_b(*copy_value_1, value_2) &&
      !s21_is_equal_b(*copy_value_1, num_null)) {
    if (*scale < 28) {
      norm_b(value_1, 1);
      for (int i = 0; i < 7; i++) {
        copy_value_1->bits[i] = value_1->bits[i];
      }
      initial_num_b(result_ostatok);
    }
    *scale += 1;
  }
}
/**
 * @brief удаляет нули в конце
 */
void removing_zeros(s21_big copy_value_1, s21_big *copy_value_2,
                    s21_big value_2, s21_big *result) {
  s21_big num_null = {0};

  while (s21_is_equal_b(copy_value_1, num_null) &&
         !s21_is_equal_b(*copy_value_2, value_2)) {
    right_shift_b(copy_value_2, 1);
    left_shift_b(result, 1);
  }
}
/**
 * @brief уравнивает индексы
 */
void index_equalization(s21_big copy_value_1, s21_big *copy_value_2) {
  while (s21_is_less_or_equal_b(*copy_value_2, copy_value_1)) {
    left_shift_b(copy_value_2, 1);
    if (s21_is_less_b(copy_value_1, *copy_value_2)) {
      right_shift_b(copy_value_2, 1);
      break;
    }
  }
}
