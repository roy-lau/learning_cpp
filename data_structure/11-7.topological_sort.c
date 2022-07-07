/**
 * @file 11-7.topological_sort.c
 * @author RoyLau (897379293@qq.com)
 * @brief 图 -- 拓扑排序
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 * @输入示例：
 * 6 6
 * 3 5
 * 4 1
 * 5 2
 * 1 2
 * 2 6
 * 1 6
 */
#include <stdio.h>

 /**
  * @param n 点
  * @param m 边
  * @param arr 邻接矩阵
  * @param in_degree 入度数组
  * @param mark 标记数组
  * @param ans 答案数组
  */
int n, m, arr[105][105], in_degree[105], mark[105], ans[105];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0;i < m;i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    arr[a][b]++;
    in_degree[b]++;
  }

  for (int i = 0;i < n;i++) {
    int ind = 0;
    for (int j = 1;j <= n;j++) {
      if (in_degree[j] == 0 && mark[j] == 0) {
        ind = j;
        break;
      }
    }
    if (ind == 0) break;
    ans[i] = ind;
    // mark[ind] = 1;
    for (int j = 1;j <= n;j++) {
      in_degree[j] -= arr[ind][i];
    }
  }

  if (ans[n - 1] == 0) {
    printf("-1\n");
  } else {
    for (int i = 0;i < n;i++) {
      i &&printf("--");
      printf("%d", ans[i]);
    }
    printf("\n");
  }

  return 0;
}