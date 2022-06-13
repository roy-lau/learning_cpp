/**
 * @file 6-2.swap.c
 * @author RoyLau
 * @brief 变量交换 2
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {
  int a, b;
  while (~scanf("%d%d", &a, &b)) {
    printf("before: a = %d, b= %d\n", a, b);
    // 只能交换整型
    a ^= b;
    b ^= a;
    a ^= b;
    printf("swap: a = %d, b= %d\n", a, b);
  }

  return 0;
}