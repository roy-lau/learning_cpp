/**
 * @file 1-11.sort_overload.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 排序重载
 * @version 0.1
 * @date 2022-07-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Node {
public:
  int x, y;
  // 排序重载，只能重载小于号
  bool operator< (const Node &b) const {
    if (this->x == b.x)return this->y > b.y;
    return this->x < b.x;
  }
};

int main() {
  int n;
  Node num[105];
  cin >> n;
  for (int i = 0;i < n;i++) {
    num[i].x = rand() % 100;
    num[i].y = rand() % 100;
  }

  sort(num, num + n);

  cout << endl;
  for (int i = 0;i < n;i++) {
    cout << num[i].x << " " << num[i].y << endl;
  }
  return 0;
}