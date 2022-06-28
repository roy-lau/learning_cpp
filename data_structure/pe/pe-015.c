/**
 * @file pe-015.c
 * @author RoyLau (897379293@qq.com)
 * @brief 网格路径
 * @version 0.1
 * @date 2022-06-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

long long ans[25][25];

int main() {
  // 方法一：
  // int n; // 20
  // scanf("%d", &n);

  // for (int x = 1;x <= n + 1;x++) {
  //   for (int y = 1;y <= n + 1;y++) {
  //     if (x == 1 || y == 1) {
  //       ans[x][y] = 1;
  //     } else {
  //       ans[x][y] = ans[x - 1][y] + ans[x][y - 1];
  //     }
  //   }
  // }
  // printf("%lld\n", ans[n + 1][n + 1]);

  // 方法二：
  long long num = 1;
  for (int i = 40, j = 1;i > 20;i--, j++) {
    num *= i;
    num /= j;
  }
  printf("%lld\n", num);

  return 0;
}