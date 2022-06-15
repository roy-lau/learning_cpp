/**
 * @file oj-107.c
 * @author RoyLau (897379293@qq.com)
 * @brief 7 的奇数倍
 * @version 0.1
 * @date 2022-06-14
 * @desc 能被 7 整除，不能被 2 整除
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("%s\n", (n % 7 == 0 && n & 1) ? "YES" : "NO");
  return 0;
}