/**
 * @file 11-2.graph_linkd.c
 * @author RoyLau (897379293@qq.com)
 * @brief 图的存储 - 邻接表
 * @version 0.1
 * @date 2022-07-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

// 输入样例：
// 8 10
// 1 2
// 2 7
// 7 6
// 6 5
// 5 4
// 4 3
// 3 8
// 8 6
// 8 7
// 3 1

int n, m, num[105][105];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m;i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    num[a][++num[a][0]] = b;
    num[b][++num[b][0]] = a;
  }

  for (int i = 1;i <= n;i++) {
    printf("%d : ", i);
    for (int j = 1;j <= num[i][0];j++) {
      printf("[%d --> %d]", i, num[i][j]);
    }
    printf("\n");
  }

  for (int i = 1;i <= n;i++) {
    printf("%d = ", i);
    for (int j = 1; j <= num[i][0];j++) {
      printf("%d ", num[i][j]);
    }
    printf("\n");
  }

  return 0;
}