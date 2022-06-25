/**
 * @file 9.stable_sort.c
 * @author RoyLau
 * @brief 稳定排序
 * @version 0.1
 * @date 2022-05-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

 // 定义颜色的宏
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define YELLOW(a) COLOR(a, 33) // 黄色

 /**
  * @brief 变量交换的宏
  *
  */
#define swap(a, b) {\
  a ^= b;\
  b ^= a;\
  a ^= b;\
}

/**
 * @brief 用于测试的宏
 *
 */
#define TEST(arr, n, func, args...) {\
  int *num = (int *)malloc(sizeof(int) * n);\
  memcpy(num, arr, sizeof(int) * n);\
  output(num, n);\
  printf(YELLOW("%s = "), #func);\
  func(args);\
  output(num, n);\
  free(num);\
  printf("\n");\
}


/**
  * @brief 插入排序
  *
  * @param num 待排序的数组
  * @param n 长度
  */
void insert_sort(int *num, int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0 && num[j] < num[j - 1]; j--) {
      swap(num[j], num[j - 1]);
    }
  }
  return;
}

/**
 * @brief 冒泡排序
 *
 * @param num 待排序数组
 * @param n 长度
 */
void bobble_sort(int *num, int n) {
  int times = 1;
  for (int i = 1; i < n && times; i++) {
    times = 0;
    for (int j = 0; j < n - i;j++) {
      if (num[j] <= num[j + 1]) continue;
      swap(num[j], num[j + 1]);
      times = 1;
    }
  }
  return;
}

/**
 * @brief 归并排序
 *
 * @param num 数组
 * @param l 左
 * @param r 右
 */
void merge_sort(int *num, int l, int r) {
  if (r - l <= 1) {
    if (r - l == 1 && num[r] < num[l]) {
      swap(num[r], num[l]);
    }
    return;
  }
  int mid = (l + r) >> 1;
  merge_sort(num, l, mid);
  merge_sort(num, mid + 1, r);

  int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
  int p1 = l, p2 = mid + 1, k = 0;
  while (p1 <= mid || p2 <= r) {
    if (p2 > r || (p1 <= mid && num[p1] <= num[p2])) {
      temp[k++] = num[p1++];
    } else {
      temp[k++] = num[p2++];
    }
  }
  memcpy(num + l, temp, sizeof(int) * (r - l + 1));
  free(temp);
  return;
}


/**
 * @brief 打印日志
 *
 * @param num
 * @param n
 */
void output(int *num, int n) {
  printf("[ ");
  for (int i = 0; i < n;i++) {
    i &&printf(" ");
    printf("%d", num[i]);
  }
  printf(" ]\n");
}

/**
 * @brief 随机生成数值，并写进数组
 *
 * @param num 数组
 * @param n 长度
 */
void randint(int *num, int n) {
  while (n--) num[n] = rand() % 100;
}


int main() {
  srand(time(0));
#define MAX_N 20
  int arr[MAX_N];
  randint(arr, MAX_N);

  TEST(arr, MAX_N, insert_sort, num, MAX_N);
  TEST(arr, MAX_N, bobble_sort, num, MAX_N);
  TEST(arr, MAX_N, merge_sort, num, 0, MAX_N - 1);

#undef MAX_N
  return 0;
}