/**
 * @file 4-1.operator.c
 * @author RoyLau
 * @brief 运算符
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  
  printf("%d\n", 2 & 3);
  printf("%d\n", 2 | 3);
  printf("%d\n", 2 << 3); // 立方
  printf("%d\n", 3 >> 2); // 立方
  printf("%d\n", ~2); // int 类型是 4 个字节，一个字节是 8 位，一共 32 位。 00000000000000000000000000000010 ==> 11111111111111111111111111111101
  return 0;
}