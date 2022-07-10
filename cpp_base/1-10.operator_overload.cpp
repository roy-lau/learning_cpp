/**
 * @file 1-10.operator_overload.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 运算符重载
 * @version 0.1
 * @date 2022-07-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

class Node {
public:
  int x, y;
  Node() : x(0), y(0) {}
  Node(int a, int b) : x(a), y(b) {}
  Node(const Node &n) {
    this->x = n.x, this->y = n.y;
  }
  // 运算符重载函数(对象规则)
  Node operator-(const Node &a) {
    Node t(*this);
    t.x -= a.x;
    t.y -= a.y;
    return t;
  }
};

// 运算符重载函数(全局规则)
Node operator+(const Node &a, const Node &b) {
  Node t;
  t.x = a.x + b.x;
  t.y = a.y + b.y;
  return t;
}

int main() {
  Node a(10, 20);
  Node b(3, 4);
  Node c = a + b;
  cout << c.x << " " << c.y << endl;

  Node d = a - b;
  cout << d.x << " " << d.y << endl;
  return 0;
}