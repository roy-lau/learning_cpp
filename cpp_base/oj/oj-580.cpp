/**
 * @file oj-580.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 明明的随机数
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 * 
 * @input
  10
  20 40 32 67 40 20 89 300 400 15
 */
#include <iostream>
#include <set>
using namespace std;

int main() {
  int cont, n;
  cin >> cont;
  set<int> s;
  for (int i = 0;i < cont;i++) {
    cin >> n;
    s.insert(n);
  }

  cout << s.size() << endl;
  for (auto x : s) {
    cout << x << " ";
  }

}