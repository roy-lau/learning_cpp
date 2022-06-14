/**
 * @file 8-1.while.c
 * @author RoyLau (897379293@qq.com)
 * @brief while 循环
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int i = 1;
  // <= 是两次判断，一次判断是否小于，一次判断是否等于
  while (i < 101) {
    printf("%d\n", i++);
  }
  // do {
  //   printf("%d\n", i++);
  // } while (i < 101);

  return 0;
}