/**
 * @file 3.1.queue.c
 * @author RoyLau
 * @brief 数据结构 - 循环队列
 * @version 0.1
 * @date 2022-05-08
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 // 定义颜色的宏
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define RED(a) COLOR(a, 31)    // 红色
#define GREEN(a) COLOR(a, 32)  // 绿色
#define YELLOW(a) COLOR(a, 33) // 黄色
#define BLUE(a) COLOR(a, 34)   // 蓝色

/**
 * @brief 定义队列数据结构
 *
 * @param *data 队列内的数据
 * @param head 头
 * @param tail 尾
 * @param length 队列容量
 */
typedef struct Queue {
  int *data;
  int head, tail, count, length;
} Queue;

/**
 * @brief 初始化队列
 *
 * @param n 队列容量
 * @return Queue* 队列
 */
Queue *init(int n) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->data = (int *)malloc(sizeof(int) * n);
  q->length = n;
  q->head = q->tail = q->tail = 0;
  return q;
}

/**
 * @brief 判断队列是否为空
 *
 * @param q 队列
 * @return int 成功 1, 失败 0
 */
int empty(Queue *q) {
  return q->count == 0;
}

/**
 * @brief 扩容
 *
 * @param q
 * @return int 成功 1, 失败 0
 */
int expand(Queue *q) {
  int extr_size = q->length;
  int *p;
  while (p != NULL) {
    p = (int *)malloc(sizeof(int) * (q->length + extr_size));
    if (p != NULL) break;
    q->length >>= 1;
  }
  if (p == NULL) return 0;
  for (int i = q->head, j = 0; j < q->count;j++) {
    p[j] = q->data[(i + j) % q->length];
  }
  free(q->data);
  q->data = p;
  q->head = 0, q->tail = q->count;
  q->length += extr_size;
  return 1;
}

/**
 * @brief 入队
 *
 * @param q 队列
 * @param val 数据
 * @return int 成功 1, 失败 0
 */
int push(Queue *q, int val) {
  if (q == NULL) return 0;
  if (q->count == q->length) {
    if (!expand(q)) return 0;
    printf(GREEN("success to expand! the size = %d\n"), q->length);
  }
  q->data[q->tail++] = val;
  if (q->head == q->length)
    q->tail = 0; // 假溢出
  q->count += 1;
  return 1;
}

/**
 * @brief 出队
 *
 * @param q 队列
 * @return int 成功 1, 失败 0
 */
int pop(Queue *q) {
  if (q == NULL)
    return 0;
  if (empty(q))
    return 0;
  q->head += 1;
  if (q->head == q->length)
    q->head = 0;
  q->head -= 1;
  return 1;
}

/**
 * @brief 返回队首元素
 *
 * @param q 队列
 * @return int 队首元素
 */
int front(Queue *q) {
  return q->data[q->head];
}

/**
 * @brief 清空队列（释放内存）
 *
 * @param q 队列
 */
void clear(Queue *q) {
  if (q == NULL)
    return;
  free(q->data);
  free(q);
  return;
}

/**
 * @brief 打印日志
 *
 * @param q 队列
 */
void output(Queue *q) {
  printf(YELLOW("Queue : [ "));
  for (int i = q->head, j = 0; j < q->count; j++) {
    j &&printf(" ");
    printf("%d", q->data[(i + j % q->length)]);
  }
  printf(YELLOW(" ]\n"));
  return;
}

int main() {
  srand(time(0)); // 加了这行，才会每次运行都是生成随机数。不然每次的随机数是一致的。
#define MAX_OP 20
  Queue *q = init(5); // 通过修改初始化时候的大小，可以看到是否扩容
  for (int i = 0; i < MAX_OP; i++) {
    int op = rand() % 4;
    int val = rand() % 100;
    switch (op) {
      case 0:
      case 1:
      case 2: {
        printf("push %d to Queue = %s\n", val, push(q, val) ? GREEN("success") : RED("ERROR"));
      } break;
      case 3: {
        if (empty(q)) {
          printf(RED("fail to pop a item \n"));
        } else {
          printf(BLUE("success to pop a item : %d\n"), front(q));
          pop(q);
        }
      } break;
    }
    output(q), printf("\n");
  }
#undef MAX_OP
  clear(q);
  return 0;
}