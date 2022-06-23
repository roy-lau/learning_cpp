/**
 * @file 13-2.pointer_struct.c
 * @author RoyLau (897379293@qq.com)
 * @brief 指针结构体
 * @version 0.1
 * @date 2022-06-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

#define print(x){\
  printf("%s = %d\n", #x, x); \
}

struct Data {
  int x, y;
};

int main() {
  struct Data a[2], *p = a;
  a[0].x = 0, a[0].y = 1;
  a[1].x = 2, a[1].y = 3;

  // printf("%p\n", *a);
  // printf("%p\n", &a);
  // printf("%p\n", a);
  // 用尽可能多的方式取 x 的值：
  print(a[1].x);
  print(p[1].x);

  print((a + 1)->x);
  print((p + 1)->x);

  print((*(a + 1)).x);
  print((*(p + 1)).x);

  print((&a[1])->x);
  print((&p[1])->x);

  print((&a[0] + 1)->x);
  print((&p[0] + 1)->x);

  print((&(*a) + 1)->x);
  print((&(*p) + 1)->x);

  print(*((int *)a + 2)); // 根据结构体的存储顺序找到 x
  print(*((int *)p + 2));

  return 0;
}

