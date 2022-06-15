/**
 * @file oj-105.c
 * @author RoyLau (897379293@qq.com)
 * @brief 今天会下雨🌧吗？
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  double h;
  scanf("%lf", &h);
  printf("%s\n", h > 55.4 ? "YES" : "NO");
  return 0;
}