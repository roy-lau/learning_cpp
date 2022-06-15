/**
 * @file oj-111.c
 * @author RoyLau (897379293@qq.com)
 * @brief 乘车费用
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
  if (n <= 3) {
    printf("%d\n", 14);
  } else {
    printf("%.1lf\n", 14 + (n - 3) * 2.3);
  }

  return 0;
}