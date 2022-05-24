/**
 * @file 13.branch_search.c
 * @author RoyLau
 * @brief 二分查找
 * @version 0.1
 * @date 2022-05-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>

 /**
  * @brief 二分查找
  *
  * @param arr 数组
  * @param n 长度
  * @param x 查找的值
  * @return int -1 未找到，n 查找值的下标
  */
int binary_search(int *arr, int n, int x) {
  int head = 0, tail = n - 1, mid;
  while (head < tail) {
    mid = (head + tail) >> 1;
    if (arr[mid] == x) return mid;
    if (arr[mid] < x) head = mid + 1;
    else tail = mid - 1;
  }
  return -1;
}

// 0000011111 找到第一个 1
int binary_search1(int *arr, int n) {
  int head = 0, tail = n, mid;
  while (head < tail) {
    mid = (head + tail) >> 1;
    if (arr[mid] == 1) tail = mid;
    else head = mid + 1;
  }
  return head == n ? -1 : head;
}

//  1111100000 找到最后一个 1
int binary_search2(int *arr, int n) {
  int head = 0, tail = n - 1, mid;
  while (head < tail) {
    mid = (head + tail + 1) >> 1;
    if (arr[mid] == 1) head = mid;
    else tail = mid - 1;
  }
  return head;
}

int main() {
  int arr[100] = { 0 }, n;
  scanf("%d", &n);
  for (int i = 0; i < n;i++) {
    scanf("%d", arr + i);
    // arr[i] = i;
    // printf("%d ", i);
  }
  // int x;
  // while (~scanf("%d", &x)) {
  //   printf("--> %d\n", binary_search(arr, n, x));
  // }

  // printf("--> %d\n", binary_search1(arr, n));

  printf("--> %d\n", binary_search2(arr, n));

  return 0;
}