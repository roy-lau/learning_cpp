/**
 * @file 1-3.fun_overload.c
 * @author RoyLau (897379293@qq.com)
 * @brief 函数重载
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
using namespace std;

int add(int a, int b) {
  cout << "add_int：" << endl;
  return a + b;
}
// 使用默认参数时，要注意函数重载的二异性
// int add(int a, int b,int c=6) {
//   cout << "add_3_int：" << endl;
//   return a + b+c;
// }
double add(double a, double b) {
  cout << "add_double：" << endl;
  return a + b;
}


// 默认参数
void default_params(int a, int b, int c = 6) {
  cout << "a = " << a << "\nb = " << b << "\nc = " << c << endl;
}

int main() {
  // 函数重载
  int a, b;
  cin >> a >> b;
  cout << add(a, b) << endl;

  double x, y;
  cin >> x >> y;
  cout << add(x, y) << endl;

  // 默认参数
  default_params(1, 2);

  return 0;

}