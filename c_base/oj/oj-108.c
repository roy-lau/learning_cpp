/**
 * @file oj-108.c
 * @author RoyLau (897379293@qq.com)
 * @brief 求面积的问题
 * @version 0.1
 * @date 2022-06-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int main() {
  char str; // 𝑟 表示长方形，𝑡 表示三角形。
  double m, n;
  scanf("%s%lf%lf", &str, &m, &n);
  // if(str == 'r'){
  //   printf("%.2lf", m*n);
  // }else{
  //   printf("%.2lf", m*n/2);
  // }

  // 长方形除以 1 相当于没除，三角形除以 2
  printf("%.2lf\n", m * n / (str == 'r' ? 1 : 2));
  return 0;
}