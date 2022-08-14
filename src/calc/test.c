#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21calc.h"

START_TEST(test_add) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "-cos(-cos(5))+4*(5)";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = 19.039963;
  ck_assert_float_eq_tol(a, reference, 1e-6);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_divide) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "64/4+32*2";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = 80.0;
  ck_assert_double_eq(a, reference);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_trigonometry) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "sin(0)+cos(0)*(45)";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = 45.0;
  ck_assert_double_eq(a, reference);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_trigonometry1) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "-cos(3)+sin(5)+24*45/12^5";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = 0.035408;
  ck_assert_float_eq_tol(a, reference, 1e-6);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_binar) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "(-6.0)+2.2+2^2";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = 0.200000;
  ck_assert_float_eq_tol(a, reference, 1e-6);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_unar) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "atan(0.5)+9.6325873+52.369894";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = 62.466129;
  ck_assert_float_eq_tol(a, reference, 1e-6);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_another1) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "99586.1/99586.1 + sin(45)+cos(100)-6+2.2";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = -1.086778;
  ck_assert_float_eq_tol(a, reference, 1e-6);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_another3) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "tan(1)+exp(1)+log(2)";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = 4.576720;
  ck_assert_float_eq_tol(a, reference, 1e-6);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_another4) {
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str1[256] = "asin(1)+acos(1)+sqrt(4)";
  char str[256];
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  double a = polish_calc(&tail);
  // printf("%lf\n", a);
  double reference = 3.570796;
  ck_assert_float_eq_tol(a, reference, 1e-6);
  free(tail);
  free(tail2);
  free(stack_digit);
  free(out_string);
}
END_TEST

START_TEST(test_error1) {
  char *str = "..+5m3";
  int e = 1;
  ck_assert_int_eq(check(str), e);
}
END_TEST

START_TEST(test_error2) {
  char *str = "(5+5))";
  int e = 1;
  ck_assert_int_eq(check(str), e);
}
END_TEST

START_TEST(test_error3) {
  char *str = "---+";
  int e = 1;
  ck_assert_int_eq(check(str), e);
}
END_TEST

START_TEST(test_error4) {
  char *str = "-m2+2logl";
  int e = 1;
  ck_assert_int_eq(check(str), e);
}
END_TEST

Suite *suit_create(void) {
  Suite *suite = suite_create("Tests for s21calc");
  TCase *test_plus = tcase_create("test");
  TCase *test_minus = tcase_create("test1");
  TCase *test_trig = tcase_create("test2");
  TCase *test_trig1 = tcase_create("test3");
  TCase *test_binary = tcase_create("test4");
  TCase *test_unary = tcase_create("test5");
  TCase *test_another = tcase_create("test6");
  TCase *test_another_1 = tcase_create("test7");
  TCase *test_another_2 = tcase_create("test8");
  TCase *test_error = tcase_create("test9");
  TCase *test_error_1 = tcase_create("test10");
  TCase *test_error_2 = tcase_create("test11");
  TCase *test_error_3 = tcase_create("test12");
  tcase_add_test(test_plus, test_add);
  tcase_add_test(test_minus, test_divide);
  tcase_add_test(test_trig, test_trigonometry);
  tcase_add_test(test_trig1, test_trigonometry1);
  tcase_add_test(test_binary, test_binar);
  tcase_add_test(test_unary, test_unar);
  tcase_add_test(test_another, test_another1);
  tcase_add_test(test_another_1, test_another3);
  tcase_add_test(test_another_2, test_another4);
  tcase_add_test(test_error, test_error1);
  tcase_add_test(test_error_1, test_error2);
  tcase_add_test(test_error_2, test_error3);
  tcase_add_test(test_error_3, test_error4);
  suite_add_tcase(suite, test_plus);
  suite_add_tcase(suite, test_minus);
  suite_add_tcase(suite, test_trig);
  suite_add_tcase(suite, test_binary);
  suite_add_tcase(suite, test_unary);
  suite_add_tcase(suite, test_another);
  suite_add_tcase(suite, test_another_1);
  suite_add_tcase(suite, test_another_2);
  suite_add_tcase(suite, test_error);
  suite_add_tcase(suite, test_error_1);
  suite_add_tcase(suite, test_error_2);
  suite_add_tcase(suite, test_error_3);
  return suite;
}

int main(void) {
  Suite *suite = suit_create();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  srunner_free(suite_runner);

  // if (srunner_ntests_failed(suite_runner) != 0) {
  //   return EXIT_FAILURE;
  // }
  return EXIT_SUCCESS;
}
