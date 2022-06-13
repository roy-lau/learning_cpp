/**
 * @file oj-97.c
 * @author RoyLau
 * @brief #97. 求和2
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  long n;
  scanf("%ld", &n);
  printf("%ld\n", n * (1 + n) / 2); // 公式：(首项+尾项)*项数/2

  return 0;
}