/**
 * @file oj-464.c
 * @author RoyLau (897379293@qq.com)
 * @brief 统计闰年
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
int check(int y) {
  return (y % 4 == 0 && y % 100) || (y % 400 == 0);
}
int main() {
  int x, y, cont = 0;
  scanf("%d%d", &x, &y);
  while (x <= y) {
    cont += check(x);
    x++;
  }
  printf("%d\n", cont);

  return 0;
}