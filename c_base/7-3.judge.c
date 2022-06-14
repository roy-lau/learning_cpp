/**
 * @file 7-3.judge.c
 * @author RoyLau (897379293@qq.com)
 * @brief 输出 随机数 奇数个数
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int n, cont = 0;
  scanf("%d", &n);
  for (int i = 0;i < n;i++) {
    int val = rand() % 100; // 生成 [0,100) 的随机数
    cont += (val & 1); // 累加 奇数 的个数
    i &&printf(", ");
    printf("%d", val);
  }
  printf("\n");
  printf("cont = %d\n", cont);
  return 0;
}