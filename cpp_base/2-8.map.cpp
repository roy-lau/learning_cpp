/**
 * @file 2-8.map.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 映射的使用
 * @version 0.1
 * @date 2022-07-24
 *
 * @copyright Copyright (c) 2022
 *
 *
 */
#include <iostream>
#include <map>
#include <utility> // pair 对 {first,second}
using namespace std;


struct node {
  int x, y;
  bool operator< (const node &t) const {
    return this->x < t.x;
  }
};

int main() {
  map<int, char> m;
  m.insert(make_pair(2, '?'));
  m[4] = '+';
  m[5] = 'A';
  m[6] = 'a';
  m[7] = '&';
  cout << (m.count(5) ? "5 is exist!" : "5 is no exist!") << endl; // 判断键为 5 的元素存不存在
  cout << "size : " << m.size() << endl;
  m[10] = 't';
  cout << "key = 10 value = " << m[10] << endl;
  m.erase(7);
  cout << (m.count(7) ? "7 is exist!" : "7 is no exist!") << endl;

  // 用中括号去判断一个不存在的key，cpp 会默认将这个元素的 value 设为空
  cout << endl << "Tips:" << endl;
  cout << "size : " << m.size() << endl;
  cout << (m[20] ? "20 is exist!" : "20 is no exist!") << endl;
  cout << "size : " << m.size() << endl;

  cout << endl << "遍历 map：" << endl;
  for (auto &x : m) {
    cout << x.first << " " << x.second << endl;
  }

  cout << endl << "自定义 类型映射:" << endl;
  map<int, node> m1;
  m1[3] = (node){ 10,8 };
  m1[5] = (node){ 6,5 };
  m1[7] = (node){ 4,3 };
  for (auto &x : m1) {
    cout << x.first << " " << x.second.x << " " << x.second.y << endl;
  }

  map<node, int> m2;
  m2[(node) { 1, 2 }] = 1;
  m2[(node) { 3, 4 }] = 2;
  m2[(node) { 5, 6 }] = 3;
  

  return 0;
}