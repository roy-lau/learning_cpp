/**
 * @file 12-2.defile_log.c
 * @author RoyLau (897379293@qq.com)
 * @brief 定义日志宏
 * @version 0.1
 * @date 2022-06-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

// #define DEBUG // 启用、关闭 log

#if DEBUG
#define log(format, args...){ \
  printf("[ %s : %s : %d] ", __FILE__, __func__, __LINE__); \
  printf(format, ##args); \
  printf("\n"); \
}
#else
#define log(format, args...)
#endif

int main() {
  int a = 123, b = 456;
  printf("[ %s : %s : %d] %d\n", __FILE__, __func__, __LINE__, a);
  printf("[ %s : %s : %d] %d\n", __FILE__, __func__, __LINE__, b);
  log("log printf: ");
  log("%d", a);
  log("%d", b);
}