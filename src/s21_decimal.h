#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_DECIMAL -79228162514264337593543950335.0F
#define MAX_DECIMAL 79228162514264337593543950335.0F

#define MIN_SCALE_DECIMAL \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

/*---------------------structs---------------------*/
typedef struct {
  unsigned int bits[7];
} s21_big;

typedef struct {
  unsigned int bits[4];
} s21_decimal;

enum code_error_convertors { CODE_TRUE, CODE_FALSE };
enum code_value_comparison { falsee, truee };  //возвращает 0 если
enum code_error_arithmetic { CODE_OK, CODE_PLUS_INF, CODE_MINUS_INF, CODE_NAN };

void print_decimal_b(s21_big value);
/*---------------------convert---------------------*/
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int incorrect_float(float src);
int exp_float(char str[500]);
void from_str_to_decimal(char str[500], s21_decimal *dst);
/*---------------------other---------------------*/
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_truncate_b(s21_big value, s21_big *result);

int s21_negate(s21_decimal value, s21_decimal *result);

/*----------------------------------------------------*/
/*---------------------arithmetic---------------------*/
/*----------------------------------------------------*/

/*---------------------add---------------------*/
int s21_add(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int zero_equal(s21_decimal value);
void s21_simple_add(s21_decimal value1, s21_decimal value2,
                    s21_decimal *result);
void s21_add_sign(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int s21_add_b(s21_big value1, s21_big value2, s21_big *result);
int zero_equal_b(s21_big value);
void s21_simple_add_b(s21_big value1, s21_big value2, s21_big *result);
void s21_add_sign_b(s21_big value1, s21_big value2, s21_big *result);

/*---------------------sub---------------------*/
int s21_sub(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int s21_sub_b(s21_big value1, s21_big value2, s21_big *result);

int s21_sub_simple(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
int s21_sub_simple_b(s21_big value_1, s21_big value_2, s21_big *result);
void s21_sub_sign(s21_big value_1, s21_big value_2, s21_big *result);
int s21_sub(s21_decimal value1, s21_decimal value2, s21_decimal *result);

/*---------------------mul---------------------*/
int s21_mul(s21_decimal value1, s21_decimal value2, s21_decimal *result);
int s21_mul_simple_b(s21_big value_1, s21_big value_2, s21_big *result);

/*---------------------div---------------------*/
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_simple_div(s21_big value_1, s21_big value_2, s21_big *result);
void ostatok(s21_big copy_value_1, s21_big value_2, s21_big *result,
             int *scale);
int dividend_less_divisor(s21_big copy_value_1, s21_big value_2,
                          s21_big *copy_value_2, s21_big *result, int *scale);
void sub_for_div(s21_big *copy_value_1, s21_big copy_value_2, s21_big *result);
void move_rigth_index(s21_big copy_value_1, s21_big *copy_value_2,
                      s21_big *result);
void add_scale(s21_big *copy_value_1, s21_big *value_1, s21_big value_2,
               s21_big *result_ostatok, int *scale);
void removing_zeros(s21_big copy_value_1, s21_big *copy_value_2,
                    s21_big value_2, s21_big *result);
void index_equalization(s21_big copy_value_1, s21_big *copy_value_2);

/*---------------------comparison---------------------*/
int s21_is_greater(s21_decimal value1, s21_decimal value2);
int s21_simple_greater(s21_decimal value1, s21_decimal value2);
int s21_greater_sign(s21_decimal value1, s21_decimal value2);

int s21_is_less(s21_decimal value1, s21_decimal value2);
int s21_simple_less(s21_decimal value1, s21_decimal value2);
int s21_less_sign(s21_decimal value1, s21_decimal value2);

int s21_is_equal(s21_decimal value1, s21_decimal value2);
int s21_simple_equal(s21_decimal value1, s21_decimal value2);
int s21_equal_sign(s21_decimal value1, s21_decimal value2);

int s21_is_greater_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_less_or_equal(s21_decimal value1, s21_decimal value2);
int s21_is_not_equal(s21_decimal value1, s21_decimal value2);

int s21_is_greater_b(s21_big value1, s21_big value2);
int s21_simple_greater_b(s21_big value1, s21_big value2);
int s21_greater_sign_b(s21_big value1, s21_big value2);

int s21_is_less_b(s21_big value1, s21_big value2);
int s21_simple_less_b(s21_big value1, s21_big value2);
int s21_less_sign_b(s21_big value1, s21_big value2);

int s21_is_equal_b(s21_big value1, s21_big value2);
int s21_simple_equal_b(s21_big value1, s21_big value2);
int s21_equal_sign_b(s21_big value1, s21_big value2);

int s21_is_greater_or_equal_b(s21_big value1, s21_big value2);
int s21_is_less_or_equal_b(s21_big value1, s21_big value2);
int s21_is_not_equal_b(s21_big value1, s21_big value2);

/*---------------------helper functions---------------------*/
int get_bit(s21_decimal value, int index);
int get_bit_b(s21_big value, int index);
void set_bit(s21_decimal *decimal, int index, int value);
void set_bit_b(s21_big *decimal, int index, int value);

int get_sign(s21_decimal value);
int get_sign_b(s21_big value);
void set_sign(s21_decimal *value, int sign);
void set_sign_b(s21_big *value, int sign);

int get_scale(s21_decimal value);
int get_scale_b(s21_big value);
void set_scale(s21_decimal *value, int scale);
void set_scale_b(s21_big *value, int scale);

void initial_num(s21_decimal *num);
void initial_num_b(s21_big *num);
void print_decimal(s21_decimal value);

void norm(s21_decimal *value, int diff_scl);
void norm_b(s21_big *value, int diff_scl);
void comp_and_norm(s21_decimal *scl1, s21_decimal *scl2);
void comp_and_norm_b(s21_big *scl1, s21_big *scl2);

void four_to_seven(s21_big *value_big, s21_decimal value_small);
int from_7_to_4_ints(s21_big *value, s21_decimal *result);

int is_overflow(s21_big *value);
int start_num_index(s21_decimal value);
int start_num_index_b(s21_big value);

void division_10(s21_decimal *temporary_max, int *max_scale, int *so_small_max);
void division_10_b(s21_big *temporary_max, int *max_scale, int *so_small_max);
int errors(s21_big result_b, s21_decimal *result);

void left_shift(s21_decimal *value, int position);
void right_shift(s21_decimal *value, int positions);
void left_shift_b(s21_big *value, int position);
void right_shift_b(s21_big *value, int positions);

int s21_bank_b(s21_big value, s21_big *result);

void print_decimal(s21_decimal value);

#endif
