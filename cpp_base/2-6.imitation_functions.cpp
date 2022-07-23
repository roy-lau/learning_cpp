/**
 * @file 2-6.imitation_functions.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 仿函数
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 * @编译时需要加 --std=c++11
 */
#include <iostream>
using namespace std;

struct my_less {
  bool operator()(int a, int b) {
    return a < b;
  }
};

struct my_add {
  bool operator()(int a, int b) {
    return a + b;
  }
};

int main() {
  int a, b;
  cin >> a >> b;
  if (my_less{}(a, b)) {
    cout << "a less than b" << endl;
  } else {
    cout << "b less than a" << endl;
  }

  // cout << my_add{}(a, b) << endl;

  return 0;
}