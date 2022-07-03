/**
 * @file 9-1.insert_sort.c
 * @author RoyLau (897379293@qq.com)
 * @brief 插入排序
 * @version 0.1
 * @date 2022-07-03
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a,b) {__typeof(a) __temp = a; a = b; b = __temp;}


void insert_sort(int *num, int n) {
  for (int i = 0;i < n;i++) {
    for (int j = i; j < n;j++) {
      if (num[i] > num[j]) swap(num[i], num[j]);
    }
  }
}

int main() {
  srand(time(0));
  int n, num[105];
  scanf("%d", &n);
  for (int i = 0;i < n;i++) {
    num[i] = rand() % 100;
    i &&printf(", ");
    printf("%d", num[i]);
  }
  printf("\n");

  insert_sort(num, n);
  for (int i = 0;i < n;i++) {
    i &&printf(", ");
    printf("%d", num[i]);
  }
  printf("\n");
  return 0;
}