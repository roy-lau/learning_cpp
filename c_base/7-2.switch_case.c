/**
 * @file 7-2.switch_case.c
 * @author RoyLau (897379293@qq.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

int main(){
  int n;
  scanf("%d",&n);

  switch (n) {
  case 1:
    printf("one\n");
    break;
  case 2:
    printf("two\n");
    break;
  case 3:
    printf("three\n");
    break;
  
  default:
    printf("error\n");
    break;
  }
  return 0;
}