/**
 * @file oj-99.c
 * @author RoyLau
 * @brief 计算跑道的长度
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  double v, a;
  scanf("%lf%lf", &v, &a);
  double sum = (v * v) / (2 * a);
  printf("%.2lf\n", sum);

  return 0;
}