/**
 * @file 5-1.math.c
 * @author RoyLau
 * @brief 求一个数的立方根
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <math.h>

int main() {
  double x;
  while (~scanf("%lf", &x)) {
    printf("--> %lf\n", pow(x, 1.0 / 3.0));
  }

  return 0;
}