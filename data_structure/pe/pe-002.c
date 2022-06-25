/**
 * @file pe-002.c
 * @author RoyLau (897379293@qq.com)
 * @brief 偶斐波那契数
 * @link https://pe-cn.github.io/2/
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

 // 方法一：
 // int num[4000005];

 // int main() {
 //   num[0] = 1, num[1] = 2;
 //   int sum = 2;
 //   for (int i = 2;1;++i) {
 //     num[i] = num[i - 1] + num[i - 2];
 //     if (num[i] > 4000000) break;
 //     if (num[i] % 2 == 0) sum += num[i];
 //   }
 //   printf("%d\n", sum);

 //   return 0;
 // }

 // 方法二（空间复杂度优化）：
int main() {
  int a = 1, b = 2, sum = 0;
  while (b < 4000000) {
    if (b % 2 == 0) sum += b;
    b = a + b;
    a = b - a;
  }
  printf("%d\n", sum);
  return 0;
}