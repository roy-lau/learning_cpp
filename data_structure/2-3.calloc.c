/**
 * @file 2-3.calloc.c
 * @author RoyLau (897379293@qq.com)
 * @brief calloc 分配并清零内存
 * @link https://zh.cppreference.com/w/c/memory/calloc
 * @version 0.1
 * @date 2022-06-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *p1 = calloc(4, sizeof(int));    // 分配并清零 4 个 int 的数组
  int *p2 = calloc(1, sizeof(int[4])); // 等价，直接命名数组类型
  int *p3 = calloc(4, sizeof * p3);     // 等价，免去重复类型名

  if (p2) {
    for (int n = 0; n < 4; ++n) // 打印数组
      printf("p2[%d] == %d\n", n, p2[n]);
  }

  free(p1);
  free(p2);
  free(p3);
}