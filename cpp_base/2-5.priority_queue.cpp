/**
 * @file 2-5.priority_queue.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 优先队列的操作
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
  int x, y;
  bool operator< (const node &n) const {
    return this->x > n.x; // 逻辑需要反着来
  }
};

struct cmp { // 仿函数
  bool operator() (const node &a, const node &b) {
    return a.x > b.x;
  }
};




void output(priority_queue<int> pq) {
  cout << "size : " << pq.size() << endl;
  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  cout << endl;
}
void output(priority_queue<int, vector<int>, greater<int> >  pq) {
  cout << "size : " << pq.size() << endl;
  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  cout << endl;
}

void output(priority_queue<string> pq) {
  cout << "size : " << pq.size() << endl;
  while (!pq.empty()) {
    cout << pq.top() << endl;
    pq.pop();
  }
  cout << endl;
}
void output(priority_queue<node> pq) {
  cout << "size : " << pq.size() << endl;
  while (!pq.empty()) {
    cout << pq.top().x << " " << pq.top().y << endl;
    pq.pop();
  }
  cout << endl;
}
void output(priority_queue<node, vector<node>, cmp> pq) {
  cout << "size : " << pq.size() << endl;
  while (!pq.empty()) {
    cout << pq.top().x << " " << pq.top().y << endl;
    pq.pop();
  }
  cout << endl;
}




int main() {
  cout << "int 类型大顶堆：" << endl;
  priority_queue<int> pq; // 默认是个大顶堆 less
  pq.push(5);
  pq.push(4);
  pq.push(1);
  pq.push(2);
  pq.push(3);
  output(pq);

  cout << "int 类型小顶堆：" << endl;
  priority_queue<int, vector<int>, greater<int> > pq1; // 小顶堆 greater
  pq1.push(5);
  pq1.push(4);
  pq1.push(1);
  pq1.push(2);
  pq1.push(3);
  output(pq1);

  cout << "string 类型大顶堆：" << endl;
  priority_queue<string> pq2; // 默认是个大顶堆 less
  pq2.push("abcd");
  pq2.push("<>");
  pq2.push("abc");
  pq2.push("001");
  pq2.push("ABC");
  output(pq2);

  cout << "自定义 类型大顶堆：" << endl;
  priority_queue<node> pq3; // 默认是个大顶堆 less
  // priority_queue<node, vector<node>, cmp> pq3; // 默认是个大顶堆 less
  pq3.push((node) { 1, 2 });
  pq3.push((node) { 8, 9 });
  pq3.push((node) { 5, 6 });
  output(pq3);

  return 0;
}