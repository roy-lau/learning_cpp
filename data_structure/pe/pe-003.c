/**
 * @file pe-003.c
 * @author RoyLau (897379293@qq.com)
 * @brief 最大回文乘积
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

#define MAX_N 1000

int is_rever(int n) {
  int temp = 0, x = n;
  while (x) {
    temp = temp * 10 + x % 10;
    x /= 10;
  }
  return temp == n;
}

int main() {
  int ans = 0;
  for (int i = 100; i < MAX_N;++i) {
    for (int j = i; j < MAX_N;++j) {
      if (is_rever(i * j) && i * j > ans) {
        ans = i * j;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}