/**
 * @file oj-90.c
 * @author RoyLau
 * @brief 取数位II
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  // 方法一：
  // int n;
  // scanf("%d", &n);
  // printf("%d\n", n / 100);
  // printf("%d\n", n / 10 % 10);
  // printf("%d\n", n % 10);

  // 方法二：
  char str[15] = { 0 };
  scanf("%s", str);
  for (int i = 0;str[i];i++) {
    printf("%c\n", str[i]);
  }
  return 0;
}