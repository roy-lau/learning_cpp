/**
 * @file 10-0.array.c
 * @author RoyLau (897379293@qq.com)
 * @brief 数组
 * @version 0.1
 * @date 2022-06-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

 /**
  * @brief 输出一维数组内存值
  *
  * @param nums 一维数组形参
  * @param n
  */
void p_arr(int nums[], int n) {
  printf("p_arr :\n");
  printf("nums = %p, nums + 1 = %p\n", nums, nums + 1);
  return;
}

/**
 * @brief
 *
 * @param matrix 二维数组形参
 */
// void p_matrix(int matrix[2][3]) { // 传参方法一
void p_matrix(int (*matrix)[3]) { // 传参方法二
  printf("p_matrix :\n");
  printf("p_matrix = %p, p_matrix + 1 = %p\n", matrix, matrix + 1);
  return;
}

int main() {
  int arr[10] = { 1,2,3,4,5,6,7,8,9 };

  /**
   * @brief 字节、长度 展示
   *
   */
   // 数组占用的字节数
  printf("sizeof = %lu\n", sizeof(arr));
  // 数组的长度
  int arr_len = sizeof(arr) / sizeof(int);
  printf("arr_len = %d\n", arr_len);

  /**
   * @brief 内存、取值 展示
   *
   */
  int i = 5;
  // arr[i] 等价于 arr+i
  printf("arr[i] = %p, arr+i= %p\n", &arr[i], arr + i);
  // arr 和 &arr[0] 的地址是相同的
  printf("arr = %p, &arr[0] = %p\n", arr, &arr[0]);
  // arr+1 比 arr 大了 4 个字节
  printf("arr+1 = %p\n", arr + 1);


  /**
   * @brief 数组传参
   *
   */
  p_arr(arr, arr_len);

  // 二维数组
  int matrix[2][3] = { {1,2,3},{4,5,6} }; // 定义一个 2 行 3 列的二维数组
  // int matrix1[2][10] = {0}; // 定义一个 2 行 10 列的二维数组
  printf("\nmatrix: \n");

  /**
   * @brief 字节、长度 展示
   *
   */
   // 数组占用的字节数
  printf("sizeof = %lu\n", sizeof(matrix));
  // 数组的长度
  int matrix_len = sizeof(matrix) / sizeof(int);
  printf("matrix_len = %d\n", matrix_len);

  // matrix 和 matrix +1 相差 12 个字节
  printf("matrix = %p, matrix + 1 =%p\n", matrix, matrix + 1);

  p_matrix(matrix);

  return 0;
}