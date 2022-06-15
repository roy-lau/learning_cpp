/**
 * @file 9-1.function.c
 * @author RoyLau (897379293@qq.com)
 * @brief 直线方程 y = k * x + b
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int solve(int k, int x, int b) {
  return k * x + b;
}

int main() {
  int k, b;
  scanf("%d%d", &k, &b);
  for (int x = 1;x < 101;++x) {
    printf("f(%d) = %d\n", x, solve(k, x, b));
  }
}