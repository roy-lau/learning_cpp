/**
 * @file oj-113.c
 * @author RoyLau (897379293@qq.com)
 * @brief 一个月有多少天
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int y, m; // 年 月
  scanf("%d%d", &y, &m);
  // 穷举每月的天数
  int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };
  // 闰年的二月增加一天
  if ((y % 4 == 0 && y % 100) || y % 400 == 0) month[2] += 1;

  printf("%d\n", month[m]);
  return 0;
}