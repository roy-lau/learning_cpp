/**
 * @file 10-1.sequential_search.c
 * @author RoyLau (897379293@qq.com)
 * @brief 线性查找
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sequential_search(int *num, int n, int x) {
  for (int i = 0;i < n;i++) {
    if(num[i] == x) {
      printf("--> %d\n", i);
      return;
    }
  }
  printf("not find\n");
}


int main() {
  srand(time(0));
  int n = 20, num[105], temp[105];
  for (int i = 0;i < n;i++) {
    num[i] = rand() % 100;
    i &&printf(", ");
    printf("%d", num[i]);
  }
  printf("\n");

  int x;
  while (~scanf("%d", &x)) {
    sequential_search(num, n, x);
  }

  printf("\n");
  return 0;
}