/**
 * @file 2-5.free.c
 * @author RoyLau (897379293@qq.com)
 * @brief free 归还之前分配的内存
 * @link https://zh.cppreference.com/w/c/memory/free
 * @version 0.1
 * @date 2022-06-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdlib.h>

int main(void) {
  int *p1 = malloc(10 * sizeof * p1);
  free(p1); // 每一个分配的指针都要释放

  int *p2 = calloc(10, sizeof * p2);
  int *p3 = realloc(p2, 1000 * sizeof * p3);
  if (p3) // p3 非空表示 p2 被 realloc 释放
    free(p3);
  else // p3 为空表示 p2 未被释放
    free(p2);
}