/**
 * @file oj-92.c
 * @author RoyLau
 * @brief 圆形面积和周长
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define PI 3.14

int main() {
  double r;
  scanf("%lf", &r);
  printf("%.2lf\n", 2 * PI * r);
  printf("%.2lf\n", PI * r * r);
  return 0;
}