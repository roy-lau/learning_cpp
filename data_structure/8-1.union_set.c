/**
 * @file 8-1.union_set.c
 * @author RoyLau (897379293@qq.com)
 * @brief 并查集
 * @version 0.1
 * @date 2022-07-02
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int n, m, my_union[105];

// 初始化
void init(int x) {
  for (int i = 1;i <= x;i++) {
    my_union[i] = i;
  }
}

// 查找父节点
int find_fa(int x) {
  if (my_union[x] == x) return x;
  return my_union[x] = find_fa(my_union[x]); // 路径压缩优化，递归
}

// 合并
void merge(int x, int y) {
  int rootx = find_fa(x), rooty = find_fa(y);
  if (rootx != rooty) my_union[rootx] = rooty;
}

// 查询
int query(int x, int y) {
  int rootx = find_fa(x), rooty = find_fa(y);
  if (rootx == rooty) return 1;
  return 0;
}

int main() {
  scanf("%d%d", &n, &m);
  init(n);
  for (int i = 0;i < m;i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a == 0) {   // 合并
      merge(b, c);
    } else { // 查询
      if (query(b, a) == 1) {
        printf("%d and %d in same place\n", b, c);
      } else {
        printf("%d and %d not in same place\n", b, c);
      }

    }
  }
}