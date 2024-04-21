#include "s21_decimal.h"
/*---------------------greater---------------------*/
/**
 * @brief функция знака > составная
 */
int s21_is_greater(s21_decimal value1, s21_decimal value2) {
  int code = truee;
  comp_and_norm(&value1, &value2);
  code = s21_greater_sign(value1, value2);
  return code;
}

/**
 * @brief функция знака > сравниваются числа
 */
int s21_simple_greater(s21_decimal value1, s21_decimal value2) {
  int code = truee;
  int block = 2;
  while (block > -1 && code == truee) {
    if (value1.bits[block] == value2.bits[block] && block != 0)
      block--;
    else if (value1.bits[block] > value2.bits[block])
      break;
    else {
      code = falsee;
    }
  }
  return code;
}

/**
 * @brief функция знака > сравниваются знаки
 */
int s21_greater_sign(s21_decimal value1, s21_decimal value2) {
  int code = truee;
  if (get_sign(value1) == 0 && get_sign(value2) == 1)
    code = s21_simple_greater(value1, value2);
  else if (get_sign(value1) == 1 && get_sign(value2) == 1) {
    if (s21_is_equal(value1, value2))
      code = falsee;
    else
      code = (!s21_simple_greater(value1, value2));
  } else if ((get_sign(value1)) != (get_sign(value2) == 1))
    code = (!get_sign(value1));
  else
    code = s21_simple_greater(value1, value2);

  return code;
}

/*---------------------less---------------------*/

/**
 * @brief функция знака < составная
 */
int s21_is_less(s21_decimal value1, s21_decimal value2) {
  int code = truee;
  comp_and_norm(&value1, &value2);
  code = s21_less_sign(value1, value2);
  return code;
}

/**
 * @brief функция знака < сравниваются числа
 */
int s21_simple_less(s21_decimal value1, s21_decimal value2) {
  int block = 2;
  int code = truee;
  while (block > -1 && code == truee) {
    if (value1.bits[block] == value2.bits[block] && block != 0) {
      block--;
    } else if (value1.bits[block] < value2.bits[block]) {
      break;
    } else {
      code = falsee;
    }
  }
  return code;
}

/**
 * @brief функция знака < сравниваются знаки
 */
int s21_less_sign(s21_decimal value1, s21_decimal value2) {
  int code;
  if (get_sign(value1) == 0 && get_sign(value2) == 0)
    code = s21_simple_less(value1, value2);
  else if (get_sign(value1) == 1 && get_sign(value2) == 1) {
    if (s21_is_equal(value1, value2)) {
      code = falsee;
    } else
      code = (!s21_simple_less(value1, value2));
  } else if ((get_sign(value1)) != (get_sign(value2)))
    code = (get_sign(value1));
  else {
    code = s21_simple_less(value1, value2);
  }
  return code;
}

/*---------------------equal---------------------*/

/**
 * @brief функция знака = составная
 */
int s21_is_equal(s21_decimal value1, s21_decimal value2) {
  int code = truee;
  comp_and_norm(&value1, &value2);
  code = s21_equal_sign(value1, value2);
  return code;
}

/**
 * @brief функция знака = сравниваются числа
 */
int s21_simple_equal(s21_decimal value1, s21_decimal value2) {
  int code = truee;
  int block = 2;
  if (get_scale(value1) == get_scale(value2)) code = truee;
  while (block > -1 && code == truee) {
    if (value1.bits[block] != value2.bits[block]) code = falsee;
    block--;
  }
  return code;
}

/**
 * @brief функция знака = сравниваются знаки
 */
int s21_equal_sign(s21_decimal value1, s21_decimal value2) {
  int code;
  if (get_sign(value1) == 0 && get_sign(value2) == 0)
    code = s21_simple_equal(value1, value2);
  else if (get_sign(value1) == 1 && get_sign(value2) == 1)
    code = s21_simple_equal(value1, value2);
  else if ((get_sign(value1)) != (get_sign(value2)))
    code = falsee;
  return code;
}

/*---------------------greater_or_equal---------------------*/
int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2) {
  int code = truee;
  code = (!s21_is_less(value1, value2));
  return code;
}

/*---------------------less_or_equal---------------------*/
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2) {  // п
  int code = truee;
  code = (!s21_is_greater(value1, value2));
  return code;
}

/*---------------------not-equal---------------------*/
int s21_is_not_equal(s21_decimal value1, s21_decimal value2) {
  comp_and_norm(&value1, &value2);
  int code = truee;
  int block = 2;
  while (block > -1 && code == truee) {
    if (s21_is_equal(value1, value2) == falsee)
      code = truee;
    else
      code = falsee;
    block--;
  }
  return code;
}
/***********************************/
/**************** 7 ****************/
/***********************************/

/*---------------------greater---------------------*/
/**
 * @brief функция знака > составная
 */
int s21_is_greater_b(s21_big value1, s21_big value2) {
  int code = truee;
  comp_and_norm_b(&value1, &value2);
  code = s21_greater_sign_b(value1, value2);
  return code;
}

/**
 * @brief функция знака > сравниваются числа
 */
int s21_simple_greater_b(s21_big value1, s21_big value2) {
  int code = truee;
  int block = 5;
  if (get_sign_b(value1) == 1 && get_sign_b(value2) == 1) {
  }
  while (block > -1 && code == truee) {
    if (value1.bits[block] == value2.bits[block] && block != 0) {
      block--;
    } else if (value1.bits[block] > value2.bits[block]) {
      break;
    } else {
      code = falsee;
    }
  }
  return code;
}

/**
 * @brief функция знака > сравниваются знаки
 */
int s21_greater_sign_b(s21_big value1, s21_big value2) {
  int code = truee;
  if (get_sign_b(value1) == 0 && get_sign_b(value2) == 1) {
    code = s21_simple_greater_b(value1, value2);
    code = truee;
  } else if (get_sign_b(value1) == 1 && get_sign_b(value2) == 1) {
    if (s21_is_equal_b(value1, value2))
      code = falsee;
    else
      code = (!s21_simple_greater_b(value1, value2));
  } else if ((get_sign_b(value1)) != (get_sign_b(value2) == 1))
    code = !get_sign_b(value1);

  else
    code = s21_simple_greater_b(value1, value2);

  return code;
}

/*---------------------less---------------------*/

/**
 * @brief функция знака < составная
 */
int s21_is_less_b(s21_big value1, s21_big value2) {
  int code = truee;
  comp_and_norm_b(&value1, &value2);
  code = s21_less_sign_b(value1, value2);
  return code;
}

/**
 * @brief функция знака < сравниваются числа
 */
int s21_simple_less_b(s21_big value1, s21_big value2) {
  int block = 5;
  int code = truee;
  while (block > -1 && code == truee) {
    if (value1.bits[block] == value2.bits[block] && block != 0) {
      block--;
    } else if (value1.bits[block] < value2.bits[block]) {
      break;
    } else {
      code = falsee;
    }
  }
  return code;
}

/**
 * @brief функция знака < сравниваются знаки
 */
int s21_less_sign_b(s21_big value1, s21_big value2) {
  int code;
  if (get_sign_b(value1) == 0 && get_sign_b(value2) == 0)
    code = s21_simple_less_b(value1, value2);
  else if (get_sign_b(value1) == 1 && get_sign_b(value2) == 1) {
    if (s21_is_equal_b(value1, value2)) {
      code = falsee;
    } else
      code = (!s21_simple_less_b(value1, value2));
  } else if ((get_sign_b(value1)) != (get_sign_b(value2)))
    code = (get_sign_b(value1));
  else {
    code = s21_simple_less_b(value1, value2);
  }
  return code;
}

/*---------------------equal---------------------*/

/**
 * @brief функция знака = составная
 */
int s21_is_equal_b(s21_big value1, s21_big value2) {
  int code = truee;
  comp_and_norm_b(&value1, &value2);
  code = s21_equal_sign_b(value1, value2);
  return code;
}

/**
 * @brief функция знака = сравниваются числа
 */
int s21_simple_equal_b(s21_big value1, s21_big value2) {
  int code = truee;
  int block = 5;
  if (get_scale_b(value1) == get_scale_b(value2)) code = truee;
  while (block > -1 && code == truee) {
    if (value1.bits[block] != value2.bits[block]) code = falsee;
    block--;
  }
  return code;
}

/**
 * @brief функция знака = сравниваются знаки
 */
int s21_equal_sign_b(s21_big value1, s21_big value2) {
  int code;
  if (get_sign_b(value1) == 0 && get_sign_b(value2) == 0)
    code = s21_simple_equal_b(value1, value2);
  else if (get_sign_b(value1) == 1 && get_sign_b(value2) == 1)
    code = s21_simple_equal_b(value1, value2);
  else if ((get_sign_b(value1)) != (get_sign_b(value2)))
    code = falsee;
  return code;
}

/*---------------------greater_or_equal---------------------*/
int s21_is_greater_or_equal_b(s21_big value1, s21_big value2) {
  int code = truee;
  code = (!s21_is_less_b(value1, value2));
  return code;
}

/*---------------------less_or_equal---------------------*/
int s21_is_less_or_equal_b(s21_big value1, s21_big value2) {  // п
  int code = truee;
  code = (!s21_is_greater_b(value1, value2));
  return code;
}

/*---------------------not-equal---------------------*/
int s21_is_not_equal_b(s21_big value1, s21_big value2) {
  comp_and_norm_b(&value1, &value2);
  int code = truee;
  int block = 5;
  while (block > -1 && code == truee) {
    if (s21_is_equal_b(value1, value2) == falsee)
      code = truee;
    else
      code = falsee;
    block--;
  }
  return code;
}
