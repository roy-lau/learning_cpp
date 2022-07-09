/**
 * @file 1-6.sort_struct.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 结构体排序
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 * @输入示例：
 * 5
 * 5 55
 * 4 89
 * 5 12
 * 4 17
 * 5 99
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
  int x, y;
};
// 如果 x 一致，按照 y 从大到小排序
// 默认按照 x 从小到大排序
bool cmp(const node &a, const node &b) {
  if (a.x == b.x) return a.y > b.y;
  return a.x < b.x;
}

int main() {
  int n;
  node t[105];
  cin >> n;
  for (int i = 0;i < n;i++) {
    cin >> t[i].x >> t[i].y;
  }
  cout << endl;
  sort(t, t + n, cmp);

  for (int i = 0; i < n; i++) {
    cout << t[i].x << " " << t[i].y << endl;
  }
}