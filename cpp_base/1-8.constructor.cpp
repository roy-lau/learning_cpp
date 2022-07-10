/**
 * @file 1-8.constructor.c
 * @author RoyLau (897379293@qq.com)
 * @brief 构造函数
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
using namespace std;

class Node {
public:
  int x, y;
  /**
   * @brief 默认构造函数（和类同名的构造函数会直接被调用）
   *
   */
  Node() : x(10), y(20) {
    cout << "default constructor output: ";
    // this->x = this->y = -1;
  }
  /**
   * @brief 有参构造函数
   *
   * @param a
   * @param b
   */
  Node(int a, int b) :x(a), y(b) {
    cout << "params constructor output: ";
  }
  /**
   * @brief 拷贝构造函数（主要就是传入的参数）
   * 
   * @param a 
   */
  Node(const Node &a) :x(a.x), y(a.y) {
    cout << "copy constructor output: ";
    this->x++;
    this->y++;
  }

};

int main() {
  Node t; // 默认
  cout << t.x << " " << t.y << endl;
  Node t1(2, 3); // 有参
  cout << t1.x << " " << t1.y << endl;
  Node t2(t); // 拷贝
  cout << t2.x << " " << t2.y << endl;

  return 0;
}