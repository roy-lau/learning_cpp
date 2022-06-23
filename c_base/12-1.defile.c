/**
 * @file 12-1.defile.c
 * @author RoyLau (897379293@qq.com)
 * @brief 宏
 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

#define P(a) { \
  printf("%s = ", #a); printf("%d\n", (a)); \
}

#define MAX(A,B) ({ \
  __typeof(A) __a = (A); __typeof(B) __b = (B); \
  __a > __b ? __a : __b; \
})

int main() {
  int a = 7;
  P(a);
  P(MAX(2, 3));
  P(5 + MAX(2, 3));
  P(MAX(2, MAX(3, 4)));
  P(MAX(2, 3 > 4 ? 3 : 4));
  P(MAX(a++, 6));
  P(a);
  return 0;
}