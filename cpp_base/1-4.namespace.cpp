/**
 * @file 1-4.namespace.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 命名空间
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

namespace my {
  int a = 8;
  void sayHi() {
    cout << "Hi" << endl;
  }
}

int a = 5;
int main() {
  int a = 6;

  if (1) {
    int a = 7;
    cout << a << endl; // 7 <= 当前作用域
  }

  cout << a << endl; // 6 <= 默认作用域
  cout << ::a << endl; // 5 <= 全局区
  cout << my::a << endl; // 8 <= my 命名空间
  ::a = 99;
  cout << ::a << endl; // 99 <= 全局区修改后的值
  my::sayHi();

  return 0;
}