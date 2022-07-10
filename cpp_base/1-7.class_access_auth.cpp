/**
 * @file 1-7.class_access_auth.c
 * @author RoyLau (897379293@qq.com)
 * @brief cpp 类和成员类型
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

class node {
  // 私有变量，只能在 class 内部访问和修改
private:
  int x, y;
  // 公共变量，可以在外部访问和修改
public:
  void change_x(int val) {
    this->x = val;
  }
  void change_y(int val) {
    this->y = val;
  }
  void show_x() {
    cout << "x = " << x << endl;
  }
  int return_y() {
    return this->y;
  }
  void sayHi();
  friend void my_friend(node &t);
};

void node::sayHi() {
  cout << "hi" << endl;
}

void my_friend(node &t) {
  cout << "my_friend: " << t.x << " " << t.y << endl;
}

int main() {
  node t;
  t.change_x(5);
  t.change_y(6);
  t.show_x();
  cout << "y = " << t.return_y() << endl;
  t.sayHi();
  my_friend(t);

  return 0;
}