/**
 * @file 3-1.string.c
 * @author RoyLau
 * @brief 循环读入一行带空格的字符串
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {
  char str[100] = { 0 };

  while (scanf("%[^\n]s", str) != EOF) {
    getchar(); // 吞掉开头的换行符(\n)
    int len = printf("%s", str);
    printf(" has %d digits!\n", len);
  }


  return 0;
}