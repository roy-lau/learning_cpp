/**
 * @file 11-5.dijkstra.c
 * @author RoyLau (897379293@qq.com)
 * @brief 最短路径求解方法 -- Dijkstra 算法（单源最短路）
 * @version 0.1
 * @date 2022-07-06
 *
 * @copyright Copyright (c) 2022
 *
 * @输入示例：
 * 6 9 1
 * 1 2 1
 * 1 3 10
 * 2 3 20
 * 2 4 3
 * 3 4 4
 * 3 5 2
 * 4 5 8
 * 4 6 1
 * 5 6 10
 */
#include <stdio.h>
#include <string.h>

 /**
  * @param n 点
  * @param m 边
  * @param s 起点
  * @param arr 二维数组
  * @param ans 结果数组
  * @param mark 标记数组
  */
int n, m, s, arr[1005][1005], ans[1005], mark[1005];


int main() {
  memset(ans, 0x3F, sizeof(ans));
  scanf("%d%d%d", &n, &m, &s);
  for (int i = 0;i < m;i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (arr[a][b] == 0 || arr[a][b] > c) {
      arr[a][b] = arr[b][a] = c;
    }
  }

  ans[s] = 0;
  for (int i = 1;i < n;i++) {
    int ind = 0;
    for (int j = 1;j <= n;j++) {
      if (mark[j] == 0 && ans[j] != 0x3F3F3f3F && (ind == 0 || ans[j] < ans[ind])) {
        ind = j;
      }
    }
    if (ind == 0) break;

    mark[ind] = 1;
    for (int j = 1;j <= n;j++) {
      if (arr[ind][j] && ans[j] > ans[ind] + arr[ind][j]) {
        ans[j] = ans[ind] + arr[ind][j];
      }
    }
  }

  for (int i = 1; i <= n;i++) {
    printf("%d -> %d = %d\n", s, i, ans[i]);
  }

  return 0;
}