/**
 * @file oj-109.c
 * @author RoyLau (897379293@qq.com)
 * @brief 四位数中有偶数位么
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
  while (n) {
    if (!(n & 1)) {
      printf("YES\n");
      return 0;
    }
    n /= 10;
  }
  printf("NO\n");
  return 0;
}