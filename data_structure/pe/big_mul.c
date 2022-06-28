/**
 * @file big_mul.c
 * @author RoyLau (897379293@qq.com)
 * @brief 大整数乘法
 * @version 0.1
 * @date 2022-06-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>

char s1[1005], s2[1005];
int n1[1005], n2[10005], ans[2005];

int main() {

  scanf("%d%d", s1, s2);

  // 在 n1[0] 和 n2[0] 中保存 s1 和 s2 的长度。
  n1[0] = strlen(s1), n2[0] = strlen(s2);

  // 倒序将两个数字分别存入 n1 n2 中
  for (int i = 0, j = n1[0];i < n1[0];i++, j--) {
    n1[j] = n1[i] - '0';
  }
  for (int i = 0, j = n2[0];i < n2[0];i++, j--) {
    n2[j] = n2[i] - '0';
  }

  // 将最大的数字长度存入到 ans[0] 中
  ans[0] = n1[0] + n2[0] - 1;

  // 将两数相乘的结果存入到 ans 中
  for (int i = 1;i <= n1[0];i++) {
    for (int j = 1;j <= n2[0];j++) {
      ans[i + j - 1] += n1[i] * n2[j];
    }
  }

  // 进位
  for (int i = 1;i <= ans[0];i++) {
    if (ans[i] > 0) {
      ans[i + 1] += ans[i] / 10;
      ans[i] %= 10;
      if (i == ans[0]) ans[0]++;
    }
  }

  // 倒序输出 ans 中的计算结果
  for (int i = ans[0];i > 0;i--) {
    printf("%d", ans[i]);
  }
  printf("\n");

  return 0;
}