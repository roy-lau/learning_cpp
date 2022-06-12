/**
 * @file 1-2.sprintf.c
 * @author RoyLau
 * @brief sprintf 函数
 * @version 0.1
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main() {

  // char str[100] = { 0 }; // 定义字符串数组，并清空。
  // int n;
  // scanf("%d", &n);
  // printf("%d\n", sprintf(str, "%d", n));
  // printf("str = %s\n", str);

  char ip[10] = { 0 };
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  sprintf(ip, "%d.%d.%d.%d", a, b, c, d);
  printf("ip = %s\n", ip);

  return 0;
}