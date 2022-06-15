/**
 * @file oj-120.c
 * @author RoyLau (897379293@qq.com)
 * @brief 日期合法性
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int check(int y, int m, int d) {
  if (m < 1 || m > 12) return 0; // 限定传入 月 的范围
  if (d < 1 || d > 31) return 0; // 限定传入 日 的范围

  // 穷举每月的天数
  int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };
  // 闰年的二月增加一天
  if ((y % 4 == 0 && y % 100) || y % 400 == 0) month[2] += 1;
  return d <= month[m];

}

int main() {
  int y, m, d; // 年 月 日
  scanf("%d%d%d", &y, &m, &d);
  printf("%s\n", check(y, m, d) ? "YES" : "NO");
  return 0;
}