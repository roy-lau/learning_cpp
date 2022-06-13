/**
 * @file oj-94.c
 * @author RoyLau
 * @brief 计算BMI
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  double w, h; // 体重，身高
  scanf("%lf%lf", &w, &h);
  printf("%.2lf\n", w / (h * h));

  return 0;
}