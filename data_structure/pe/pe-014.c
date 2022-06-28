/**
 * @file pe-014.c
 * @author RoyLau (897379293@qq.com)
 * @brief 最长考拉兹序列
 * @link https://pe-cn.github.io/14/
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>

int arr[10000005] = { 0 };

/**
 * @brief 考拉茲记忆化递归函数
 * 
 * @param n 
 * @return int 
 */
int klz_func(long long n) {
  if (n == 1) return 1;
  if (n < 1000000 && arr[n] != 0) return arr[n];
  int t;
  if (n % 2 == 0) t = klz_func(n / 2) + 1;
  else t = klz_func(3 * n + 1) + 1;
  if (n < 10000000) arr[n] = t;
  return t;
}


int main() {

  int len = 0, ans;
  for (int i = 2; i < 1000000;++i) {
    int t = klz_func(i);
    if (t > len) {
      len = t;
      ans = i;
    }
  }

  printf("%d\n", ans);
  return 0;
}