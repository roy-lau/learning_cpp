/**
 * @file oj-112.c
 * @author RoyLau (897379293@qq.com)
 * @brief 按要求输出
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  char x;
  scanf("%s", &x);
  switch (x) {
    case 'a':
      printf("It is good\n");
      break;
    case 'b':
      printf("OMG\n");
      break;
    case 'c':
      printf("Yes!\n");
      break;
  }
  return 0;
}