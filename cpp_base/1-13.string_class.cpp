/**
 * @file 1-13.string_class.c
 * @author RoyLau (897379293@qq.com)
 * @brief 实现 `my_string` 类
 * @version 0.1
 * @date 2022-07-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <cstring>
using namespace std;

class my_string {
private:
  int len;
  char *p;

public:
  my_string() : len(0), p(NULL) {}
  friend istream &operator>> (istream &in, my_string &s);
  friend ostream &operator<< (ostream &out, my_string &s);

};

// 重载 cin >> 右移运算符
istream &operator>> (istream &in, my_string &s) {
  if (s.len != 0) free(s.p);
  s.p = (char *)calloc(10005, 1);
  in >> s.p;
  s.len = strlen(s.p);
  return in;
}

// 重载 cout << 左移运算符
ostream &operator<< (ostream &out, my_string &s) {
  if (s.len != 0) out << s.p;
  return out;
}

int main() {
  my_string s;
  cin >> s;
  cout << s << endl;

  return 0;
}