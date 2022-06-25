/**
 * @file 2-1.pointer.c
 * @author RoyLau (897379293@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-06-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

typedef struct x {
  int a;
  double b;
  char c, d[3];
} X;

int main() {
  /**
   * @brief 变量 指针
   *
   */
  int a = 5;
  int *p = &a;
  // *p = 6;
  printf("%d\n", *p); // *p 取的是地址中的值
  printf("%p\n", p); // 指针变量指向 a 元素的内存地址

  // int 类型占 4 字节内存，指针类型占 8 字节。
  printf("sizeof(a) = %lu, sizeof(p) = %lu\n", sizeof(a), sizeof(p)); // 4 8


  /**
   * @brief 数组指针
   *
   */
  int num[100];
  int *c = num; // 数组变量本身就是地址，所以不需要使用&取地址符。
  printf("num = %p\n", num);
  num[5] = 55;
  printf("num[5] = %d\n", num[5]);
  c[5] = 66;
  printf("num[5] = %d\n", num[5]);

  printf("c = %p\n", c);
  // printf("*c = %d\n", *c);
  printf("c[5] = %d\n", c[5]);
  printf("sizeof(num) = %lu, sizeof(c) = %lu\n", sizeof(num), sizeof(c)); // 400 8

  /**
   * @brief 结构体指针
   *
   */
  X t;
  t.a = 5;
  t.b = 3.14;
  t.c = '?';
  printf("t.a = %d, t.b = %lf, t.c = %c\n", t.a, t.b, t.c);
  X *pt = &t;
  pt->a = 6;
  pt->c = '!';
  printf("pt->a = %d, pt->b = %lf, pt->c = %c\n", pt->a, pt->b, pt->c);



  return 0;
}