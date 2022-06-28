/**
 * @file big_add.c
 * @author RoyLau (897379293@qq.com)
 * @brief 大整数的加法
 * @version 0.1
 * @date 2022-06-27
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <string.h>

char s1[1005], s2[1005];
int n1[1005], n2[1005], ans[1005];

int main() {
  scanf("%s%s", s1, s2);
  n1[0] = strlen(s1);
  n2[0] = strlen(s2);

  // 倒序将两个数字分别存入 n1 n2 中
  for (int i = 0, j = n1[0]; i < n1[0];i++, j--) {
    n1[j] = s1[i] - '0';
  }
  for (int i = 0, j = n2[0]; i < n2[0];i++, j--) {
    n2[j] = s2[i] - '0';
  }

  // 将最大的数字长度存入到 ans[0] 中
  if (n1[0] > n2[0]) ans[0] = n1[0];
  else ans[0] = n2[0];

  // 将两数相加的结果存入到 ans 中
  for (int i = 1;i <= ans[0];i++) {
    ans[i] = n1[i] + n2[i];
  }

  // 进位
  for (int i = 1;i <= ans[0];i++) {
    if (ans[i] > 9) {
      ans[i + 1]++;
      ans[i] -= 10;
      if (i == ans[0]) ans[0]++;
    }
  }

  // 倒序输出 ans 中的计算结果
  for (int i = ans[0]; i > 0; i--) {
    printf("%d", ans[i]);
  }

  printf("\n");
  return 0;
}