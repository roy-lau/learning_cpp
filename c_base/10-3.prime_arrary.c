/**
 * @file 10-3.prime_arrary.c
 * @author RoyLau (897379293@qq.com)
 * @brief 素数筛选（将素数合数存在数组中）
 * @version 0.1
 * @date 2022-06-18
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#define MAX_N 100

int prime[MAX_N + 5] = { 0 };

/**
 * @brief 利用合数标记素数
 *
 */
void init_prime() {
  for (int i = 2; i <= MAX_N; ++i) {
    if (prime[i]) continue;
    prime[++prime[0]] = i;
    for (int j = 2 * i; j <= MAX_N; j += i) { // 2 的倍数必然是合数
      prime[j] = 1; // 标记合数
    }
  }
}

int main() {
  init_prime();

  for (int i = 1; i <= prime[0]; ++i) {
    printf("%d\n", prime[i]); // 输出素数
  }

  return 0;
}