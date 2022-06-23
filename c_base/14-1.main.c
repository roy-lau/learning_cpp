/**
 * @file 14-1.main.c
 * @author RoyLau (897379293@qq.com)
 * @brief 主函数的命令行参数
 * @version 0.1
 * @date 2022-06-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("argc = %d\n", argc);
  for (int i = 0; i < argc;++i) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
  return 0;
}