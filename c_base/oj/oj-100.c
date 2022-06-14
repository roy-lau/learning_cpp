/**
 * @file oj-100.c
 * @author RoyLau
 * @brief 计算复利
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define monthly_interest 1.00417

int main() {
  int m = 6;
  double sum = 0, n;
  scanf("%lf", &n);
  while (m) {
    sum = (n + sum) * monthly_interest;
    m--;
  }
  printf("$%.2lf\n", sum);

  return 0;
}