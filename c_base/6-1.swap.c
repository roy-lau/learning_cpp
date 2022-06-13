/**
 * @file 6-1.swap.c
 * @author RoyLau
 * @brief 变量交换 1
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
    int temp = a;
    a = b;
    b = temp;
    printf("swap: a = %d, b= %d\n", a, b);
  }

  return 0;
}