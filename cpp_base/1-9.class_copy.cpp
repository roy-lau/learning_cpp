/**
 * @file 1-9.class_copy.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 类的深浅拷贝
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Node {
public:
  int n;
  char *s;
  Node() {
    this->n = 5;
    this->s = (char *)calloc(5, 1);
    s[0] = '!';
  };
  // 有参函数
  Node(int n, char *s) {
    this->n = n;
    this->s = (char *)calloc(strlen(s) + 1, 1);
    memcpy(this->s, s, strlen(s));
  }
  // 深拷贝
  Node(const Node &a) {
    this->n = a.n;
    this->s = (char *)calloc(strlen(a.s) + 1, 1);
    memcpy(this->s, a.s, strlen(a.s));
  }
  // 析构函数（用来释放空间）
  ~Node() {
    cout << "free" << endl;
    free(this->s); // 原始数据类型编译器会自动释放
  }
};

int main() {
  Node *n = new Node(66, "new-class");
  cout << n->n << " " << n->s << endl;
  delete n;

  // 默认是浅拷贝
  Node t;
  t.n = 10;
  t.s = (char *)calloc(8, 1);
  t.s[0] = 'A', t.s[1] = 'B', t.s[2] = 'C';
  cout << t.n << " " << t.s << endl;

  Node tt(t);
  cout << tt.n << " " << tt.s << endl;

  tt.n = 20;
  tt.s[0] = 'a', tt.s[1] = 'b', tt.s[2] = 'c';
  cout << tt.n << " " << tt.s << endl;

  cout << t.n << " " << t.s << endl; // 浅拷贝（会影响原来的值）输出 abc，深拷贝输出 ABC。


  return 0;
}