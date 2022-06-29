/**
 * @file 6-2.queue_list.c
 * @author RoyLau (897379293@qq.com)
 * @brief 链式队列
 * @version 0.1
 * @date 2022-06-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
}Node;

typedef struct queue {
  struct node *head;
  int size;
}Queue;

Queue *init_queue() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->head = (Node *)malloc(sizeof(Node));
  q->head->next = q->head;
  q->size = 0;

  return q;
}

void delete_queue(Queue *q) {
  Node *n = q->head->next;
  while (n != q->head) {
    Node *t = n->next;
    free(n);
    n = t;
  }
  free(q->head);
  free(q);
}

int get_front(Queue *q) {
  if (q->size < 0) return 0;
  return q->head->next->data;
}

int push(Queue *q, int val) {
  if (q == NULL) return 0;
  Node *n = (Node *)malloc(sizeof(Node));
  n->next = q->head->next;
  q->head->data = val;
  q->head->next = n;
  q->head = n;
  q->size++;
  return 1;
}

int pop(Queue *q) {
  if (q->size < 1) return 0;
  Node *n = q->head->next;
  q->head->next = n->next;
  free(n);
  q->size--;
  return 0;
}

void show_queue(Queue *q) {
  printf("q->size = %d\n", q->size);
  for (Node *n = q->head->next;n != q->head;n = n->next) {
    printf("%d ", n->data);
  }
  printf("\n-------------------------\n");
}

int main() {
  int  n;
  scanf("%d", &n);
  Queue *q = init_queue();
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
