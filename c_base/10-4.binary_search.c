/**
 * @file 10-4.binary_search.c
 * @author RoyLau (897379293@qq.com)
 * @brief 二分查找算法
 * @version 0.1
 * @date 2022-06-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

 /**
  * @brief 二分查找
  *
  * @param arr 待查找的数组
  * @param len 数组长度
  * @param x 查找值
  * @return int 找到就返回找到的下标，未找到返回 -1
  */
int binary_search(int *arr, int len, int x) {
  int min = 0, max = len - 1, mid;
  while (min <= max) {
    mid = (min + max) >> 1;
    if (arr[mid] < x) min = mid + 1;
    else if (arr[mid] > x) max = mid - 1;
    else if (arr[mid] == x) return mid;
  }
  return -1;
}

/**
 * @brief 二分查找（递归版本）
 *
 * @param arr
 * @param l
 * @param r
 * @param x
 * @return int
 */
int binary_search1(int *arr, int l, int r, int x) {
  if (l > r) return -1;
  int mid = (l + r) >> 1;
  if (arr[mid] == x) return mid;
  if (arr[mid] < x) l = mid = +1;
  else r = mid - 1;
  return binary_search1(arr, l, r, x);
}

int main() {
  int x, n = 10;
  int arr[10] = { 1,2,3,4,5,6,7,7,8,9 };

  while (~scanf("%d", &x)) {
    // printf("binary_search(%d) = %d\n", x, binary_search(arr, n, x));
    printf("binary_search1(%d) = %d\n", x, binary_search1(arr, 0, n - 1, x));
  }

  return 0;
}