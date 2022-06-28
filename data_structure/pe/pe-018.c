/**
 * @file pe-018.c
 * @author RoyLau (897379293@qq.com)
 * @brief
 * @runing a.out < input18
 * @version 0.1
 * @date 2022-06-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int num[20][20], ans[20][20], max;

int main() {
  for (int i = 1;i <= 15;i++) {
    for (int j = 1;j <= i;j++) {
      scanf("%d", &num[i][j]);
    }
  }

  for (int i = 1;i <= 15;i++) {
    for (int j = 1;j <= i;j++) {
      ans[i][j] = (ans[i - 1][j] > ans[i - 1][j - 1] ? ans[i - 1][j] : ans[i - 1][j - 1]) + num[i][j];
      if (ans[i][j] > max) max = ans[i][j];
    }
  }

  printf("%d\n", max); // 1074

  return 0;
}