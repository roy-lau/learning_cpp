/**
 * @file 11-3.kruskal.c
 * @author RoyLau (897379293@qq.com)
 * @brief 最小生成树算法 -- kruskal算法（克鲁斯卡尔算法）（以边为基准）
 * @version 0.1
 * @date 2022-07-06
 *
 * @copyright Copyright (c) 2022
 * @输入示例：
 * 6 9
 * 1 2 1
 * 2 5 2
 * 5 6 2
 * 4 6 1
 * 3 4 4
 * 1 3 5
 * 3 2 6
 * 2 4 7
 * 2 6 3
 * 返回 10
 */
#include <stdio.h>
#define swap(a,b) {__typeof(a) __temp = a; a = b; b = __temp;}

 /**
  * @brief 边
  *
  * @param s 起点
  * @param e 终点
  * @param v 权值
  */
typedef struct edge {
  int s, e, v;
} Edge;

// 存储边信息的数组
Edge edg[105];

/**
 * @param n 点
 * @param m 边
 * @param ans 最小生成树的边权之和
 * @param my_unions 并查集
 */
int n, m, ans, my_unions[105];


// 初始化并查集
void init_union() {
  for (int i = 1;i <= n;i++) {
    my_unions[i] = i;
  }
}

// 冒泡排序
void sort() {
  for (int i = 0; i < m - 1;i++) {
    for (int j = 0;j < m - i - 1;j++) {
      if (edg[j].v > edg[j + 1].v) {
        swap(edg[j].s, edg[j + 1].s);
        swap(edg[j].e, edg[j + 1].e);
        swap(edg[j].v, edg[j + 1].v);
      }
    }
  }
}



// 查找并查集的父节点
int find_fa(int x) {
  if (my_unions[x] == x) return x;
  return my_unions[x] = find_fa(my_unions[x]);
}


int main() {
  scanf("%d%d", &n, &m);


  // 初始化并查集
  init_union();


  // 给边赋值，开始、结束、权值
  for (int i = 0;i < m;i++) {
    int s, e, v;
    scanf("%d%d%d", &s, &e, &v);
    edg[i].s = s, edg[i].e = e, edg[i].v = v;
  }


  // 排序
  sort();


  int cnt = 1;
  // 遍历边
  for (int i = 0;i < m;i++) {
    int s = edg[i].s, e = edg[i].e;
    int fs = find_fa(s), fe = find_fa(e);
    if (fs != fe) { // 如果起点和终点不相连
      ans += edg[i].v; // 累计权值
      cnt++;
      my_unions[fs] = fe; // 合并两个边的集合
      if (cnt == n) break; // 累加的连接数 和节点数相同，跳出循环
    }
  }
  if (cnt == n) printf("%d\n", ans); // 输出权值之和
  else printf("-1\n");


  return 0;
}