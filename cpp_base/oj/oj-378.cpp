/**
 * @file oj-378.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 字符串括号匹配2
 * @version 0.1
 * @date 2022-07-24
 * @link http://oj.haizeix.com/problem/378
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <stack>
using namespace std;


int main() {
  stack<char> sta;
  char s[305];

  cin >> s;
  for (int i = 0; s[i] != '@'; i++) {
    if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
      sta.push(s[i]);
    } else if (s[i] == ')') {
        if (!sta.empty() && sta.top() == '(') {
          sta.pop();
        } else {
          cout << "NO" << endl;
          return 0;
        }
      } else if (s[i] == ']') {
        if (!sta.empty() && sta.top() == '{') {
          sta.pop();
        } else {
          cout << "NO" << endl;
          return 0;
        }
      } else if (s[i] == '}') {
        if (!sta.empty() && sta.top() == '{') {
          sta.pop();
        } else {
          cout << "NO" << endl;
          return 0;
        }
      }
  }

  cout << (sta.empty() ? "YES" : "NO") << endl;

  return 0;

}