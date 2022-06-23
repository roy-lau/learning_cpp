/**
 * @file 14-2.main.c
 * @author RoyLau (897379293@qq.com)
 * @brief 主函数环境变量
 * @version 0.1
 * @date 2022-06-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main(int argc, char *argv[], char **env) {
  for (int i = 0;env[i];++i) {
    printf("env[%d] = %s\n", i, env[i]);
  }

  return 0;
}