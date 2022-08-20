/**
 * @file oj-385.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 海港
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 * @input1
   3
   1 4 4 1 2 2
   2 2 2 3
   10 1 3
 * @output1
    3
    4
    4
 *
 */
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct node {
  int c, t;
};

int n, mark[10005], ans;

int main() {
  scanf("%d", &n);
  queue<node> que;
  for (int i = 0;i < n; i++) {
    int t;
    scanf("%d", &t);  // 来船了
    while (!que.empty() && t - que.front().t >= 86400) {
      mark[que.front().c]--;
      if (mark[que.front().c] == 0)  ans--; // 一天开外，离开的人
      que.pop();
    }
    int cnt;
    scanf("%d", &cnt);
    for (int j = 0; j < cnt; j++) {
      int c;
      scanf("%d", &c);
      mark[c]++;
      if (mark[c] == 1) ans++;  // 新来的人
      que.push((node) { c, t });
    }
    printf("\n");
    printf("--> %d\n", ans);
  }
}