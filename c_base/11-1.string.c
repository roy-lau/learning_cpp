/**
 * @file 11-1.string.c
 * @author RoyLau (897379293@qq.com)
 * @brief 字符串操作
 * @version 0.1
 * @date 2022-06-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <string.h>

int main(){
  char str[100] = "hello world";
  printf("sizeof(str) = %lu\n", sizeof(str)); // 空间大小
  printf("strlen(str) = %lu\n", strlen(str)); // 字符串长度，不算 '\0'


  return 0;
}