/**
 * @file oj-reverse_num.c
 * @author RoyLau
 * @brief 数字翻转
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int reverse_num(int n) {
  int sum = 0, temp = n;
  while (temp) {
    sum = sum * 10 + temp % 10;
    temp /= 10;
    // n = 123
    // 第一次循环
    // 0 * 10 + 123 % 10  = 3
    // 123 / 10 = 12
    // 第二次循环
    // 3 * 10 + 12 % 10 = 32
    // 12 / 10 = 1
    // 第三次循环
    // 32 * 10 + 1 % 10 = 321
    // 1 / 10 = 0 结束循环
  }
  return sum;
}


int main() {
  int n;
  while (~scanf("%d", &n)) {
    printf("%d\n", reverse_num(n));
  }

  return 0;
}