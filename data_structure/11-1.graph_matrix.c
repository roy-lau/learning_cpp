/**
 * @file 11-1.graph.c
 * @author RoyLau (897379293@qq.com)
 * @brief 图的存储 - 邻接矩阵
 * @version 0.1
 * @date 2022-07-05
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
 // 输入：
 // 8 10
 // 1 3
 // 3 4
 // 4 6
 // 6 7
 // 7 5
 // 5 8
 // 2 8
 // 1 2
 // 2 4
 // 4 5

int n, m, matrix[105][105]; // n 点，m 边。 matrix 矩阵（实际情况下需要用结构体来做）

int main() {
  scanf("%d%d", &n, &m);
  // 构建邻接矩阵
  for (int i = 0; i < m;i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    matrix[x][y] = matrix[y][x] = 1;
  }

  // 打印邻接矩阵间的关系
  for (int i = 1;i <= n;i++) {
    printf("%d : ", i);
    for (int j = 1;j <= n;j++) {
      if (matrix[i][j]) printf("[%d --> %d] ", i, j);
    }
    printf("\n");
  }

  // 打印矩阵图
  for (int i = 1; i <= n;i++) {
    for (int j = 1;j <= n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}