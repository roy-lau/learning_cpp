/**
 * @file oj-79.c
 * @author RoyLau (897379293@qq.com)
 * @brief 输出素数
 * @version 0.1
 * @date 2022-06-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);

  int primes[b + 5] = { 0 };

  for (int i = 2; i <= b; ++i) {
    if (primes[i]) continue;
    for (int j = 2 * i;j <= b; j += i) {
      primes[j] = 1;
    }
  }

  for (;a <= b;a++) {
    if (primes[a])  continue;
    printf("%d\n", a);
  }

  return 0;
}