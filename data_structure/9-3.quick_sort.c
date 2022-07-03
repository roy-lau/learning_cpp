/**
 * @file 9-3.quick_sort.c
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


void quick_sort(int *num, int l, int r) {
  if (l >= r) return;
  int t = num[l]; // 中间元素
  int ll = l, rr = r;  // rr 从前向后遍历，rr 从后向前遍历
  while (ll < rr) {
    while (ll < rr && num[rr] >= t) rr--; // 从后向前找比 t 小的
    if (ll < rr) num[ll] = num[rr];
    while (ll < rr && num[ll] <= t) ll++; // 从前向后找比 t 大的
    if (ll < rr) num[rr] = num[ll];
  }
  num[ll] = t;
  quick_sort(num, l, ll - 1);
  quick_sort(num, ll + 1, r);
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

  quick_sort(num, 0, n-1);
  for (int i = 0;i < n;i++) {
    i &&printf(", ");
    printf("%d", num[i]);
  }
  printf("\n");
  return 0;
}