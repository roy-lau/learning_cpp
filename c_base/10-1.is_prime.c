/**
 * @file 10-1.is_prime.c
 * @author RoyLau (897379293@qq.com)
 * @brief 判断素数
 * @version 0.1
 * @date 2022-06-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <math.h>

int is_prime(int n) {
  for (int i = 2;i <= sqrt(n);++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {

  int n;
  while (~scanf("%d", &n)) {
    printf("%d %s\n", n, is_prime(n) ? "is a prime!" : "is not a prime!");
  }

  return 0;
}