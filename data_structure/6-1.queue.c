/**
 * @file 6-1.queue.c
 * @author RoyLau (897379293@qq.com)
 * @brief 循环队列
 * @version 0.1
 * @date 2022-06-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

 /**
  * @brief 队列结构定义
  *
  * @param *data 数据
  * @param front 队首
  * @param rear 队尾
  * @param cap 容量
  * @param size 大小
  *
  */
typedef struct queue {
  int *data;
  int front, rear, cap, size;
}Queue;

Queue *init_queue(int n) {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->data = (int *)malloc(sizeof(int) * n);
  q->front = q->rear = q->size = 0;
  q->cap = n;
  return q;
}

void delete_queue(Queue *q) {
  free(q->data);
  free(q);
  return;
}

int get_front(Queue *q) {
  if (q == NULL && q->size < 1)return -1;
  return q->data[q->front];
}

/**
 * @brief 扩容
 *
 * @param q 队列
 */
void expend(Queue *q) {
  int *p = (int *)malloc(sizeof(int) * (q->cap) * 2);
  for (int i = 0, j = q->front;j != q->rear;i++, j++, j %= q->cap) {
    p[i] = q->data[j];
  }
  int *t = q->data;
  q->data = p;
  free(t);
  q->cap *= 2;
  q->front = 0;
  q->rear = q->size;
}

int push(Queue *q, int val) {
  if (q == NULL) return 0;
  if (q->rear + 1 == q->cap) {
    printf("expend ++\n");
    expend(q);
  }
  q->data[q->rear] = val;
  q->rear++;
  if (q->rear == q->cap) q->rear = 0;
  q->size++;
  return 1;
}

int pop(Queue *q) {
  if (q->size == 0) return 0;
  q->front++;
  if (q->front == q->cap) q->front = 0;
  q->size--;
  return 1;
}

void show_queue(Queue *q) {
  printf("q->size = %d, q->cap = %d\n", q->size, q->cap);
  for (int i = q->front;i != q->rear;i++, i %= q->cap) {
    printf("%d ", q->data[i]);
  }
  printf("\n------------------------\n");
}

int main() {
  int max, n;
  scanf("%d%d", &max, &n);
  Queue *q = init_queue(max);
  for (int i = 0;i < n;i++) {
    int a, b;
    scanf("%d", &a);
    if (a == 0) {
      scanf("%d", &b);
      push(q, b);
    } else if (a == 1) {
      pop(q);
    } else {
      printf("queue front = %d\n", get_front(q));
    }
    show_queue(q);
  }
  delete_queue(q);

  return 0;
}