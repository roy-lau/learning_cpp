/**
 * @file oj-98.c
 * @author RoyLau
 * @brief 计算圆柱体的体积
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 * @公式1： 底面积=半径∗半径∗π
 * @公式2： 体积=底面积∗高
 */
#include <stdio.h>
#define PI 3.14


int main() {
  double r, h; // r=半径 h=高
  scanf("%lf%lf", &r, &h);

  double s = r * r * PI; // 底面积
  printf("%.2lf\n", s);

  double v = s * h;
  printf("%.2lf\n", v); // 体积

  return 0;
}

