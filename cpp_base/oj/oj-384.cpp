/**
 * @file oj-384.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 敲七
 * @version 0.1
 * @date 2022-07-24
 * @link http://oj.haizeix.com/problem/384
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <queue>
using namespace std;


int is_about7(int t) {
  if (t % 7 == 0) return 0;
  while (t != 0) {
    if (t % 10 == 7) return 0;
    t /= 10;
  }
  return 1;
}

int main() {
  int n, x, t;
  cin >> n >> x >> t;
  queue<int> que;
  for (int i = x;i <= n;i++) {
    que.push(i);
  }
  for (int i = 1; i < x;i++) {
    que.push(i);
  }
  /**
    for(int i = 0, j = x; i < n; i++,j++){
      if(j > n ) j = 1;
      que.push(j);
    }
   */
  while (que.size() != 1) {
    if (is_about7(t)) {
      que.push(que.front());
    }
    que.pop();
    t++;
  }
  cout << que.front() << endl;
}