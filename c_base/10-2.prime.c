/**
 * @file 10-2.prime.c
 * @author RoyLau (897379293@qq.com)
 * @brief 输出 100 以内的素数
 * @version 0.1
 * @date 2022-06-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <math.h>

int is_prime(int n) {
  for (int i = 2, I = sqrt(n);i <= I;++i) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {

  for (int i = 2; i < 101;++i) {
    if (is_prime(i)) printf("%d\n", i);
  }
  return 0;
}