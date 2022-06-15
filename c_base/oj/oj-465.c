/**
 * @file oj-465.c
 * @author RoyLau (897379293@qq.com)
 * @brief 数的分离
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 * @ desc 取位数 floor(log10(n)) + 1
 */
#include <stdio.h>
#include <math.h>

int digit(long long n, int k) {
  if (floor(log10(n)) + 1 < k) return 0;
  if (k == 1) return n % 10;
  return digit(n / 10, k - 1);
}

int main() {
  long long n;
  int k;
  scanf("%lld%d", &n, &k);
  printf("%d\n", digit(n, k));

  return 0;
}