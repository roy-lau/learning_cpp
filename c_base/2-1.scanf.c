/**
 * @file 2-1.scanf.c
 * @author RoyLau
 * @brief scanf 函数
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {
  int a, b;
  // 循环读入
  while (scanf("%d%d", &a, &b) != -1) {
    printf("a = %d b= %d\n", a, b);
  }
  return 0;
}