/**
 * @file 11-4.prim.c
 * @author RoyLau (897379293@qq.com)
 * @brief 最小生成树算法 -- prim 算法（普里姆算法）（以点为基准）
 * @version 0.1
 * @date 2022-07-06
 *
 * @copyright Copyright (c) 2022
 *
 * @输入示例：
 * 6 9
 * 1 2 3
 * 1 3 7
 * 1 4 9
 * 3 4 5
 * 2 4 9
 * 2 5 12
 * 4 5 15
 * 4 6 10
 * 5 6 1
 * 输出：26
 */
#include <stdio.h>

 /**
  * @param n 点
  * @param m 边
  * @param ans 最小生成树的边权之和
  * @param cnt 标记数
  * @param mark 标记数组
  * @param arr 标记内部点
  */
int n, m, ans, cnt, mark[105], arr[105][105];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m;i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (arr[a][b] == 0 || arr[a][b] > c) { // 处理重复的边
      arr[a][b] = arr[b][a] = c;
    }
  }

  // 时间复杂度 O(n^3)
  cnt = 1;
  mark[1] = 1;
  while (1) {
    int min = 999999999, mind; // min 找最小的权重，mind 当前边连通的点
    for (int j = 1;j <= n;j++) { // j 是内部点
      if (mark[j] == 1) {
        for (int k = 1; k <= n;k++) { // k 是外部点
          // 权值最小，当前边必须存在
          if (mark[k] == 0 && min > arr[j][k] && arr[j][k]) {
            min = arr[j][k];
            mind = k;
          }
        }
      }
    }
    if(mind == 0) break;
    ans += min;
    mark[mind] = 1;
    cnt++;
    if (cnt == n) break;
  }

  if (cnt == n) printf("%d\n", ans);
  else printf("-1\n");


  return 0;
}