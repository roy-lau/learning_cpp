/**
 * @file oj-90.c
 * @author RoyLau
 * @brief 取数位II
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n / 100);
  printf("%d\n", n / 10 % 10);
  printf("%d\n", n % 10);
  return 0;
}