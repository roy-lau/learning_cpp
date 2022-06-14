/**
 * @file oj-95.c
 * @author RoyLau
 * @brief 交换两位数
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
  printf("%d%d\n", n % 10, n / 10);

  return 0;
}