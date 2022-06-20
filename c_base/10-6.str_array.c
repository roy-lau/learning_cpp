/**
 * @file 10-6.str_array.c
 * @author RoyLau (897379293@qq.com)
 * @brief 字符数组
 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  char str[] = "hello world";
  char str2[] = { 'h','e','l','l','o',' ','w','o','r','l','d' };
  printf("sizeof(str) = %lu\n", sizeof(str));
  printf("sizeof(str2) = %lu\n", sizeof(str2));

}