/**
 * @file oj-100.c
 * @author RoyLau
 * @brief #101. 计算各位和
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
  int sum = 0, temp = n;
  while (temp) {
    sum += temp % 10;
    temp /= 10;
  }
  printf("%d\n", sum);

  return 0;
}