/**
 * @file 16.heap_sort.c
 * @author RoyLau
 * @brief 数据结构 - 堆排序
 * @version 0.1
 * @date 2022-05-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 /**
  * @brief 变量交换的宏
  *
  */
#define swap(a, b) {\
  __typeof(a) __temp = a;\
  a = b; b = __temp;\
}

  /**
   * @brief 向下调整
   *
   * @param arr 数组
   * @param n 长度
   * @param ind 下标
   */
void downUpdate(int *arr, int n, int ind) {
  while ((ind << 1) <= n) {
    int temp = ind, l = ind << 1, r = ind << 1 | 1;
    if (arr[l] > arr[temp]) temp = l;
    if (r <= n && arr[r] > arr[temp]) temp = r;
    if (temp == ind) break;
    swap(arr[ind], arr[temp]);
    ind = temp;
  }
  return;
}


/**
 * @brief 堆排序
 *
 * @param arr 数组
 * @param n 长度
 */
void heap_sort(int *arr, int n) {
  arr -= 1; // arr[1] 的时候相当于 arr[0]
  for (int i = n >> 1; i >= 1;i--) {
    downUpdate(arr, n, i);
  }
  for (int i = n; i > 1; i--) {
    swap(arr[i], arr[1]);
    downUpdate(arr, i - 1, 1);
  }
  return;
}

void output(int *arr, int n) {
  printf("[ ");
  for (int i = 0; i < n; i++) {
    i &&printf(" ");
    printf("%d", arr[i]);
  }
  printf(" ]\n");
}

int main() {
  srand(time(0));
#define MAX_N 20
  int *arr = (int *)malloc(sizeof(int) * MAX_N);
  for (int i = 0; i < MAX_N; i++) {
    arr[i] = rand() % 100;
  }
  printf("排序前==> "), output(arr, MAX_N);
  heap_sort(arr, MAX_N);
  printf("排序后==> "),output(arr, MAX_N);
#undef MAX_N
  free(arr);

  return 0;
}