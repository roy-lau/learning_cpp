/**
 * @file oj-114.c
 * @author RoyLau (897379293@qq.com)
 * @brief 他的名字
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
    case 'h':
      printf("He\n");
      break;
    case 'l':
      printf("Li\n");
      break;
    case 'c':
      printf("Cao\n");
      break;
    case 'd':
      printf("Duan\n");
      break;
    case 'w':
      printf("Wang\n");
      break;
    default:
      printf("Not Here\n");
  }
  return 0;
}