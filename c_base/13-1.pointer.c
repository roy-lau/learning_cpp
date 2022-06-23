/**
 * @file 13-1.pointer.c
 * @author RoyLau (897379293@qq.com)
 * @brief 理解指针
 * @version 0.1
 * @date 2022-06-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int a = 5;
  int *p = &a;
  *p = 6;
  printf("%p\n", &p);
  printf("%p\n", p);
  printf("%d\n", *p);
  printf("%d\n", a);
}