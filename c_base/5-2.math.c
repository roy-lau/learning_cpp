/**
 * @file 5-2.math.c
 * @author RoyLau
 * @brief 角度值转弧度值
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main() {
  double x;
  while (~scanf("%lf", &x)) {
    printf("--> %lf\n", x * PI / 180.0);
  }

  return 0;
}