/**
 * @file oj-117.c
 * @author RoyLau (897379293@qq.com)
 * @brief 回文数
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int y = 0, z = n;
  while (n) {
    y = y * 10 + n % 10;
    n /= 10;
  }
  printf("%s\n", y == z ? "YES" : "NO");
  return 0;
}