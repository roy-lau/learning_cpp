/**
 * @file 2-7.set.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 集合的使用
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <set>
using namespace std;


struct node {
  int x, y;
  bool operator< (const node &t) const {
    return this->x < t.x;
  }
};


int main() {
  cout << "int 类型集合：" << endl;
  set<int, greater<int> > s; // 默认 less 从小到大，greater 从大到小
  s.insert(6);
  s.insert(4);
  s.insert(3);
  s.insert(5);
  s.insert(2);
  cout << "size : " << s.size() << endl;
  s.insert(6); // 已存在，不再插入
  cout << "size : " << s.size() << endl;
  cout << (s.count(5) ? "5 yes" : "5 no") << endl;

  s.erase(5);
  s.erase(5);
  cout << "size : " << s.size() << endl;
  cout << (s.count(5) ? "5 yes" : "5 no") << endl;

  // 下面两种方法需要 c++11 才支持， --std=c++11

  for (auto &x : s) {
    cout << x << " ";
  }
  cout << endl;

  for (auto it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;


  cout << endl << "自定义 类型集合：" << endl;
  set<node> s1;
  s1.insert((node) { 9, 8 });
  s1.insert((node) { 3, 2 });
  s1.insert((node) { 5, 4 });
  s1.insert((node) { 1, -2 });
  s1.insert((node) { 7, 6 });
  node t = (node){ 9,8 };
  cout << (s1.count(t) ? "find !" : "no find !") << endl;

  for (auto &n : s1) {
    cout << n.x << " " << n.y << endl;
  }


  return 0;

}