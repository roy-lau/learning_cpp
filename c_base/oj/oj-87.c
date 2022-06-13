/**
 * @file oj-87.c
 * @author RoyLau
 * @brief 矩形的周长和面积
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  double a, b;
  scanf("%lf%lf", &a, &b);
  printf("%.2lf\n", (a + b) * 2);
  printf("%.2lf\n", a * b);
  return 0;
}