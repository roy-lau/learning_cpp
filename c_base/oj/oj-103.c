/**
 * @file oj-103.c
 * @author RoyLau (897379293@qq.com)
 * @brief 整除问题
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%s\n", a % b ? "NO" : "YES");

  return 0;
}