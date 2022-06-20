/**
 * @file 10-5.dynamic_array.c
 * @author RoyLau (897379293@qq.com)
 * @brief 动态数组
 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

void output(int *arr, int n) {
  printf("arr = [ ");
  for (int i = 0; i < n;i++) {
    printf("%d ", arr[i]);
  }
  printf("]\n");
  return;
}
void output_matrix(int **matrix, int n) {
  printf("matrix = %p, matrix + 1 = %p \n", matrix, matrix + 1);
  return;
}

int main() {
  int *arr = (int *)malloc(sizeof(int) * MAX_N);
  int **matrix = (int **)malloc(sizeof(arr) * MAX_N);
  for (int i = 0; i < 5;i++) {
    scanf("%d", &arr[i]);
  }
  output(arr, 5);
  printf("matrix = %p, matrix + 1 = %p \n", matrix, matrix + 1);
  output_matrix(matrix, 5);
  free(arr);
  free(matrix);
  return 0;
}