/**
 * @file oj-379.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 仓库日志
 * @version 0.1
 * @date 2022-07-24
 * @link http://oj.haizeix.com/problem/379
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> sta, mmax;
  mmax.push(0);
  int n;
  cin >> n;
  for (int i = 0;i < n;i++) {
    int t;
    cin >> t;
    if (t == 0) {
      cin >> t;
      sta.push(t);
      mmax.push(max(mmax.top(), t));
    } else if (t == 1) {
      if (!sta.empty()) {
        sta.pop();
        mmax.pop();
      }
    } else {
      cout << mmax.top() << endl;
    }
  }

  return 0;
}