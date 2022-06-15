/**
 * @file 9-2.fac.c
 * @author RoyLau (897379293@qq.com)
 * @brief 递归 阶乘
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int fac(int n) {
  if (n == 1)return 1;
  return n * fac(n - 1);
}

int main() {
  int n;
  while (~scanf("%d", &n)) {
    printf("fac(%d) = %d\n", n, fac(n));
  }
  return 0;
}