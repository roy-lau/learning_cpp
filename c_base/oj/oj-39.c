/**
 * @file oj-39.c
 * @author RoyLau
 * @brief 输出一定数量的偶数
 * @version 0.1
 * @date 2022-06-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  int begin, end;
  scanf("%d%d", &begin, &end);
  if (begin < 0)begin = 0;
  if (begin % 2)begin += 1;
  for (int i = 0;i < end;i++) {
    printf("%d\n", begin);
    begin += 2;
  }

  return 0;
}