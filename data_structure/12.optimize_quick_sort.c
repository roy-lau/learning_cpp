/**
 * @file 12.optimize_quick_sort.c
 * @author RoyLau
 * @brief 优化后的快速排序
 * @version 0.1
 * @date 2022-05-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>

 /**
  * @brief 变量交换的宏
  *
  */
#define swap(a, b) {\
  __typeof(a) __temp = a;\
  a = b; b = __temp;\
}

  /**
   * @brief 快速排序(优化后的)
   *
   * @O nlogn
   * @param num 数组
   * @param l
   * @param r
   */
void quick_sort(int *num, int l, int r) {
  while (l < r) {
    int x = l, y = r, z = num[(l + r) >> 1];
    do {
      while (num[x] < z) x++;
      while (num[y] > z) y--;
      if (x <= y) {
        swap(num[x], num[y]);
        x++, y--;
      }
    } while (x <= y);
    quick_sort(num, l, y);
    l = x;
  }
}

/**
 * @brief 初始化数组
 *
 * @param arr 数组
 * @param n 长度
 */
void init_arr(int *arr, int n) {
  for (int i = 0;i < n;i++) {
    arr[i] = n - i;
  }
  return;
}


/**
 * @brief 打印日志
 *
 * @param arr
 * @param n
 */
void output(int *arr, int n) {
  for (int i = 0; i < n;i++) {
    i &&printf(" ");
    printf("%d", arr[i]);
  }
  return;
}


int main() {
#define MAX_N 100000
  int arr[MAX_N] = { 0 };
  init_arr(arr, MAX_N);
  quick_sort(arr, 0, MAX_N - 1);
  output(arr, MAX_N);

#undef MAX_N
  return 0;
}