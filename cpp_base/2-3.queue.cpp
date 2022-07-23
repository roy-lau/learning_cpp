/**
 * @file 2-3.queue.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 队列的使用
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct node {
  string s;
  double d;
};


void output(queue<char> q) {
  cout << "size : " << q.size() << endl;
  while (!q.empty()) {
    cout << q.front() << " " << q.back() << endl;
    q.pop();
  }
  cout << endl << endl;
}

void output(queue<node> q) {
  cout << "size : " << q.size() << endl;
  while (!q.empty()) {
    cout << q.front().s << " " << q.front().d << endl;
    q.pop();
  }
  cout << endl;
}


int main() {
  cout << "char 类型队列：" << endl;
  queue<char> q;
  q.push('c');
  q.push('n');
  q.push('m');
  q.push('!');
  output(q);

  cout << "自定义 类型队列：" << endl;
  queue<node> que;
  que.push((node) { "hell", 2.5 });
  que.push((node) { "hi", 3.6 });
  que.push((node) { "{}<>[]", 4.7 });
  que.push((node) { "  ~ ", -1.2 });
  output(que);


  return 0;
}