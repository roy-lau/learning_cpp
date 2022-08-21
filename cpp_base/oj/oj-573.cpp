/**
 * @file oj-573.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 桐桐的新闻系统
 * @version 0.1
 * @date 2022-08-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <queue>
using namespace std;

struct node {
  int qnum, p, next;
  bool operator< (const node &b)const {
    if (this->next == b.next) {
      return this->qnum > b.qnum;
    }
    return this->next > b.next;
  }
};


int main() {
  char str[20];
  priority_queue<node> que;
  while (cin >> str) {
    if (str[0] == '#') break;
    int qnum, p;
    cin >> qnum >> p;
    que.push((node){ qnum,p,p });
  }

  int k;
  cin >> k;
  for (int i = 0; i < k;i++) {
    node temp = que.top();
    que.pop();
    cout << temp.qnum << endl;
    temp.next += temp.p;
    que.push(temp);
  }


  return 0;
}