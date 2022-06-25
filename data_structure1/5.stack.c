/**
 * @file 5.stack.c
 * @author RoyLau
 * @brief 数据结构 - 栈
 * @version 0.1
 * @date 2022-05-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

 // 定义颜色的宏
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define RED(a) COLOR(a, 31)    // 红色
#define GREEN(a) COLOR(a, 32)  // 绿色
#define YELLOW(a) COLOR(a, 33) // 黄色
#define BLUE(a) COLOR(a, 34)   // 蓝色

 /**
  * @brief 定义 栈 结构
  *
  * @param *data 数据
  * @param top 栈顶指针
  * @param size 容量
  */
typedef struct Stack {
  int *data;
  int top, size;
} Stack;

/**
 * @brief 初始化 栈
 *
 * @param n 容量
 * @return Stack* 栈
 */
Stack *init(int n) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->data = (int *)malloc(sizeof(int) * n);
  s->size = n;
  s->top = -1;
  return s;
}

/**
 * @brief 判断栈是否为空
 *
 * @param s 栈
 * @return int 空 1，非空 0
 */
int empty(Stack *s) {
  return s->top == -1;
}

/**
 * @brief 获取栈顶元素
 *
 * @param s 栈
 * @return int 栈顶元素的值
 */
int top(Stack *s) {
  return s->data[s->top];
}

/**
 * @brief 扩容
 *
 * @param s 栈
 * @return int 成功 1，失败 0
 */
int expand(Stack *s) {
  int extr_size = s->size;
  int *p;
  while (extr_size) {
    p = (int *)realloc(s->data, sizeof(s->size + extr_size)); // 循环扩容
    if (p != NULL) break;
    extr_size >>= 1;
  }
  if (p == NULL) return 0;
  s->data = p;
  s->size += extr_size;
  return 1;

}
/**
 * @brief 入栈（压栈）
 *
 * @param s 栈
 * @param val 值
 * @return int 成功 1，失败 0
 */
int push(Stack *s, int val) {
  if (s == NULL) return 0;
  if (s->top == s->size - 1) {
    if (!expand(s)) return 0;
    printf(GREEN("success to expand! the size = %d\n"), s->size);
  }
  s->top += 1;
  s->data[s->top] = val;
  return 1;
}

/**
 * @brief 出栈（弹栈）
 *
 * @param s 栈
 * @return int 成功 1，失败 0 
 */
int pop(Stack *s) {
  if (s == NULL) return 0;
  if (empty(s)) return 0;
  s->top -= 1;
  return 1;
}

/**
 * @brief 清空 栈
 *
 * @param s 栈
 */
void clear(Stack *s) {
  if (s == NULL) return;
  free(s->data);
  free(s);
  return;
}

/**
 * @brief 打印日志
 *
 * @param s 栈
 */
void output(Stack *s) {
  printf(YELLOW("Stack(%d) : ["), s->size);
  for (int i = 0; i <= s->top; i++) {
    i &&printf(" ");
    printf(YELLOW("%d"), s->data[i]);
  }
  printf(YELLOW("]\n"));
  return;
}

int main() {
  srand(time(0));
#define MAX_OP 20
  Stack *s = init(2); // 通过修改初始化时候的大小，可以看到是否扩容
  for (int i = 0; i < MAX_OP; i++) {
    int op = rand() % 4;
    int val = rand() % 100;
    switch (op) {
      case 0:
      case 1:
      case 2: {
        printf("push %d to Stack = %s\n", val, push(s, val) ? GREEN("success") : RED("ERROR"));
      } break;
      case 3: {
        if (empty(s)) {
          printf(RED("fail to pop a item \n"));
        } else {
          printf(BLUE("success to pop a item : %d\n"), top(s));
          pop(s);
        }
      } break;
    }
    output(s), printf("\n");
  }
#undef MAX_OP
  clear(s);

  return 0;
}