/**
 * @file 3-1.string.c
 * @author RoyLau
 * @brief 读入一行带空格的字符串
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {
  char str[100] = { 0 };

  scanf("%[^\n]s", str);
  printf("str = %s\n", str);

  return 0;
}