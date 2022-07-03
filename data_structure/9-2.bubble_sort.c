/**
 * @file 9-2.bubble_sort.c
 * @author RoyLau (897379293@qq.com)
 * @brief 冒泡排序
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


void bubble_sort(int *num, int n) {
  for (int i = 1; i < n;i++) {
    int flag;
    for (int j = 0; j < n - i;j++) {
      if (num[j] > num[j + 1]) {
        flag = 1;
        swap(num[j], num[j + 1]);
      }
    }
    if (flag == 0) break;
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

  bubble_sort(num, n);
  for (int i = 0;i < n;i++) {
    i &&printf(", ");
    printf("%d", num[i]);
  }
  printf("\n");
  return 0;
}