/**
 * @file oj-104.c
 * @author RoyLau (897379293@qq.com)
 * @brief 数字中有 9 吗
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  // (n % 10 == 9) 判断个位是否有 9
  // (n / 10 % 10 == 9) 判断十位是否有 9
  // (n / 100 % 10 == 9) 判断百位是否有 9
  if ((n % 10 == 9) || (n / 10 % 10 == 9) || (n / 100 % 10 == 9)) printf("YES\n");
  else printf("NO\n");
  return 0;
}