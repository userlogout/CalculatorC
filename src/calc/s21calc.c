#include "s21calc.h"
int error = 0;
Stack *createStack() {
  Stack *arr = malloc(sizeof(Stack));
  arr->prev = NULL;
  arr->next = NULL;
  arr->elements.digit = 0;
  arr->elements.prior = 0;
  arr->elements.sign = -3;
  return arr;
}

// функция добавления в стек чисел
void push_digit(Stack **stack, double elements) {
  Stack *temp = malloc(sizeof(Stack));
  temp->elements.digit = elements;
  temp->elements.sign = 0;
  temp->elements.prior = -1;
  temp->next = NULL;
  temp->prev = (*stack);
  (*stack)->next = temp;
  (*stack) = temp;
}

void push_struct(Stack **out, Stack **in) {
  Stack *temp = malloc(sizeof(Stack));
  temp->elements.digit = (*in)->elements.digit;
  temp->elements.sign = (*in)->elements.sign;
  temp->elements.prior = (*in)->elements.prior;
  temp->next = NULL;
  temp->prev = (*out);
  (*out)->next = temp;
  (*out) = temp;
}

// функция добавления в стек операций
void push_oper(Stack **stack, int elements) {
  // создали новую переменную и выделили для нее память
  Stack *temp = malloc(sizeof(Stack));
  temp->elements.sign = elements;
  temp->elements.digit = 0;
  temp->elements.prior = 0;
  temp->next = NULL;
  temp->prev = (*stack);
  (*stack)->next = temp;
  (*stack) = temp;
}

void pop_stack(Stack **stack) {
  if ((*stack)->prev != NULL) {
    // выкинутый элемент и предыдущий элемент равен не ему а null
    Stack *temp = (*stack);
    ((*stack)->prev)->next = NULL;
    (*stack) = (*stack)->prev;
    free(temp);
  }
}

// void print(Stack **stack) {
//   while ((*stack)->prev != NULL) {
//     if ((*stack)->elements.sign == 0) {
//       printf("%lf\n", (*stack)->elements.digit);
//     } else {
//       printf("%d\n ", (*stack)->elements.prior);
//     }
//     pop_stack(stack);
//   }
// }

// void print_list(Stack **stack) {  // печатает стек в обратном порядке
//   (*stack) = (*stack)->next;  // i = 0
//   while ((*stack) != NULL) {
//     if ((*stack)->elements.sign == 0) {
//       printf("%lf\n", (*stack)->elements.digit);
//     } else {
//       printf(" %d\n", (*stack)->elements.sign);
//     }
//     (*stack) = (*stack)->next;  // i++
//   }
// }

void validate_asin(char *str) {
  char find[] = "asin";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp) = 'a';
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    *(temp + 3) = ' ';
    temp = strstr(str, find);
  }
}

void validate_acos(char *str) {
  char find[] = "acos";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp) = 'o';
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    *(temp + 3) = ' ';
    temp = strstr(str, find);
  }
}

void validate_atan(char *str) {
  char find[] = "atan";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp) = 'n';
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    *(temp + 3) = ' ';
    temp = strstr(str, find);
  }
}

void validate_sqrt(char *str) {
  char find[] = "sqrt";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp) = 'q';
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    *(temp + 3) = ' ';
    temp = strstr(str, find);
  }
}

void validate_ln(char *str) {
  char find[] = "ln";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp) = 'g';
    *(temp + 1) = ' ';
    temp = strstr(str, find);
  }
}

void validate_sin(char *str) {
  char find[] = "sin";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    temp = strstr(str, find);
  }
}

void validate_cos(char *str) {
  char find[] = "cos";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    temp = strstr(str, find);
  }
}

void validate_tan(char *str) {
  char find[] = "tan";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    temp = strstr(str, find);
  }
}

void validate_exp(char *str) {
  char find[] = "exp";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    temp = strstr(str, find);
  }
}

void validate_log(char *str) {
  char find[] = "log";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp) = 'g';
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    temp = strstr(str, find);
  }
}

void validate_mod(char *str) {
  char find[] = "mod";
  char *temp = strstr(str, find);
  while (temp != NULL) {
    *(temp + 1) = ' ';
    *(temp + 2) = ' ';
    temp = strstr(str, find);
  }
}

void validated(char *str) {
  validate_asin(str);
  validate_acos(str);
  validate_atan(str);
  validate_sqrt(str);
  validate_ln(str);
  validate_sin(str);
  validate_cos(str);
  validate_tan(str);
  validate_exp(str);
  validate_log(str);
  validate_mod(str);
}

// получение приоритета
int get_priority(int flag) {
  int result = 0;
  if (flag == 17) result = 0;  // (
  if (flag == 1) result = 1;
  if (flag == 2) result = 1;
  if (flag == 3) result = 2;
  if (flag == 4) result = 2;
  if (flag == 5) result = 3;  // pow
  if (flag == 6) result = 2;  // mod
  if (flag == 7) result = 5;
  if (flag == 8) result = 5;
  if (flag == 9) result = 5;
  if (flag == 10) result = 5;
  if (flag == 11) result = 5;
  if (flag == 12) result = 5;
  if (flag == 13) result = 5;
  if (flag == 14) result = 5;
  if (flag == 15) result = 5;
  if (flag == 16) result = 5;
  if (flag == 18) result = 6;  // )
  if (flag == 19) result = 4;  // unar minus
  return result;
}

int rang(char type) {
  int rang = 0;
  if (type == '+') rang = 1;
  if (type == '-') rang = 2;
  if (type == '*') rang = 3;
  if (type == '/') rang = 4;
  if (type == '^') rang = 5;
  if (type == 'm') rang = 6;   // mod
  if (type == 's') rang = 7;   // sin
  if (type == 'c') rang = 8;   // cos
  if (type == 't') rang = 9;   // tan
  if (type == 'e') rang = 10;  // exp
  if (type == 'g') rang = 11;  // log
  if (type == 'i') rang = 12;  // ln
  if (type == 'a') rang = 13;  // asin
  if (type == 'o') rang = 14;  // acos
  if (type == 'n') rang = 15;  // atan
  if (type == 'q') rang = 16;  // sqrt
  if (type == '(') rang = 17;  // (
  if (type == ')') rang = 18;  // )
  if (type == '~') rang = 19;  // unar minus
  return rang;
}

double get_digit(char *str, int *i) {
  int j = 0;
  char buf[256];
  memset(buf, 0, 256);  // чтобы очистить мусор временный массив buf
  double result = 0;
  while (isdigit(str[(*i)]) || (str[(*i)] == '.')) {
    buf[j] = str[*i];
    j++;
    (*i)++;
  }
  result = atof(buf);
  return result;
}

void structur(Stack **stack_digit, char *str) {
  int i = 0;
  while (i < (int)strlen(str)) {
    if (isdigit(str[i])) {
      double r = get_digit(str, &i);
      push_digit(stack_digit, r);
    } else {
      int a = rang(str[i]);
      push_oper(stack_digit, a);
      (*stack_digit)->elements.prior = get_priority(a);
      i++;
    }
  }
}

void polish(Stack **stack_digit, Stack **out_string) {
  Stack *tail = *out_string;
  Stack *temp = createStack();
  if ((*stack_digit)->elements.sign == -3) {
    (*stack_digit) = (*stack_digit)->next;
  }
  for (; (*stack_digit) != NULL;) {
    if ((*stack_digit)->elements.prior == -1) {
      push_struct(out_string, stack_digit);
      (*stack_digit) = (*stack_digit)->next;  // i++;
      continue;
    }
    if ((*stack_digit)->elements.prior == 5) {
      push_struct(&temp, stack_digit);
      (*stack_digit) = (*stack_digit)->next;
      continue;
    }
    if (((*stack_digit)->elements.prior > 0) &&
        ((*stack_digit)->elements.prior < 5)) {
      if (temp->prev == NULL) {
        push_struct(&temp, stack_digit);
        (*stack_digit) = (*stack_digit)->next;
      } else {
        while ((temp->elements.prior) >= ((*stack_digit)->elements.prior)) {
          push_struct(out_string, &temp);
          pop_stack(&temp);
        }
        push_struct(&temp, stack_digit);
        (*stack_digit) = (*stack_digit)->next;
      }
      continue;
    }
    if ((*stack_digit)->elements.prior == 0) {
      push_struct(&temp, stack_digit);
      (*stack_digit) = (*stack_digit)->next;
      continue;
    }
    if ((*stack_digit)->elements.prior == 6) {
      while ((temp)->elements.prior != 0) {
        push_struct(out_string, &temp);
        pop_stack(&temp);
      }
      pop_stack(&temp);
      (*stack_digit) = (*stack_digit)->next;
      continue;
    }
    if ((temp)->elements.prior == 5) {
      push_struct(out_string, &temp);
      pop_stack(&temp);
      continue;
    }
  }
  unit(&temp, out_string);
  // free(out_string);
  *stack_digit = tail;
}

double polish_calc(Stack **stack) {
  double final_digit = 0.0;
  Stack *result = createStack();
  (*stack) = (*stack)->next;
  while ((*stack) != NULL) {
    // если число
    if ((*stack)->elements.prior == -1) {
      push_struct(&result, stack);
      (*stack) = (*stack)->next;
      // pop_stack(&result);
    } else {
      // + - * /
      if (((*stack)->elements.prior > 0) && ((*stack)->elements.prior < 4)) {
        int sign = (*stack)->elements.sign;
        (*stack) = (*stack)->next;
        double x = (result)->elements.digit;
        pop_stack(&result);
        double y = (result)->elements.digit;
        pop_stack(&result);
        double res = binary_calc(x, y, sign);
        push_digit(&result, res);
        // если токен функция
      } else if ((((*stack)->elements.prior >= 4) &&
                  ((*stack)->elements.prior < 17)) ||
                 ((*stack)->elements.prior == 19)) {
        double x = result->elements.digit;
        pop_stack(&result);
        int sign = (*stack)->elements.sign;
        (*stack) = (*stack)->next;
        double c = unary_calc(x, sign);
        push_digit(&result, c);
      }
    }
  }
  final_digit = result->elements.digit;
  // free(result);
  pop_stack(&result);
  return final_digit;
}

double unary_calc(double x, int sign) {
  double value = 0.0;
  switch (sign) {
    case 7:
      value = sin(x);
      break;
    case 8:
      value = cos(x);
      break;
    case 9:
      value = tan(x);
      break;
    case 10:
      value = exp(x);
      break;
    case 11:
      value = log10(x);
      break;
    case 12:
      value = log(x);
      break;
    case 13:
      value = asin(x);
      break;
    case 14:
      value = acos(x);
      break;
    case 15:
      value = atan(x);
      break;
    case 16:
      value = sqrt(x);
      break;
    default:
      break;
  }
  return value;
}

double binary_calc(double x, double y, int sign) {
  double value = 0.0;
  switch (sign) {
    case 1:
      value = y + x;
      break;
    case 2:
      value = y - x;
      break;
    case 3:
      value = y * x;
      break;
    case 4:
      value = y / x;
      break;
    case 5:
      value = pow(y, x);
      break;
    case 6:
      value = fmod(y, x);
      break;
    default:
      break;
  }
  return value;
}

void unit(Stack **temp, Stack **out_string) {
  while ((*temp)->prev != NULL) {
    push_struct(out_string, temp);
    pop_stack(temp);
  }
}

char remove_spaces(char *source, char *target) {
  memset(target, 0, 256);
  int j = 0;
  for (int i = 0; source[i] != '\0'; i++) {
    if (isspace(source[i]) == 0) {
      target[j] = source[i];
      j++;
    }
  }
  return *target;
}

int check(char *str) {
  int flag = 0;
  int left = 0;
  int right = 0;
  int c = 0;  // count digits
  int i = 0;
  int t = 0;  // count dots
  while (str[i] != '\0') {
    if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
      while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.') {
        if (str[i] == '.') {
          t++;
          if (strchr("+-*/^()sctaonigqm.x", str[i - 1]) ||
              strchr("+-*/^()sctaonigq.x", str[i + 1]) || str[i - 1] == '\0' ||
              str[i + 1] == '\0' || t > 1) {
            flag = 1;
            return flag;
          }
          i++;
        } else if (str[i] >= '0' && str[i] <= '9') {
          c++;
          if ((strchr("0123456789", str[i + 1]) && str[i] == '0' && c == 1 &&
               str[i + 1] != '\0') ||
              str[i - 1] == 'x' || str[i + 1] == 'x') {
            printf("err\n");
            flag = 1;
            return flag;
          }
          i++;
        }
      }
      t = 0;
      c = 0;
    } else if (strchr("*/^", str[i])) {
      if (strchr("*/^+-(m", str[i - 1]) || str[i + 1] == '\0' ||
          strchr(")+-", str[i + 1]) || str[i - 1] == '\0') {
        flag = 1;
        return flag;
      }
      i++;
    } else if (strchr("(", str[i])) {
      if ((strchr("0123456789x.", str[i - 1]) && str[i - 1] != '\0') ||
          str[i + 1] == '\0') {
        flag = 1;
        return flag;
      }
      left++;
      i++;
    } else if (strchr(")", str[i])) {
      if ((strchr("0123456789x)", str[i + 1]) && str[i + 1] != '\0') ||
          str[i - 1] == '\0' || left == 0 || strchr("+-m(", str[i - 1])) {
        flag = 1;
        return flag;
      }
      right++;
      i++;
    } else if (strchr("nsctaoigqlnexpsqrtlog", str[i])) {
      if (strchr("0123456789x", str[i - 1]) && str[i - 1] != '\0') {
        flag = 1;
        return flag;
      }
      i++;
    } else if (strchr("mod", str[i])) {
      if (str[i + 1] == '\0') {
        flag = 1;
        return flag;
      }
      i++;
    } else if (str[i] == 'm') {
      if (strchr("+-*/^(.", str[i - 1]) || str[i - 1] == '\0' ||
          str[i + 1] == '\0') {
        flag = 1;
        return flag;
      }
      i++;
    } else if (str[i] == 'x') {
      if (strchr("x", str[i + 1]) && str[i + 1] != '\0') {
        flag = 1;
        return flag;
      }
      i++;
    } else if (strchr("-+", str[i])) {
      if ((strchr("+-", str[i - 1]) && str[i - 1] != '\0') ||
          str[i + 1] == '\0') {
        flag = 1;
        return flag;
      }
      i++;
    }
  }
  if (left != right) {
    flag = 1;
    return flag;
  }
  return flag;
}

// int main() {
//   Stack *out_string = createStack();
//   Stack *stack_digit = createStack();
//   Stack *tail = stack_digit;
//   Stack *tail2 = out_string;
//   char str1[256] = "";
//   char str[256];
//   validated(str1);
//   remove_spaces(str1, str);
//   printf("%s\n", str);
//   if (check(str) == 1) {
//     printf("error");
//   } else {
//     structur(&stack_digit, str);
//     polish(&tail, &tail2);
//     double a = polish_calc(&tail);
//     printf("%lf\n", a);
//   }
//   free(tail);
//   free(tail2);
//   // free(stack_digit);
//   // free(out_string);
//   return 0;
// }

double output(char *str1) {
  double res = 0;
  //  printf("%s", str1);
  Stack *out_string = createStack();
  Stack *stack_digit = createStack();
  Stack *tail = stack_digit;
  Stack *tail2 = out_string;
  char str[256];
  str1[strcspn(str1, "=")] = '\0';  // обрезает по знаку равно
  validated(str1);
  remove_spaces(str1, str);
  structur(&stack_digit, str);
  polish(&tail, &tail2);
  res = polish_calc(&tail);
  return res;
}
