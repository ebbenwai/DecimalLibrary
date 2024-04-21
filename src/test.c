#include <check.h>

#include "s21_decimal.h"

/***********************************/
/************* GREATER *************/
/***********************************/

START_TEST(test_s21_greater) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};

  set_sign(&value1, 1);
  set_sign(&value2, 0);

  set_scale(&value1, 6);
  set_scale(&value2, 6);

  s21_decimal value3 = {{1, 2, 3, 0}};
  s21_decimal value4 = {{21, 21, 21, 0}};

  set_sign(&value3, 1);
  set_sign(&value4, 1);

  s21_decimal value5 = {{21, 21, 21, 0}};
  s21_decimal value6 = {{42, 42, 42, 0}};

  set_sign(&value5, 0);
  set_sign(&value6, 0);

  s21_decimal value7 = {{7, 10, 9, 0}};
  s21_decimal value8 = {{25, 25, 25, 0}};
  set_scale(&value7, 1);
  set_scale(&value8, 1);

  s21_decimal value9 = {{0, 0, 0, 0}};
  s21_decimal value10 = {{0, 0, 0, 0}};

  ck_assert_int_eq(0, s21_is_greater(value1, value2));
  ck_assert_int_eq(1, s21_is_greater(value3, value4));
  ck_assert_int_eq(0, s21_is_greater(value5, value6));
  ck_assert_int_eq(0, s21_is_greater(value7, value8));
  ck_assert_int_eq(0, s21_is_greater(value9, value10));
}
END_TEST;

Suite *s21_test_greater() {
  Suite *result;
  TCase *tc_greater;

  result = suite_create("s21_greater");
  tc_greater = tcase_create("s21_greater");

  tcase_add_test(tc_greater, test_s21_greater);
  suite_add_tcase(result, tc_greater);

  return result;
}
/***********************************/
/************* LESS *************/
/***********************************/

START_TEST(test_s21_less) {
  s21_decimal value1 = {{0, 0, 0, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};

  set_sign(&value1, 0);
  set_sign(&value2, 0);

  s21_decimal value3 = {{1, 1, 100, 0}};
  s21_decimal value4 = {{21, 21, 21, 0}};
  set_sign(&value3, 1);
  set_sign(&value4, 0);

  set_scale(&value3, 2);
  set_scale(&value4, 1);

  s21_decimal value5 = {{21, 21, 21, 0}};
  s21_decimal value6 = {{42, 42, 42, 0}};
  set_sign(&value5, 1);
  set_sign(&value6, 1);

  s21_decimal value7 = {{0, 0, 0, 0}};
  s21_decimal value8 = {{0, 0, 0, 0}};

  s21_decimal value9 = {{5, 5, 0, 0}};
  s21_decimal value10 = {{7, 25, 0, 0}};
  set_sign(&value9, 0);
  set_sign(&value10, 1);

  ck_assert_int_eq(0, s21_is_less(value1, value2));
  ck_assert_int_eq(1, s21_is_less(value3, value4));
  ck_assert_int_eq(0, s21_is_less(value5, value6));
  ck_assert_int_eq(0, s21_is_less(value7, value8));
  ck_assert_int_eq(0, s21_is_less(value9, value10));
}
END_TEST;

Suite *s21_test_less() {
  Suite *result;
  TCase *tc_less;

  result = suite_create("s21_less");
  tc_less = tcase_create("s21_less");

  tcase_add_test(tc_less, test_s21_less);
  suite_add_tcase(result, tc_less);

  return result;
}

/***********************************/
/************* LESS BIG ************/
/***********************************/

START_TEST(test_s21_less_BIG) {
  s21_big value1 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big value2 = {{0, 0, 0, 0, 0, 0, 0}};

  set_sign_b(&value1, 0);
  set_sign_b(&value2, 0);

  s21_big value3 = {{1, 1, 100, 0, 0, 0, 0}};
  s21_big value4 = {{21, 21, 21, 0, 0, 0, 0}};
  set_sign_b(&value3, 1);
  set_sign_b(&value4, 0);

  set_scale_b(&value3, 2);
  set_scale_b(&value4, 1);

  s21_big value5 = {{21, 21, 21, 0, 0, 0, 0}};
  s21_big value6 = {{42, 42, 42, 0, 0, 0, 0}};
  set_sign_b(&value5, 1);
  set_sign_b(&value6, 1);

  s21_big value7 = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big value8 = {{0, 0, 0, 0, 0, 0, 0}};

  s21_big value9 = {{5, 5, 0, 0, 0, 0, 0}};
  s21_big value10 = {{7, 25, 0, 0, 0, 0, 0}};
  set_sign_b(&value9, 0);
  set_sign_b(&value10, 1);

  ck_assert_int_eq(0, s21_is_less_b(value1, value2));
  ck_assert_int_eq(1, s21_is_less_b(value3, value4));
  ck_assert_int_eq(0, s21_is_less_b(value5, value6));
  ck_assert_int_eq(0, s21_is_less_b(value7, value8));
  ck_assert_int_eq(0, s21_is_less_b(value9, value10));
}
END_TEST;

Suite *s21_test_less_BIG() {
  Suite *result;
  TCase *tc_less;

  result = suite_create("s21_less_BIG");
  tc_less = tcase_create("s21_less_BIG");

  tcase_add_test(tc_less, test_s21_less_BIG);
  suite_add_tcase(result, tc_less);
  return result;
}

/***********************************/
/************** EQUAL **************/
/***********************************/
START_TEST(test_s21_equal) {
  s21_decimal value1 = {{0, 1, 0, 0}};
  s21_decimal value2 = {{0, 1, 0, 0}};
  set_sign(&value1, 1);
  set_sign(&value2, 1);

  set_scale(&value1, 1);
  set_scale(&value2, 1);

  s21_decimal value3 = {{1, 1, 1, 0}};
  s21_decimal value4 = {{1, 1, 1, 0}};
  set_sign(&value3, 1);
  set_sign(&value4, 0);

  s21_decimal value5 = {{21, 21, 21, 0}};
  s21_decimal value6 = {{21, 21, 21, 0}};
  set_sign(&value5, 1);
  set_sign(&value6, 1);

  set_scale(&value5, 1);
  set_scale(&value6, 2);

  s21_decimal value7 = {{0, 0, 0, 0}};
  s21_decimal value8 = {{0, 0, 0, 0}};

  s21_decimal value9 = {{5, 5, 0, 0}};
  s21_decimal value10 = {{5, 5, 0, 0}};
  set_scale(&value9, 1);
  set_scale(&value10, 0);

  ck_assert_int_eq(1, s21_is_equal(value1, value2));
  ck_assert_int_eq(0, s21_is_equal(value3, value4));
  ck_assert_int_eq(0, s21_is_equal(value5, value6));
  ck_assert_int_eq(1, s21_is_equal(value7, value8));
  ck_assert_int_eq(0, s21_is_equal(value9, value10));
}
END_TEST;

Suite *s21_test_equal() {
  Suite *result;
  TCase *tc_equal;

  result = suite_create("s21_equal");
  tc_equal = tcase_create("s21_equal");

  tcase_add_test(tc_equal, test_s21_equal);
  suite_add_tcase(result, tc_equal);

  return result;
}

/***********************************/
/******** GREATER OR EQUAL *********/
/***********************************/
START_TEST(test_greater_or_equal) {
  s21_decimal value1 = {{2, 2, 2, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};

  s21_decimal value3 = {{1, 1, 1, 0}};
  s21_decimal value4 = {{2, 2, 2, 0}};
  set_scale(&value3, 1);
  set_scale(&value4, 3);

  s21_decimal value5 = {{21, 21, 21, 0}};  //!!!1!
  s21_decimal value6 = {{21, 21, 21, 0}};
  set_sign(&value5, 1);
  set_sign(&value6, 1);

  s21_decimal value7 = {{2, 2, 2, 0}};
  s21_decimal value8 = {{2, 2, 2, 0}};
  set_sign(&value7, 1);
  set_sign(&value8, 1);

  s21_decimal value9 = {{0, 5, 0, 0}};
  s21_decimal value10 = {{99, 5, 0, 0}};

  ck_assert_int_eq(1, s21_is_greater_or_equal(value1, value2));
  ck_assert_int_eq(1, s21_is_greater_or_equal(value3, value4));
  ck_assert_int_eq(1, s21_is_greater_or_equal(value5, value6));
  ck_assert_int_eq(1, s21_is_greater_or_equal(value7, value8));
  ck_assert_int_eq(0, s21_is_greater_or_equal(value9, value10));
}
END_TEST;

Suite *test_s21_test_is_greater_or_equal() {
  Suite *result;
  TCase *tc_greater_or_equal;

  result = suite_create("s21_greater_or_equal");
  tc_greater_or_equal = tcase_create("s21_greater_or_equal");

  tcase_add_test(tc_greater_or_equal, test_greater_or_equal);
  suite_add_tcase(result, tc_greater_or_equal);

  return result;
}

/***********************************/
/********** LESS OR EQUAL **********/
/***********************************/
START_TEST(test_less_or_equal) {
  s21_decimal value1 = {{2, 2, 2, 0}};
  s21_decimal value2 = {{0, 0, 0, 0}};

  s21_decimal value3 = {{1, 1, 1, 0}};
  s21_decimal value4 = {{2, 2, 2, 0}};
  set_scale(&value3, 1);
  set_scale(&value4, 3);

  s21_decimal value5 = {{21, 21, 21, 0}};  //!!!1!
  s21_decimal value6 = {{21, 21, 21, 0}};
  set_sign(&value5, 1);
  set_sign(&value6, 1);

  s21_decimal value7 = {{0, 2, 0, 0}};
  s21_decimal value8 = {{2, 2, 2, 2}};
  set_sign(&value7, 0);
  set_sign(&value8, 0);

  s21_decimal value9 = {{0, 5, 0, 0}};
  s21_decimal value10 = {{99, 5, 0}};

  ck_assert_int_eq(0, s21_is_less_or_equal(value1, value2));
  ck_assert_int_eq(0, s21_is_less_or_equal(value3, value4));
  ck_assert_int_eq(1, s21_is_less_or_equal(value5, value6));
  ck_assert_int_eq(1, s21_is_less_or_equal(value7, value8));
  ck_assert_int_eq(1, s21_is_less_or_equal(value9, value10));
}
END_TEST;

Suite *test_s21_test_is_less_or_equal() {
  Suite *result;
  TCase *tc_less_or_equal;

  result = suite_create("s21_less_or_equal");
  tc_less_or_equal = tcase_create("s21_less_or_equal");

  tcase_add_test(tc_less_or_equal, test_less_or_equal);
  suite_add_tcase(result, tc_less_or_equal);

  return result;
}

/***********************************/
/************ NOT EQUAL ************/
/***********************************/
START_TEST(test_is_not_equal) {
  s21_decimal value1 = {{2, 2, 2, 0}};
  s21_decimal value2 = {{2, 2, 2, 0}};

  s21_decimal value3 = {{1, 1, 1, 0}};
  s21_decimal value4 = {{2, 2, 2, 0}};

  s21_decimal value5 = {{21, 21, 21, 0}};  //!!!1!
  s21_decimal value6 = {{21, 21, 21, 0}};
  set_sign(&value5, 0);
  set_sign(&value6, 1);

  s21_decimal value7 = {{21, 21, 21, 0}};
  s21_decimal value8 = {{21, 21, 21, 0}};
  set_scale(&value7, 0);
  set_scale(&value8, 2);

  s21_decimal value9 = {{0, 5, 0, 0}};
  s21_decimal value10 = {{99, 5, 0, 0}};

  ck_assert_int_eq(0, s21_is_not_equal(value1, value2));
  ck_assert_int_eq(1, s21_is_not_equal(value3, value4));
  ck_assert_int_eq(1, s21_is_not_equal(value5, value6));
  ck_assert_int_eq(1, s21_is_not_equal(value7, value8));
  ck_assert_int_eq(1, s21_is_not_equal(value9, value10));
}
END_TEST;
Suite *test_s21_test_is_not_equal() {
  Suite *result;
  TCase *tc_is_not_equal;

  result = suite_create("s21_is_not_equal");
  tc_is_not_equal = tcase_create("s21_is_not_equal");

  tcase_add_test(tc_is_not_equal, test_is_not_equal);
  suite_add_tcase(result, tc_is_not_equal);

  return result;
}

/***********************************/
/********** NOT EQUAL BIG **********/
/***********************************/
START_TEST(test_is_not_equal_BIG) {
  s21_big value1 = {{2, 2, 2, 0, 0, 0, 0}};
  s21_big value2 = {{2, 2, 2, 0, 0, 0, 0}};

  s21_big value3 = {{1, 1, 1, 0, 0, 0, 0}};
  s21_big value4 = {{2, 2, 2, 0, 0, 0, 0}};

  s21_big value5 = {{21, 21, 21, 0, 0, 0, 0}};  //!!!1!
  s21_big value6 = {{21, 21, 21, 0, 0, 0, 0}};
  set_sign_b(&value5, 0);
  set_sign_b(&value6, 1);

  s21_big value7 = {{21, 21, 21, 0, 0, 0, 0}};
  s21_big value8 = {{21, 21, 21, 0, 0, 0, 0}};
  set_scale_b(&value7, 0);
  set_scale_b(&value8, 2);

  s21_big value9 = {{0, 5, 0, 0, 0, 0, 0}};
  s21_big value10 = {{99, 5, 0, 0, 0, 0, 0}};

  ck_assert_int_eq(0, s21_is_not_equal_b(value1, value2));
  ck_assert_int_eq(1, s21_is_not_equal_b(value3, value4));
  ck_assert_int_eq(1, s21_is_not_equal_b(value5, value6));
  ck_assert_int_eq(1, s21_is_not_equal_b(value7, value8));
  ck_assert_int_eq(1, s21_is_not_equal_b(value9, value10));
}
END_TEST;
Suite *test_s21_test_is_not_equal_BIG() {
  Suite *result;
  TCase *tc_is_not_equal_BIG;

  result = suite_create("test_is_not_equal_BIG)");
  tc_is_not_equal_BIG = tcase_create("test_is_not_equal_BIG)");

  tcase_add_test(tc_is_not_equal_BIG, test_is_not_equal_BIG);
  suite_add_tcase(result, tc_is_not_equal_BIG);

  return result;
}

/***********************************/
/*************** ADD ***************/
/***********************************/
START_TEST(test_add1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 0b1001100010010110100000;
  value_2.bits[0] = 0b1001100010010110100000;

  s21_decimal final_result = {0};

  result.bits[0] = 0b10011000100101101000000;
  s21_add(value_1, value_2, &final_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], final_result.bits[i]);
  }
}
END_TEST;
START_TEST(test_add2) {
  s21_decimal value_3 = {{20, 25, 1, 0}};
  s21_decimal value_4 = {{25, 60, 1, 0}};
  s21_decimal final_result = {0};

  s21_decimal result = {{45, 85, 2, 0}};

  set_sign(&value_3, 0);
  set_sign(&value_4, 0);

  s21_add(value_3, value_4, &final_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], final_result.bits[i]);
  }
}
END_TEST;

START_TEST(test_add3) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{20, 0, 0, 0}};
  s21_decimal final_result = {0};

  s21_decimal result = {{18, 0, 0, 0}};

  set_sign(&value_1, 1);
  set_sign(&value_2, 0);

  s21_add(value_1, value_2, &final_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], final_result.bits[i]);
  }
}
END_TEST;

START_TEST(test_add4) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal final_result = {{0, 0, 0, 0}};

  s21_decimal result = {{4, 0, 0, 0}};
  set_sign(&result, 1);

  set_sign(&value_1, 1);
  set_sign(&value_2, 1);

  s21_add(value_1, value_2, &final_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], final_result.bits[i]);
  }
}
END_TEST;

START_TEST(test_add5) {
  s21_decimal value_1 = {{0, 0, 0, 0}};
  s21_decimal value_2 = {{2, 0, 0, 0}};
  s21_decimal final_result = {{0, 0, 0, 0}};

  s21_decimal result = {{2, 0, 0, 0}};

  set_sign(&value_1, 0);
  set_sign(&value_2, 0);

  s21_add(value_1, value_2, &final_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], final_result.bits[i]);
  }
}
END_TEST;

START_TEST(test_add6) {
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{0, 0, 0, 0}};
  s21_decimal final_result = {{0, 0, 0, 0}};

  s21_decimal result = {{2, 0, 0, 0}};

  set_sign(&value_1, 0);
  set_sign(&value_2, 0);

  s21_add(value_1, value_2, &final_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], final_result.bits[i]);
  }
}
END_TEST;

START_TEST(test_add7) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal final_result = {{0, 0, 0, 0}};

  s21_add(value_1, value_2, &final_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(1, s21_add(value_1, value_2, &final_result));
  }
}
END_TEST;

START_TEST(test_add8) {
  s21_decimal value_1 = {{1, 0, 0, 0}};
  s21_decimal value_2 = {{1, 0, 0, 0}};
  s21_decimal result = {{2, 0, 0, 0}};
  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  set_sign(&result, 1);

  s21_decimal final_result = {0};

  s21_add(value_1, value_2, &final_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], final_result.bits[i]);
  }
}
END_TEST;

Suite *s21_test_add() {
  Suite *result;
  TCase *tc_add;

  result = suite_create("s21_add");
  tc_add = tcase_create("s21_add");

  tcase_add_test(tc_add, test_add1);
  tcase_add_test(tc_add, test_add2);
  tcase_add_test(tc_add, test_add3);
  tcase_add_test(tc_add, test_add4);
  tcase_add_test(tc_add, test_add5);
  tcase_add_test(tc_add, test_add6);
  tcase_add_test(tc_add, test_add7);
  tcase_add_test(tc_add, test_add8);
  suite_add_tcase(result, tc_add);
  return result;
}

/***********************************/
/*************** SUB ***************/
/***********************************/

START_TEST(sub_test1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 2;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};
  result.bits[0] = 0;

  s21_sub(value_1, value_2, &my_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 6;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};
  result.bits[0] = 4;
  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 8;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};

  result.bits[0] = 6;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 10;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};

  result.bits[0] = 8;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 12;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};

  result.bits[0] = 10;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 20;
  value_2.bits[0] = 500;

  s21_decimal my_result = {0};

  set_scale(&value_1, 0);
  set_scale(&value_2, 2);

  set_sign(&value_1, 1);
  set_sign(&value_2, 1);

  set_sign(&result, 1);
  set_scale(&result, 2);
  result.bits[0] = 1500;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 9;
  value_2.bits[0] = 22;

  s21_decimal my_result = {0};

  set_sign(&value_1, 1);
  set_sign(&value_2, 0);

  set_sign(&result, 1);
  result.bits[0] = 31;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 5;
  value_2.bits[0] = 6;

  s21_decimal my_result = {0};

  set_sign(&value_1, 1);
  set_sign(&value_2, 1);

  result.bits[0] = 1;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 5;
  value_2.bits[0] = 4;

  s21_decimal my_result = {0};

  set_sign(&value_1, 0);
  set_sign(&value_2, 1);

  result.bits[0] = 9;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test10) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 73;
  value_2.bits[0] = 9;

  s21_decimal my_result = {0};

  set_sign(&value_1, 1);
  set_sign(&value_2, 0);

  set_sign(&result, 1);

  result.bits[0] = 82;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 9;
  value_2.bits[0] = 6;

  s21_decimal my_result = {0};

  set_sign(&value_1, 1);
  set_sign(&value_2, 1);

  set_sign(&result, 1);

  result.bits[0] = 3;
  s21_sub(value_1, value_2, &my_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(sub_test12) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 7984;
  value_2.bits[0] = 7482;

  s21_decimal my_result = {0};

  result.bits[0] = 502;

  s21_sub(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(sub_test13) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  set_sign(&value_2, 1);

  s21_decimal my_result = {0};

  ck_assert_int_eq(1, s21_sub(value_1, value_2, &my_result));
}
END_TEST;

START_TEST(sub_test14) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  set_sign(&value_1, 1);
  set_sign(&value_2, 0);

  s21_decimal my_result = {0};

  ck_assert_int_eq(2, s21_sub(value_1, value_2, &my_result));
}
END_TEST;

Suite *s21_sub_test() {
  Suite *result;
  TCase *tc_sub_test;

  result = suite_create("SUB");
  tc_sub_test = tcase_create("SUB");

  tcase_add_test(tc_sub_test, sub_test1);
  tcase_add_test(tc_sub_test, sub_test2);
  tcase_add_test(tc_sub_test, sub_test3);
  tcase_add_test(tc_sub_test, sub_test4);
  tcase_add_test(tc_sub_test, sub_test5);
  tcase_add_test(tc_sub_test, sub_test6);
  tcase_add_test(tc_sub_test, sub_test7);
  tcase_add_test(tc_sub_test, sub_test8);
  tcase_add_test(tc_sub_test, sub_test9);
  tcase_add_test(tc_sub_test, sub_test10);
  tcase_add_test(tc_sub_test, sub_test11);
  tcase_add_test(tc_sub_test, sub_test12);
  tcase_add_test(tc_sub_test, sub_test13);
  tcase_add_test(tc_sub_test, sub_test14);

  suite_add_tcase(result, tc_sub_test);
  return result;
}

/***********************************/
/*************** MUL ***************/
/***********************************/
START_TEST(mul_test0) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal my_result = {0};
  ck_assert_int_eq(1, s21_mul(value_1, value_2, &my_result));
}
END_TEST;

START_TEST(mul_test1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 2;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};
  result.bits[0] = 4;
  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 6;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};
  result.bits[0] = 12;
  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 8;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};

  result.bits[0] = 16;
  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 10;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};
  result.bits[0] = 20;
  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 12;
  value_2.bits[0] = 2;

  s21_decimal my_result = {0};
  result.bits[0] = 24;
  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 999;
  value_2.bits[0] = 666;

  s21_decimal my_result = {0};
  set_scale(&value_1, 1);
  set_scale(&value_2, 0);
  set_scale(&result, 1);
  result.bits[0] = 665334;

  s21_mul(value_1, value_2, &my_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 12345;
  value_2.bits[0] = 54321;

  s21_decimal my_result = {0};

  set_sign(&value_1, 1);
  set_sign(&value_2, 1);
  set_sign(&result, 0);

  result.bits[0] = 670592745;

  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 1001;
  value_2.bits[0] = 1000;

  s21_decimal my_result = {0};

  set_sign(&value_1, 1);
  set_sign(&value_2, 1);

  result.bits[0] = 1001000;

  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 5;
  value_2.bits[0] = 4;

  s21_decimal my_result = {0};

  set_sign(&value_1, 0);
  set_sign(&value_2, 1);

  set_sign(&result, 1);
  result.bits[0] = 20;
  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test10) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 73;
  value_2.bits[0] = 9;

  s21_decimal my_result = {0};

  set_scale(&value_1, 2);
  set_scale(&value_2, 0);

  result.bits[0] = 657;
  set_scale(&result, 2);

  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 982;
  value_2.bits[0] = 52;

  s21_decimal my_result = {0};

  set_scale(&value_1, 1);
  set_scale(&value_2, 1);

  result.bits[0] = 51064;
  set_scale(&result, 2);
  s21_mul(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(mul_test12) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};

  s21_decimal my_result = {0};
  set_sign(&value_1, 1);
  ck_assert_int_eq(2, s21_mul(value_1, value_2, &my_result));
}
END_TEST;

Suite *s21_mul_test() {
  Suite *result;
  TCase *tc_mul_test;

  result = suite_create("mul");
  tc_mul_test = tcase_create("mul");

  tcase_add_test(tc_mul_test, mul_test0);
  tcase_add_test(tc_mul_test, mul_test1);
  tcase_add_test(tc_mul_test, mul_test2);
  tcase_add_test(tc_mul_test, mul_test3);
  tcase_add_test(tc_mul_test, mul_test4);
  tcase_add_test(tc_mul_test, mul_test5);
  tcase_add_test(tc_mul_test, mul_test6);
  tcase_add_test(tc_mul_test, mul_test7);
  tcase_add_test(tc_mul_test, mul_test8);
  tcase_add_test(tc_mul_test, mul_test9);
  tcase_add_test(tc_mul_test, mul_test10);
  tcase_add_test(tc_mul_test, mul_test11);
  tcase_add_test(tc_mul_test, mul_test12);

  suite_add_tcase(result, tc_mul_test);
  return result;
}

/***********************************/
/*************** DIV ***************/
/***********************************/
START_TEST(div_test1) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 193700;
  value_2.bits[0] = 20;

  s21_decimal my_result = {0};
  result.bits[0] = 9685;
  s21_div(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test2) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};

  // value_1 = 516905600732083827(10)
  // 11100101100011010101110011110111010000010111011011001110011(2) value_2 =
  // 654321654321(10)  1001100001011000100111000001101000110001(2)
  value_1.bits[0] = 0b10111010000010111011011001110011;
  value_1.bits[1] = 0b111001011000110101011100111;
  value_2.bits[0] = 0b01011000100111000001101000110001;
  value_2.bits[1] = 0b10011000;

  s21_decimal my_result = {0};

  // result = 789987(10)   11000000110111100011(2)
  result.bits[0] = 0b11000000110111100011;

  s21_div(value_1, value_2, &my_result);
  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test3) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal my_result = {0};
  set_sign(&value_1, 1);
  value_1.bits[0] = 0b00000000000000000011000000001100;
  value_1.bits[1] = 0b1;
  value_2.bits[0] = 0b10100000000000000000000000000000;

  result.bits[0] = 0b11111100100000100100101000101011;
  result.bits[1] = 0b00110010000000110100000110101011;
  result.bits[2] = 0b101001010110111111000100110;

  set_scale(&result, 27);
  set_sign(&result, 1);

  s21_div(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test4) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal my_result = {0};

  value_1.bits[0] = 5;
  value_2.bits[0] = 2;

  result.bits[0] = 25;
  set_scale(&result, 1);

  s21_div(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test5) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal my_result = {0};

  value_1.bits[0] = 3;
  value_2.bits[0] = 2;

  result.bits[0] = 15;
  set_scale(&result, 1);

  s21_div(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test6) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal my_result = {0};

  value_1.bits[0] = 9;
  value_2.bits[0] = 1000000000;

  result.bits[0] = 9;
  set_scale(&result, 9);

  s21_div(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test7) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal my_result = {0};

  value_1.bits[0] = 8;
  value_2.bits[0] = 2;

  result.bits[0] = 4;

  s21_div(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test8) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal my_result = {0};

  value_1.bits[0] = 1234567;
  value_2.bits[0] = 0;

  ck_assert_int_eq(s21_div(value_1, value_2, &my_result), CODE_NAN);
}
END_TEST;

START_TEST(div_test9) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal my_result = {0};

  value_1.bits[0] = 0;
  value_2.bits[0] = 123456;

  s21_div(value_1, value_2, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test10) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal my_result = {0};

  value_1.bits[0] = 0b10111010000010111011011001110011;
  value_1.bits[1] = 0b111001011000110101011100111;

  value_2.bits[0] = 0b10111010000010111011011001110011;
  value_2.bits[1] = 0b111001011000110101011100111;

  s21_div(value_1, value_2, &my_result);

  result.bits[0] = 1;

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test11) {
  s21_decimal value_1 = {0};
  s21_decimal value_2 = {0};
  s21_decimal result = {0};
  s21_decimal my_result = {0};

  value_1.bits[0] = 0b10111010000010111011011001110011;
  value_1.bits[1] = 0b111001011000110101011100111;

  value_2.bits[0] = 1;

  s21_div(value_1, value_2, &my_result);

  result.bits[0] = 0b10111010000010111011011001110011;
  result.bits[1] = 0b111001011000110101011100111;

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(div_test12) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {0};
  s21_decimal my_result = {0};

  value_2.bits[0] = 8;
  set_scale(&value_2, 2);

  ck_assert_int_eq(s21_div(value_1, value_2, &my_result), 1);
}
END_TEST;

START_TEST(div_test13) {
  s21_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  s21_decimal value_2 = {0};
  s21_decimal my_result = {0};

  set_sign(&value_2, 1);
  value_2.bits[0] = 8;
  set_scale(&value_2, 2);

  ck_assert_int_eq(s21_div(value_1, value_2, &my_result), 2);
}
END_TEST;

Suite *s21_div_test() {
  Suite *result;
  TCase *tc_div_test;

  result = suite_create("div");
  tc_div_test = tcase_create("div");

  tcase_add_test(tc_div_test, div_test1);
  tcase_add_test(tc_div_test, div_test2);
  tcase_add_test(tc_div_test, div_test3);
  tcase_add_test(tc_div_test, div_test4);
  tcase_add_test(tc_div_test, div_test5);
  tcase_add_test(tc_div_test, div_test6);
  tcase_add_test(tc_div_test, div_test7);
  tcase_add_test(tc_div_test, div_test8);
  tcase_add_test(tc_div_test, div_test9);
  tcase_add_test(tc_div_test, div_test10);
  tcase_add_test(tc_div_test, div_test11);
  tcase_add_test(tc_div_test, div_test12);
  tcase_add_test(tc_div_test, div_test13);

  suite_add_tcase(result, tc_div_test);

  return result;
}
/***********************************/
/***********    NEGATE    **********/
/***********************************/

START_TEST(negate_test1) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 193700;

  result.bits[0] = 193700;
  set_sign(&result, 1);

  s21_negate(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(negate_test2) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 193700;
  set_sign(&result, 1);
  set_scale(&value_1, 24);

  result.bits[0] = 193700;
  set_scale(&result, 24);

  s21_negate(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

Suite *s21_negate_test() {
  Suite *result;
  TCase *tc_negate_test;

  result = suite_create("negate");
  tc_negate_test = tcase_create("negate");

  tcase_add_test(tc_negate_test, negate_test1);
  tcase_add_test(tc_negate_test, negate_test2);

  suite_add_tcase(result, tc_negate_test);

  return result;
}

/***********************************/
/***********    ROUND     **********/
/***********************************/

START_TEST(round_test1) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 45;
  set_scale(&value_1, 1);

  result.bits[0] = 5;

  s21_round(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(round_test2) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 46;
  set_sign(&value_1, 1);
  set_scale(&value_1, 1);

  result.bits[0] = 5;
  set_sign(&result, 1);

  s21_round(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(round_test3) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  s21_round(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(round_test4) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 123;
  set_scale(&value_1, 3);

  result.bits[0] = 0;

  s21_round(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(round_test5) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 123;
  set_sign(&value_1, 1);
  set_scale(&value_1, 2);

  result.bits[0] = 1;
  set_sign(&result, 1);

  s21_round(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

Suite *s21_round_test() {
  Suite *result;
  TCase *tc_round_test;

  result = suite_create("round");
  tc_round_test = tcase_create("round");

  tcase_add_test(tc_round_test, round_test1);
  tcase_add_test(tc_round_test, round_test2);
  tcase_add_test(tc_round_test, round_test3);
  tcase_add_test(tc_round_test, round_test4);
  tcase_add_test(tc_round_test, round_test5);

  suite_add_tcase(result, tc_round_test);

  return result;
}

/***********************************/
/***********   TRUNCATE   **********/
/***********************************/

START_TEST(truncate_test1) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 45;
  set_scale(&value_1, 1);

  result.bits[0] = 4;

  s21_truncate(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(truncate_test2) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 123456;
  set_scale(&value_1, 6);

  s21_truncate(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(truncate_test3) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 45;
  set_scale(&value_1, 1);

  result.bits[0] = 4;

  s21_truncate(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(truncate_test4) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  s21_truncate(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

Suite *s21_truncate_test() {
  Suite *result;
  TCase *tc_truncate_test;

  result = suite_create("truncate");
  tc_truncate_test = tcase_create("truncate");

  tcase_add_test(tc_truncate_test, truncate_test1);
  tcase_add_test(tc_truncate_test, truncate_test2);
  tcase_add_test(tc_truncate_test, truncate_test3);
  tcase_add_test(tc_truncate_test, truncate_test4);

  suite_add_tcase(result, tc_truncate_test);

  return result;
}

/***********************************/
/***********    FLOOR     **********/
/***********************************/

START_TEST(floor_test1) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 45;
  set_scale(&value_1, 1);

  result.bits[0] = 4;

  s21_floor(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(floor_test2) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 41234;
  set_scale(&value_1, 4);

  result.bits[0] = 4;

  s21_floor(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST;

START_TEST(floor_test3) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  value_1.bits[0] = 41234;
  set_scale(&value_1, 4);
  set_sign(&value_1, 1);

  result.bits[0] = 5;
  set_sign(&result, 1);

  s21_floor(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

START_TEST(floor_test4) {
  s21_decimal value_1 = {0};
  s21_decimal my_result = {0};
  s21_decimal result = {0};

  s21_floor(value_1, &my_result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(my_result.bits[i], result.bits[i]);
  }
}
END_TEST

Suite *s21_floor_test() {
  Suite *result;
  TCase *tc_floor_test;

  result = suite_create("floor");
  tc_floor_test = tcase_create("floor");

  tcase_add_test(tc_floor_test, floor_test1);
  tcase_add_test(tc_floor_test, floor_test2);
  tcase_add_test(tc_floor_test, floor_test3);
  tcase_add_test(tc_floor_test, floor_test4);

  suite_add_tcase(result, tc_floor_test);

  return result;
}

/***********************************/
/********* INT TO DECIMAL **********/
/***********************************/
START_TEST(test_s21_from_int_to_decimal_1) {
  int dst_2 = -123;
  s21_decimal value2 = {0};
  s21_decimal value3 = {{123, 0, 0, 0}};
  set_sign(&value3, 1);
  int test_2 = 0;
  ck_assert_int_eq(s21_from_int_to_decimal(dst_2, &value2), test_2);
}
END_TEST;

START_TEST(test_s21_from_int_to_decimal_2) {
  int dst_3 = -123;
  s21_decimal value4 = {0};
  s21_from_int_to_decimal(dst_3, &value4);
  s21_decimal value5 = {{123, 0, 0, 0}};
  set_sign(&value5, 1);
  int is_equal_3 = 1;
  ck_assert_int_eq(s21_is_equal(value4, value5), is_equal_3);
}
END_TEST;

Suite *s21_from_int_to_decimal_test() {
  Suite *result;
  TCase *tc_from_int_to_decimal;

  result = suite_create("s21_from_int_to_decimal");
  tc_from_int_to_decimal = tcase_create("s21_from_int_to_decimal");

  tcase_add_test(tc_from_int_to_decimal, test_s21_from_int_to_decimal_1);
  tcase_add_test(tc_from_int_to_decimal, test_s21_from_int_to_decimal_2);

  suite_add_tcase(result, tc_from_int_to_decimal);

  return result;
}

/***********************************/
/********* DECIMAL TO INT **********/
/***********************************/

START_TEST(test_s21_from_decimal_to_int_1) {
  int dst_1 = 0;
  s21_decimal value1 = {{12300, 0, 0, 0}};
  set_scale(&value1, 2);
  s21_from_decimal_to_int(value1, &dst_1);
  int test_1 = 123;

  ck_assert_int_eq(dst_1, test_1);
}
END_TEST;

START_TEST(test_s21_from_decimal_to_int_2) {
  int dst_2 = 0;
  s21_decimal value2 = {{123, 0, 0, 0}};
  set_sign(&value2, 1);
  s21_from_decimal_to_int(value2, &dst_2);
  int test_2 = -123;

  ck_assert_int_eq(dst_2, test_2);
}
END_TEST;

START_TEST(test_s21_from_decimal_to_int_3) {
  int dst_3 = 0;
  s21_decimal value3 = {{6, 0, 0, 0}};
  set_scale(&value3, 1);
  s21_from_decimal_to_int(value3, &dst_3);
  int test_3 = 0;

  ck_assert_int_eq(dst_3, test_3);
}
END_TEST;

START_TEST(test_s21_from_decimal_to_int_4) {
  int dst_4 = 0;
  s21_decimal value4 = {{123, 123, 0, 0}};
  s21_from_decimal_to_int(value4, &dst_4);
  int test_4 = 1;

  ck_assert_int_eq(s21_from_decimal_to_int(value4, &dst_4), test_4);
}
END_TEST;

START_TEST(test_s21_from_decimal_to_int_5) {
  int dst_5 = 0;
  s21_decimal value5 = {{123, 0, 0, 0}};
  set_bit(&value5, 31, 1);
  s21_from_decimal_to_int(value5, &dst_5);
  int test_5 = 0;

  ck_assert_int_eq(s21_from_decimal_to_int(value5, &dst_5), test_5);
}
END_TEST;

START_TEST(test_s21_from_decimal_to_int_6) {
  int dst_6 = 0;
  s21_decimal value6 = {{2147483647, 0, 0, 0}};
  set_sign(&value6, 1);

  s21_from_decimal_to_int(value6, &dst_6);
  int test_6 = -2147483648;

  ck_assert_int_eq(dst_6, test_6);
}
END_TEST;

Suite *s21_from_decimal_to_int_test() {
  Suite *result;
  TCase *tc_from_decimal_to_int;

  result = suite_create("s21_from_decimal_to_int");
  tc_from_decimal_to_int = tcase_create("s21_from_decimal_to_int");

  tcase_add_test(tc_from_decimal_to_int, test_s21_from_decimal_to_int_1);
  tcase_add_test(tc_from_decimal_to_int, test_s21_from_decimal_to_int_2);
  tcase_add_test(tc_from_decimal_to_int, test_s21_from_decimal_to_int_3);
  tcase_add_test(tc_from_decimal_to_int, test_s21_from_decimal_to_int_4);
  tcase_add_test(tc_from_decimal_to_int, test_s21_from_decimal_to_int_5);
  tcase_add_test(tc_from_decimal_to_int, test_s21_from_decimal_to_int_6);

  suite_add_tcase(result, tc_from_decimal_to_int);

  return result;
}

/***********************************/
/******** FLOAT TO DECIMAL *********/
/***********************************/
START_TEST(test_from_float_to_decimal1) {
  float f = 0.0;
  s21_decimal result;
  s21_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  s21_from_float_to_decimal(f, &result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(test_from_float_to_decimal2) {
  float f = 1357.1357;
  s21_decimal result;
  s21_decimal check = {{0b101001011010101010000, 0, 0, 0}};
  set_scale(&check, 3);
  s21_from_float_to_decimal(f, &result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], check.bits[i]);
  }
}
END_TEST

START_TEST(test_from_float_to_decimal3) {
  float f = -0.1919191919191919;

  s21_decimal check = {{1919192, 0, 0, 2147942400}};

  s21_decimal result;
  s21_from_float_to_decimal(f, &result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], check.bits[i]);
  }
}

START_TEST(test_from_float_to_decimal4) {
  float f = -0.000000000007887;

  s21_decimal check = {{7887000, 0, 0, 2148663296}};

  s21_decimal result;
  s21_from_float_to_decimal(f, &result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], check.bits[i]);
  }
}

START_TEST(test_from_float_to_decimal5) {
  float f = 5.000000000000000000000003;

  s21_decimal check = {{5000000, 0, 0, 393216}};

  s21_decimal result;
  s21_from_float_to_decimal(f, &result);

  for (int i = 0; i < 4; i++) {
    ck_assert_int_eq(result.bits[i], check.bits[i]);
  }
}

Suite *from_float_to_decimal() {
  Suite *result;
  TCase *tc_from_float_to_decimal_test;

  result = suite_create("from_float_to_decimal");
  tc_from_float_to_decimal_test = tcase_create("from_float_to_decimal");

  tcase_add_test(tc_from_float_to_decimal_test, test_from_float_to_decimal1);
  tcase_add_test(tc_from_float_to_decimal_test, test_from_float_to_decimal2);
  tcase_add_test(tc_from_float_to_decimal_test, test_from_float_to_decimal3);
  tcase_add_test(tc_from_float_to_decimal_test, test_from_float_to_decimal4);
  tcase_add_test(tc_from_float_to_decimal_test, test_from_float_to_decimal5);

  suite_add_tcase(result, tc_from_float_to_decimal_test);

  return result;
}

/***********************************/
/******** DECIMAL TO FLOAT *********/
/***********************************/
START_TEST(from_decimal_to_float_0) {
  s21_decimal my_res = {{123, 0, 0, 0}};

  set_scale(&my_res, 1);

  float res = 12.3;

  float tmp = 0;
  s21_from_decimal_to_float(my_res, &tmp);

  ck_assert_float_eq(tmp, res);
}
END_TEST

START_TEST(from_decimal_to_float_1) {
  s21_decimal my_res = {{982, 0, 0, 0}};

  set_scale(&my_res, 2);

  float res = 9.82;

  float tmp = 0;
  s21_from_decimal_to_float(my_res, &tmp);

  ck_assert_float_eq(tmp, res);
}
END_TEST

START_TEST(from_decimal_to_float_2) {
  s21_decimal my_res = {{1111, 0, 0, 0}};

  set_scale(&my_res, 5);

  float res = 0.01111;

  float tmp = 0;
  s21_from_decimal_to_float(my_res, &tmp);

  ck_assert_float_eq(tmp, res);
}
END_TEST

START_TEST(from_decimal_to_float_3) {
  s21_decimal my_res = {{1111, 0, 0, 0}};

  set_scale(&my_res, 6);

  float res = 0.001111;

  float tmp = 0;
  s21_from_decimal_to_float(my_res, &tmp);

  ck_assert_float_eq(tmp, res);
}
END_TEST

Suite *s21_from_decimal_to_float_test() {
  Suite *result;
  TCase *tc_s21_from_decimal_to_float_test;

  result = suite_create("s21_from_decimal_to_float");
  tc_s21_from_decimal_to_float_test = tcase_create("s21_from_decimal_to_float");

  tcase_add_test(tc_s21_from_decimal_to_float_test, from_decimal_to_float_0);
  tcase_add_test(tc_s21_from_decimal_to_float_test, from_decimal_to_float_1);
  tcase_add_test(tc_s21_from_decimal_to_float_test, from_decimal_to_float_2);
  tcase_add_test(tc_s21_from_decimal_to_float_test, from_decimal_to_float_3);

  suite_add_tcase(result, tc_s21_from_decimal_to_float_test);
  return result;
}

int main() {
  Suite *result;
  int failed = 0;
  SRunner *runner;

  result = s21_test_greater();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_less();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_less_BIG();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_equal();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = test_s21_test_is_greater_or_equal();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = test_s21_test_is_less_or_equal();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = test_s21_test_is_not_equal();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = test_s21_test_is_not_equal_BIG();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_test_add();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_sub_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_mul_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_div_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_negate_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_round_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_truncate_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_floor_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_from_int_to_decimal_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_from_decimal_to_int_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = from_float_to_decimal();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  result = s21_from_decimal_to_float_test();
  runner = srunner_create(result);
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : CK_FAILURE;
}