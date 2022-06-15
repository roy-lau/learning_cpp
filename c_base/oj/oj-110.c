/**
 * @file oj-110.c
 * @author RoyLau (897379293@qq.com)
 * @brief 包裹托运价格
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  double n;
  scanf("%lf", &n);
  double sum;
  if (n < 15) {
    sum = n * 6;
  } else {
    sum = (15 * 6) + ((n - 15) * 9);
  }
  printf("%.2lf\n", sum);
  return 0;
}