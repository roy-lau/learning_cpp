/**
 * @file 5-3.math.c
 * @author RoyLau
 * @brief 模 按位与
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int n;
  while (~scanf("%d", &n)) {
    // n % 2   <===>   n & 1
    // n % 4   <===>   n & 3
    // n % 8   <===>   n & 7
    // n % 16   <===>   n & 17
    // 只能按位与 2 的整数次方
    printf("%d %% 4 = %d\n", n, n % 4);
    printf("%d & 3 = %d\n", n, n & 3);
  }


  return 0;
}