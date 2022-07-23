/**
 * @file 2-4.deque.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 双端队列的使用
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <deque>
using namespace std;


void output(deque<int> dq) {
  cout << "size : " << dq.size() << endl;

  while (!dq.empty()) {
    cout << "front : " << dq.front() << " back: " << dq.back() << endl;
    dq.pop_front();
    if (!dq.empty()) dq.pop_back();
  }

  cout << endl;
}

int main() {
  cout << "双端队列访问：" << endl;
  deque<int> dq;
  dq.push_front(1);
  dq.push_front(2);
  dq.push_back(3);
  dq.push_back(4);
  dq.push_front(5);
  output(dq);

  cout << "双端队列顺序访问：" << endl;
  deque<int> que;
  que.push_back(9);
  que.push_back(7);
  que.push_back(5);
  que.push_back(3);
  que.push_front(1);
  for (int i = 0; i < que.size(); ++i) {
    cout << que[i] << endl;
    que[i] = 0;
  }
  cout << "双端队列列表访问：" << endl;
  for (auto &x : que) {
    cout << x << endl;
  }
  return 0;

}