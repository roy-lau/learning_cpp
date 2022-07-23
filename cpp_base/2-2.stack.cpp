/**
 * @file 2-2.stack.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 栈的使用
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <stack>
using namespace std;

struct node {
  int x, y;
};

void output(stack<double> sta) {
  while (!sta.empty()) {
    cout << sta.top() << " ";
    sta.pop();
  }
  cout << endl;
}

void output(stack<node> sta) {
  while (!sta.empty()) {
    cout << sta.top().x << " " << sta.top().y << " ";
    sta.pop();
  }
  cout << endl;
}

int main() {
  cout << "double 类型栈：\t";
  stack<double> sta;
  sta.push(2.3);
  sta.push(3.5);
  sta.push(4.6);
  output(sta);

  cout << "自定义 类型栈：\t";
  stack<node> sta_node;
  sta_node.push((node) { 3, 4 });
  sta_node.push((node) { 5, 6 });
  sta_node.push((node) { -1, 2 });
  output(sta_node);

  return 0;
}