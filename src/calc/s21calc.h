#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef S21CALC_H
#define S21CALC_H

typedef struct {
  int sign;      //значение интовое
  double digit;  //числа
  int prior;
} Lexem;

typedef struct Stack {
  Lexem elements;  // поле данных операции и числа
  struct Stack *next;
  struct Stack *prev;  // две ссылки //двунаправленный список
} Stack;

//функция создания стека
Stack *createStack();
void push_digit(Stack **stack, double elements);
void push_oper(Stack **stack, int elements);
void push_struct(Stack **out, Stack **in);
void pop_stack(Stack **stack);
void print(Stack **stack);
void print_list(Stack **stack);

// преобразование
void validate_asin(char *str);
void validate_acos(char *str);
void validate_atan(char *str);
void validate_sqrt(char *str);
// void validate_ln(char *str);
void validate_sin(char *str);
void validate_cos(char *str);
void validate_tan(char *str);
void validate_exp(char *str);
void validate_log(char *str);
void validate_mod(char *str);
void validated(char *str);

//дополнительные функции
int get_priority(int flag);
int rang(char type);
double get_digit(char *str, int *i);
void unit(Stack **temp, Stack **out_string);
char remove_spaces(char *source, char *target);
int check(char *str);

//основные функции
void structur(Stack **stack_digit, char *str);
void polish(Stack **stack_digit, Stack **out_string);
double polish_calc(Stack **stack);
double unary_calc(double x, int sign);
double binary_calc(double x, double y, int sign);
double output(char *str1);

#endif  // S21CALC_H
