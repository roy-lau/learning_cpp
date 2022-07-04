/**
 * @file 10-2.bisearch.c
 * @author RoyLau (897379293@qq.com)
 * @brief 折半查找
 * @version 0.1
 * @date 2022-07-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

/**
 * @brief 输出数组
 * 
 * @param num 
 * @param n 
 */
void output(int *num, int n) {
  for (int i = 0;i < n;++i) {
    i &&printf(", ");
    printf("%d", num[i]);
  }
  printf("\n");
}

/**
 * @brief 折半查找
 * 
 * @param num 待查找数组
 * @param n 数组长度
 * @param x 目标数字
 */
void bisearch(int *num, int n, int x) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (num[mid] == x) {
      printf("bs --> %d\n", mid);
      return;
    }
    if (num[mid] > x) r = mid - 1;
    else l = mid + 1;
  }
  printf("not find\n");
}

void bisearch2(int *num, int n, int x) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (num[mid] > x) r = mid - 1;
    else l = mid;
  }
  printf("bs2 --> %d %d\n", l, r);
}

int main() {
  int num[15] = { 2,5,10,36,47,54,63,80,83,91 };
  int n = 10, target;
  output(num, n);

  while (~scanf("%d", &target)) {
    bisearch(num, n, target);
    bisearch2(num, n, target);
  }

}