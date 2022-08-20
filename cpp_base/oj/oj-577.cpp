/**
 * @file oj-577.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 讲话模式
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<string, int> m;
  string temp;
  while (cin >> temp) {
    for (auto &c : temp) {
      if (c >= 'A' && c <= 'Z') {
        c += 'a' - 'A';
      }
    }
    m[temp]++;
  }
  string ans;
  int cnt = 0;
  for (auto &x : m) {
    if (x.second > cnt) {
      ans = x.first;
      cnt = x.second;
    }
  }
  cout << ans << " " << cnt << endl;
  return 0;
}