/**
 * @file 7-1.opinon.c
 * @author RoyLau (897379293@qq.com)
 * @brief 成绩判断
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 0) printf("FOOLISH\n");
  else if (n < 60) printf("FAIL\n");
  else if (n < 75) printf("MEDIUM\n");
  else if (n >= 75) printf("GOOD\n");

  return 0;
}