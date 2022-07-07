/**
 * @file 11-6.floyd.c
 * @author RoyLau (897379293@qq.com)
 * @brief 最短路径求解方法 -- Floyd 算法（多源最短路）
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 * @输入示例：
 * 6 9 1
 * 1 2 1
 * 1 3 10
 * 2 3 8
 * 2 4 1
 * 3 4 2
 * 3 5 1
 * 4 5 5
 * 4 6 3
 * 5 6 10
 *
 */
#include <stdio.h>
#include <string.h>

 /**
  * @param n 点
  * @param m 边
  * @param s 起点
  * @param arr 邻接矩阵
  */
int n, m, s, arr[105][105];

int main() {
  memset(arr, 0x3F, sizeof(arr));
  scanf("%d%d%d", &n, &m, &s);

  // 初始化数据
  for (int i = 0; i < m;i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (arr[a][b] > c) {
      arr[a][b] = arr[b][a] = c;
    }
  }

  // 自己到自己的最短路
  for (int i = 1;i <= n; i++) {
    arr[i][i] = 0;
  }

  // floyd 算法核心
  for (int i = 1;i <= n;i++) {
    for (int j = 1;j <= n;j++) {
      for (int k = 1;k <= n;k++) {
        if (arr[j][k] > arr[j][i] + arr[i][k]) {
          arr[j][k] = arr[j][i] + arr[i][k];
        }
      }
    }
  }

  // 打印最短路
  for (int i = 1;i <= n;i++) {
    printf("%d -> %d = %d\n", s, i, arr[s][i]);
  }
  // 打印连接矩阵
  for (int i = 1;i <= n;i++) {
    printf("%d : ", i);
    for (int j = 1;j <= n;j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}