/**
 * @file 1-1.c_cpp_in_out.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief c 与 cpp 的输入输出对比
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <cstdio>
using namespace std;


int main() {
  int x;
  double y;
  printf("C语言输入一个整型一个双精度浮点型：\n");
  scanf("%d", &x);
  scanf("%lf", &y);
  // scanf("%g",&y); // 去 0
  printf("%d %lf\n\n", x, y);

  printf("C++语言输入一个整型一个双精度浮点型：\n");
  cin >> x;
  cin >> y;
  // cin >> x >> y;
  cout << x << " " << y << endl;

  return 0;

}