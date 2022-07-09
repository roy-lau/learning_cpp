/**
 * @file 1-2.c_cpp_cite.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief c与 c++ 引用
 * @version 0.1
 * @date 2022-07-07
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <cstdio>
using namespace std;



/**
 * @brief C 语言交换函数
 *
 * @param a
 * @param b
 */
void c_swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

/**
 * @brief C++ 语言交换函数
 *
 * @param a
 * @param b
 */
void cpp_sqap(int &a, int &b) { // 引用传参
  int t = a;
  a = b;
  b = t;
}


int main() {
  // C
  int a = 5;
  int *b = &a;
  *b = 6;
  printf("%d %d\n", a, *b);

  // C++
  int x = 5;
  int &y = x;
  y = 6;
  cout << x << " " << y << endl;
  return 0;
}