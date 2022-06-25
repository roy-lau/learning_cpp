/**
 * @file 1-2.spatial_complexity.c
 * @author RoyLau (897379293@qq.com)
 * @brief 空间复杂度示例
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main(){
  int num[10005]; // int 类型占用 4 个字节，10005*4 约等于 40,000，也就是 40kb

  int matrix[10005][10005]; // 10005 * 10005 * 4 = 100,000,000 * 4 = 400,000,000 也就是 400Mb

  return 0;
}