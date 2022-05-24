/**
 * @file 17.quick_find.c
 * @author RoyLau
 * @brief 数据结构 - 森林与并查集
 * @version 0.1
 * @date 2022-05-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

 /**
  * @brief 并查集 - 结构定义
  *
  * @param *color 颜色
  * @param n 容量
  */
typedef struct UnionSet {
  int *color;
  int n;
} UnionSet;

/**
 * @brief 初始化
 *
 * @param n 长度
 * @return UnionSet* 并查集
 */
UnionSet *init(int n) {
  UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
  u->color = (int *)malloc(sizeof(int) * (n + 1));
  u->n = n;
  for (int i = 0; i <= n;i++) {
    u->color[i] = i;
  }
  return u;
}

/**
 * @brief 查找
 *
 * @param u 并查集
 * @param x 要查找的元素
 * @return int 查找到的元素
 */
int find(UnionSet *u, int x) {
  return u->color[x];
}

/**
 * @brief 合并
 *
 * @param u 并查集
 * @param a 待合并元素 a
 * @param b 待合并元素 b
 * @return int 是否合并成功。1 成功，0 失败
 */
int merge(UnionSet *u, int a, int b) {
  if (find(u, a) == find(u, b)) return 0;
  int clolor_a = u->color[a];
  for (int i = 1;i <= u->n;i++) {
    if (u->color[i] - clolor_a) continue;
    u->color[i] = u->color[b];
  }
  return 1;
}

/**
 * @brief 清除
 *
 * @param u 并查集
 */
void clear(UnionSet *u) {
  if (u == NULL) return;
  free(u->color);
  free(u);
  return;
}


// oj 71 题： http://oj.haizeix.com/problem/71
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  UnionSet *u = init(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    switch (a) {
      case 1: merge(u, b, c); break;
      case 2: printf("%s\n", find(u, b) == find(u, c) ? "Yes" : "No");break;
    }
  }
  clear(u);
  return 0;
}