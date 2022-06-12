/**
 * @file 1-1.printf.c
 * @author RoyLau
 * @brief printf 函数
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {
  printf("Hello Word!\n");

  int n;
  scanf("%d", &n);
  printf(" has %d digits!\n", printf("%d", n)); // 输出返回值

  return 0;
}