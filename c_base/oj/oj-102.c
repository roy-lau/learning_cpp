/**
 * @file oj-102.c
 * @author RoyLau (897379293@qq.com)
 * @brief 注水问题
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int a, b, c, t;
  scanf("%d%d%d%d", &a, &b, &c, &t);
  // 1-(1/a + 1/b) * t / (1/a +1/b - 1/c) = t2
  // t1+t2
  double m = (1.0 / a + 1.0 / b);
  printf("%.2lf\n", (1 - m * t) / (m - 1.0 / c) + t);

  return 0;
}