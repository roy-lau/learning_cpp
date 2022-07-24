/**
 * @file 2-9.unordered_set.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 无序集合的使用
 * @version 0.1
 * @date 2022-07-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

struct node {
  int x, y;
  bool operator== (const node &t)const {
    return this->x == t.x && this->y == t.y;
  }
};

struct my_hash {
  size_t operator() (const node &t) const {
    return hash<int>{}(t.x);
  }
};

int main() {
  cout << "string 类型的无序集合使用：" << endl;
  unordered_set<string> us;
  us.insert("haha~");
  us.insert("123");
  us.insert("^_^");
  cout << "size : " << us.size() << endl;
  cout << (us.count("haha~") ? "exist!" : "no exist!") << endl;
  cout << "size : " << us.size() << endl;
  for (auto &x : us) {
    cout << x << endl;
  }

  cout << "自定义 类型的无序集合使用：" << endl;
  unordered_set<node, my_hash> usn;
  usn.insert((node) { 3, 4 });
  usn.insert((node) { 8, 9 });
  usn.insert((node) { 6, 7 });
  for (auto &u : usn) {
    cout << u.x << " " << u.y << endl;
  }

  return 0;
}