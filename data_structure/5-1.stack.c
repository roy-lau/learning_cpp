/**
 * @file 5-1.stack.c
 * @author RoyLau (897379293@qq.com)
 * @brief 顺序栈
 * @version 0.1
 * @date 2022-06-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

 /**
  * @brief 栈的结构定义
  *
  * @param *data 数据
  * @param size 数据大小
  * @param top 栈顶
  * @param cap 容量
  */
typedef struct stack {
  int *data;
  int size, top, cap;
}Stack;

/**
 * @brief 初始化栈
 *
 * @param n 容量
 * @return Stack*
 */
Stack *init_stack(int n) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->data = (int *)malloc(sizeof(int) * n);
  s->size = 0;
  s->top = -1;
  s->cap = n;
  return s;
}

void delete_stack(Stack *s) {
  if (s == NULL) return;
  free(s->data);
  free(s);
  return;
}


void expend(Stack *s) {
  printf("expend\n");
  s->cap *= 2;
  s->data = (int *)realloc(s, sizeof(int) * s->cap);
}

int push(Stack *s, int val) {
  if (s == NULL) return 0;
  if (s->size >= s->cap) expend(s);
  s->data[++s->top] = val;
  s->size++;
  return 1;
}

int pop(Stack *s) {
  if (s == NULL) return 0;
  if (s->size < 1) return 0;
  s->size--;
  s->top--;
  return 1;
}

int top(Stack *s) {
  return s->data[s->top];
}

void show_stack(Stack *s) {
  printf("s->size = %d, s->cap = %d\n", s->size, s->cap);
  for (int i = 0;i < s->size;i++) {
    printf("s->data[%d] = %d, ", i, s->data[i]);
  }
  printf("\n---------------------\n");
}

int main() {
  int max, n;
  scanf("%d%d", &max, &n);
  Stack *s = init_stack(max);
  for (int i = 0;i < n;i++) {
    int a, b;
    scanf("%d", &a);
    if (a == 0) {
      scanf("%d", &b);
      push(s, b);
    } else if (a == 1) {
      pop(s);
    } else {
      printf("stack top --> %d\n", top(s));
    }
    show_stack(s);
  }
  delete_stack(s);

  return 0;
}