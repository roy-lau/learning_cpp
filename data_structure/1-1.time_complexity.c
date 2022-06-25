/**
 * @file 1-1.time_complexity.c
 * @author RoyLau (897379293@qq.com)
 * @brief 时间复杂度的示例
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  // 时间复杂度：O(n*1/2) ，n*1/2 = 根号n
  int x = 0, s = 0;
  while (s < n) {
    x++;
    s += x;
    printf("x = %d, s = %d\n", x, s);
  }


  // 时间复杂度 O(n)
  // int j = 0; // 内层循环的 j 大于等于 n 后就不循环了，相当于循环了 n 次。
  // for (int i = 0; i < n;i++) {
  //   for (;j < n;j++) {
  //     printf("i = %d, j = %d\n", i, j);
  //   }
  // }

  // 时间复杂度 O(n^2)
  // for (int i = 0;i < n;i++) {
  //   for (int j = i;j < n;j++) {
  //     printf("i = %d, j = %d\n", i, j);
  //   }
  //   printf("\n");
  // }

  return 0;
}