/**
 * @file 9-4.func_pointer.c
 * @author RoyLau (897379293@qq.com)
 * @brief 指针函数，分段函数
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int test1(int x) {
  return x * x;
}
int test2(int x) {
  return x * 2;
}

int func(int (*f1)(int), int (*f2)(int), int x) {
  if (x < 0) return f1(x);
  return f2(x);
}

int main() {
  int x;
  while (~scanf("%d", &x)) {
    printf("func(%d) = %d\n", x, func(test1, test2, x));
  }

}