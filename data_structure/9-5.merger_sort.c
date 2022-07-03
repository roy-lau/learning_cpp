/**
 * @file 9-5.merger_sort.c
 * @author RoyLau (897379293@qq.com)
 * @brief 归并排序
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


void merger_sort(int *num, int *temp, int l, int r) {
  if (l >= r) return;
  int mid = (l + r) >> 1;
  // 左右区间分别排序
  merger_sort(num, temp, l, mid);
  merger_sort(num, temp, mid + 1, r);
  int p1 = l, p2 = mid + 1, n = r - l + 1;
  // 合并
  for (int i = 0; i < n;i++) {
    if (p2 > r || p1 <= mid && num[p1] <= num[p2]) {
      temp[i] = num[p1];
      p1++;
    } else {
      temp[i] = num[p2];
      p2++;
    }
  }
  // 覆写回原数组
  for (int i = 0, j = l;i < n;i++, j++) {
    num[j] = temp[i];
  }
}

int main() {
  srand(time(0));
  int n, num[105], temp[105];
  scanf("%d", &n);
  for (int i = 0;i < n;i++) {
    num[i] = rand() % 100;
    i &&printf(", ");
    printf("%d", num[i]);
  }
  printf("\n");

  merger_sort(num, temp, 0, n - 1);
  for (int i = 0;i < n;i++) {
    i &&printf(", ");
    printf("%d", num[i]);
  }
  printf("\n");
  return 0;
}