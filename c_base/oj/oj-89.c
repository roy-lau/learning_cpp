/**
 * @file oj-89.c
 * @author RoyLau
 * @brief 取数位I
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
  printf("%d\n", n / 10);
  printf("%d\n", n % 10);
  return 0;
}