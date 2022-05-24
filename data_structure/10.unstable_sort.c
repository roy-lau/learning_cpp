/**
 * @file 10.unstable_sort.c
 * @author RoyLau
 * @brief 非稳定排序
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
  __typeof(a) __temp = a;\
  a = b; b = __temp;\
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
    * @brief 选择排序
    *
    * @O n^2
    * @param num 数组
    * @param n 长度
    */
void select_sort(int *num, int n) {
  for (int i = 0; i < n - 1;i++) {
    int ind = i;
    for (int j = i + 1;j < n;j++) {
      if (num[j] < num[ind]) ind = j;
    }
    swap(num[ind], num[i]);
  }
  return;
}

/**
 * @brief 快速排序
 *
 * @O nlogn
 * @param num 数组
 * @param l
 * @param r
 */
void quick_sort(int *num, int l, int r) {
  if (l > r) return;
  int x = l, y = r, z = num[x];
  while (x < y) {
    while (x<y && num[y]>z)y--;
    if (x < y) num[x++] = num[y];
    while (x < y && num[x] < z) x++;
    if (x < y) num[y--] = num[x];
  }
  num[x] = z;
  quick_sort(num, l, x - 1);
  quick_sort(num, x + 1, r);
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

  TEST(arr, MAX_N, select_sort, num, MAX_N);
  TEST(arr, MAX_N, quick_sort, num, 0, MAX_N - 1);

#undef MAX_N
  return 0;
}