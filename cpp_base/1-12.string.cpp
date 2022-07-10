/**
 * @file 1-12.string.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 字符串
 * @version 0.1
 * @date 2022-07-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <string>
using namespace std;

int main() {
  // 字符串定义
  string s;
  s = "abcdef";
  string a = s;
  // 字符串拼接
  string b = s + "_" + a;
  cout << "s = " << s << endl;
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;

  // 字符串修改
  b[5] = '?';
  b[7] = '!';
  cout << "b = " << b << endl;

  // 字符串查找(npos == no postion)
  if (b.find("cd") != string::npos) { // 在 b 中查找字符串 'cd', 是否存在
    cout << "'cd' in b at ind = " << b.find("cd") << endl;
  }
  if (b.find("cd", 3) != string::npos) { // 在 b 中从下标 3 开始查找字符串 'cd', 是否存在
    cout << "not find 'cd' in b" << endl;
  }

  // 字符串截取，从 2 开始，截取到下标 10。
  string c = b.substr(2, 10);
  cout << "c.substr = " << c << endl;

  // 字符串插入， 从下标 1 插入 ###
  c = c.insert(1, "###");
  cout << "c.insert = " << c << endl;

  // 字符串替换。从下标 2 到 5，替换成 @@@
  c.replace(2, 5, "@@@");
  cout << "c.replace = " << c << endl;

  // 字符串构造函数
  string r(50, '#');
  cout << "r = " << r << endl;

  // \0 长度的坑
  string n = "0123456789";
  cout << n << " n.size = " << n.size() << endl;
  n[5] = '\0';
  cout << n << " n.size = " << n.size() << endl;

  return 0;
}