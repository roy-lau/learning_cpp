/**
 * @file 15.priority_queue.c
 * @author RoyLau
 * @brief 数据结构 - 优先队列（堆）
 * @version 0.1
 * @date 2022-05-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 /**
  * @brief 变量交换的宏
  *
  */
#define swap(a, b) {\
  __typeof(a) __temp = a;\
  a = b; b = __temp;\
}
  /**
   * @brief 结构定义 - 优先队列
   *
   * @param *data 数据值
   * @param cnt 数量
   * @param size 大小
   */
typedef struct priority_queue {
  int *data;
  int cnt, size;
} priority_queue;

/**
 * @brief 初始化 - 优先队列
 *
 * @param n 大小
 * @return priority_queue* 优先队列
 */
priority_queue *init(int n) {
  priority_queue *q = (priority_queue *)malloc(sizeof(priority_queue));
  q->data = (int *)malloc(sizeof(int) * (n + 1));
  q->cnt = 0;
  q->size = n;
  return q;
}

/**
 * @brief 判断是否为空
 *
 * @param q 优先队列
 * @return int 1 空，0 非空
 */
int empty(priority_queue *q) {
  return q->cnt == 0;
}

/**
 * @brief 获取优先队列顶部元素
 *
 * @param q 优先队列
 * @return int 顶部元素
 */
int top(priority_queue *q) {
  return q->data[1];
}

/**
 * @brief 尾部插入调整
 *
 * @param q 优先队列
 * @param val 插入值
 * @return int  1 成功，0 失败
 */
int push(priority_queue *q, int val) {
  if (q == NULL) return 0;
  if (q->cnt == q->size) return 0;
  q->data[++(q->cnt)] = val;
  int ind = q->cnt;
  while (ind >> 1 && q->data[ind] > q->data[ind >> 1]) {
    swap(q->data[ind], q->data[ind >> 1]);
    ind >>= 1;
  }
  return 1;
}

/**
 * @brief 头部弹出调整
 *
 * @param q 优先队列
 * @return int 1 成功，0 失败
 */
int pop(priority_queue *q) {
  if (q == NULL) return 0;
  if (empty(q)) return 0;
  q->data[1] = q->data[q->cnt--];
  int ind = 1;
  while ((ind << 1) <= q->cnt) {
    int temp = ind, l = ind << 1, r = ind << 1 | 1; // r 相当于乘 2 加 1
    if (q->data[l] > q->data[temp]) temp = l;
    if (r <= q->cnt && q->data[r] > q->data[temp]) temp = r;
    if (temp == ind) break;
    swap(q->data[temp], q->data[ind]);
    ind = temp;
  }
  return 1;
}

/**
 * @brief 清空优先队列（垃圾回收 gc）
 *
 * @param q  优先队列
 */
void clear(priority_queue *q) {
  if (q == NULL) return;
  free(q->data);
  free(q);
  return;
}


int main() {
  srand(time(0));
#define MAX_OP 20
  priority_queue *q = init(MAX_OP);
  for (int i = 0; i < MAX_OP;i++) {
    int val = rand() % 100;
    push(q, val);
    printf("insert %d to the priority_queue\n", val);
  }
  for (int i = 0; i < MAX_OP;i++) {
    printf("%d ", top(q));
    pop(q);
  }
  printf("\n");
#undef MAX_OP
  clear(q);
  return 0;
}