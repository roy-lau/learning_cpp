/**
 * @file pe-001.c
 * @author RoyLau (897379293@qq.com)
 * @brief 3或5的倍数
 * @link https://pe-cn.github.io/1/
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  // 方法一：
  // int sum = 0;
  // for (int i = 3;i < 1000;++i) {
  //   if (i % 3 == 0 || i % 5 == 0) sum += i;
  // }

  // 方法二(时间复杂度优化)：
  int sum3 = (3 + 999) * 333 / 2;
  int sum5 = (5 + 995) * 199 / 2;
  int sum15 = (15 + 990) * 66 / 2;
  printf("%d\n", sum3 + sum5 - sum15);

  return 0;
}