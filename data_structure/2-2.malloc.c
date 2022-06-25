/**
 * @file 2-2.malloc.c
 * @author RoyLau (897379293@qq.com)
 * @brief malloc 分配内存
 * @link https://zh.cppreference.com/w/c/memory/malloc
 * @version 0.1
 * @date 2022-06-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>   
#include <stdlib.h> 

typedef struct x {
  int a, b, c;
}X;


int main(void) {
  int *p1 = malloc(4 * sizeof(int));  // 足以分配 4 个 int 的数组
  int *p2 = malloc(sizeof(int[4])); // 等价，直接命名数组类型
  int *p3 = malloc(4 * sizeof * p3);   // 等价，免去重复类型名

  if (p1) {
    for (int n = 0; n < 4; ++n) // 置入数组
      p1[n] = n * n;
    for (int n = 0; n < 4; ++n) // 打印出来
      printf("p1[%d] == %d\n", n, p1[n]);
  }

  free(p1);
  free(p2);
  free(p3);

  X *t = (X *)malloc(sizeof(X));
  t->a = 1;
  t->b = 2;
  t->c = 3;
  printf("t->a = %d, t->b = %d, t->c = %d\n", t->a, t->b, t->c);
  free(t);

}