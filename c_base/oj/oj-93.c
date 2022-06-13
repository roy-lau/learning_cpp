/**
 * @file oj-93.c
 * @author RoyLau
 * @brief 温度换算
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  double c;
  scanf("%lf", &c);
  printf("%.2lf\n", 1.8 * c + 32);

  return 0;
}