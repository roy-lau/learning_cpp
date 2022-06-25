/**
 * @file 2-4.realloc.c
 * @author RoyLau (897379293@qq.com)
 * @brief realloc 扩充之前分配的内存块
 * @link https://zh.cppreference.com/w/c/memory/realloc
 * @version 0.1
 * @date 2022-06-25
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *pa = malloc(10 * sizeof * pa); // 分配 10 个 int 的数组
  if (pa) {
    printf("%zu bytes allocated. Storing ints: ", 10 * sizeof(int));
    for (int n = 0; n < 10; ++n)
      printf("%d ", pa[n] = n);
  }

  int *pb = realloc(pa, 1000000 * sizeof * pb); // 重分配数组更大的大小
  if (pb) {
    printf("\n%zu bytes allocated, first 10 ints are: ", 1000000 * sizeof(int));
    for (int n = 0; n < 10; ++n)
      printf("%d ", pb[n]); // 展示数组
    free(pb);
  } else { // 若 realloc 失败，则需要返回原指针
    free(pa);
  }
}