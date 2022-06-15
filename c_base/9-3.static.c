/**
 * @file 9-3.static.c
 * @author RoyLau (897379293@qq.com)
 * @brief 学习理解 static 关键字
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

void func() {
  int a = 0;
  a++;
  printf("func in a = %d\n", a);

  // static int b = 0;
  // b++;
  // printf("func in b = %d\n", b);
}

int main() {
  for (int i = 0; i < 6;++i) {
    func();
  }
  return 0;
}