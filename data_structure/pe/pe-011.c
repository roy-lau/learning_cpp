/**
 * @file pe-011.c
 * @author RoyLau (897379293@qq.com)
 * @brief 方阵中的最大乘积
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int num[30][30], ans;
int dirx[4] = { -1,0,1,1 };
int diry[4] = { 1,1,1,0 };

int main() {
  // 有 bug，输入有问题

  // 从(5,5) 开始 存入 20*20 的数组
  for (int i = 5;i < 25;i++) {
    for (int j = 5;j < 25;j++) {
      scanf("%d", &num[i][j]);
    }
  }

  // 以每一个点为起点
  for (int i = 5;i < 25;i++) {
    for (int j = 5;i < 25;j++) {
      // 第 k 个方向
      for (int k = 0;k < 4;k++) {
        int t = num[i][j];
        // 走 3 步，乘连续的 3 个元素
        for (int l = 1;l < 4;l++) {
          int x = i + dirx[k] * l;
          int y = j + diry[k] * l;
          t *= num[x][y];
        }
        if (t > ans) {
          ans = t;
        }
      }
    }
  }

  printf("%d\n", ans); // 70600674
  return 0;
}