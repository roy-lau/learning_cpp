/**
 * @file 5-2.stack_list.c
 * @author RoyLau (897379293@qq.com)
 * @brief 链栈
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

typedef struct stack {
  struct node *head;
  int size;
}Stack;

Stack *init_stack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->head = (Node *)malloc(sizeof(Node));
  s->head->next = NULL;
  s->size = 0;
  return s;
}

void delete_stack(Stack *s) {
  if (s == NULL) return;
  Node *n = s->head;
  while (n != NULL) {
    Node *t = n->next;
    free(n);
    n = t;
  }
  free(s);
  return;
}

int get_top(Stack *s) {
  if (s->size < 1) return -1;
  return s->head->next->data;
}

int push(Stack *s, int val) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = val;
  n->next = s->head->next;
  s->head->next = n;
  s->size++;
  return 0;
}

int pop(Stack *s) {
  if (s->size < 1) return -1;
  Node *n = s->head->next;
  s->head->next = n->next;
  free(n);
  s->size--;
  return 0;
}

void show_stack(Stack *s) {
  printf("s->size = %d\n", s->size);
  Node *n = s->head->next;
  while (n != NULL) {
    printf("%d --> ", n->data);
    n = n->next;
  }
  printf("\n------------------------------\n");
}

int main() {
  int n;
  scanf("%d", &n);
  Stack *s = init_stack();
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d", &a);
    if (a == 0) {
      scanf("%d", &b);
      push(s, b);
    } else if (a == 1) {
      pop(s);
    } else {
      printf("Stack top = %d\n", get_top(s));
    }
    show_stack(s);
  }
  delete_stack(s);

  return 0;
}