/**
 * @file 8-2.for.c
 * @author RoyLau (897379293@qq.com)
 * @brief for 循环
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int i = 1;
  for (;;) {
    if (i > 100) break; // break 可直接结束循环
    printf("%d\n", i++);
  }
  // for (int i = 1;i < 101;++i) {
  //   printf("%d\n", i);
  // }

  return 0;
}