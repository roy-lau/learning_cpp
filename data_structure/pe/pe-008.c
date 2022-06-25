/**
 * @file pe-008.c
 * @author RoyLau (897379293@qq.com)
 * @brief 连续数字最大乘积
 * @version 0.1
 * @date 2022-06-24
 *
 * @copyright Copyright (c) 2022
 *
 * @runing ./a.out < input8 
 */
#include <stdio.h>

char num[1005];

int main() {
  scanf("%s", num);

  long long now = 1, ans = 0, zero_cnt = 0;

  for (int i = 0;i < 1000;++i) {

    if (i < 13) {
      now *= num[i] - '0';
    } else {

      if (num[i] == '0') {
        zero_cnt++;
      } else {
        now *= num[i] - '0';
      }

      if (num[i - 13] == '0') {
        zero_cnt--;
      } else {
        now /= num[i - 13] - '0';
      }
    }
    if (zero_cnt == 0 && ans < now) {
      ans = now;
    }
  }

  printf("%lld\n", ans);

  return 0;
}