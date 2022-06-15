/**
 * @file 9-5.func_auto_parmas.c
 * @author RoyLau (897379293@qq.com)
 * @brief 变参函数
 * @version 0.1
 * @date 2022-06-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdarg.h> // 处理变参函数的库

/**
 * @brief 查找最大数值
 * 
 * @param num 变参数量
 * @param ... 变参列表
 * @return int 最大数值
 */
int max_int(int num, ...) {
  int ans = 0, temp;
  va_list arg; // 定义一个代表参数列表的变量
  va_start(arg, num); // 初始化参数列表
  while (num--) {
    // 循环读入 num 个参数，取出其中的最大值，放入 ans 变量中
    temp = va_arg(arg, int);
    if (temp > ans) ans = temp;
  }
  va_end(arg); // 销毁参数列表
  return ans;
}

int main() {
  printf("%d\n", max_int(3, 1, 5, 3));
  printf("%d\n", max_int(2, 1, 3));
  printf("%d\n", max_int(6, 6, 5, 3, 7, 8, 10));
  printf("%d\n", max_int(3, 1, 9, 10));

  return 0;
}