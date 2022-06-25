/**
 * @file 3.2.queue.c
 * @author RoyLau
 * @brief 数据结构 - 链队列
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
 * @brief 定义 节点 结构 
 *
 * @param data 数据
 * @param *next 下一节点
 */
typedef struct Node {
  int data;
  struct Node *next;
} Node;

/**
 * @brief 定义 队列 结构
 *
 * @param head 头节点
 * @param tail 尾节点
 * @param length  队列长度（容量&内存）
 */
typedef struct Queue {
  Node head, *tail;
  int length;
} Queue;

Node *getNewNode(int);
Queue *init_linkQueue();
void clear_node(Node *);
void clear(Queue *);
int push(Queue *, int);
int pop(Queue *);
int empty(Queue *);
int front(Queue *);


/**
 * @brief 初始化节点
 *
 * @param val 值
 * @return Node* 节点 
 */
Node *getNewNode(int val) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = val;
  p->next = NULL;
  return p;
}

/**
 * @brief 初始化链队列
 *
 * @return Queue* 队列
 */
Queue *init_linkQueue() {
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->head.next = NULL;
  q->tail = &(q->head);
  q->length = 0;
  return q;
}

/**
 * @brief 判断当前队列是否为空
 *
 * @param q 队列
 * @return int 空 1，非空 0
 */
int empty(Queue *q) {
  return q->length == 0;
}

/**
 * @brief 返回队首的元素
 *
 * @param q 队列
 * @return int
 */
int front(Queue *q) {
  return q->head.next->data;
}

/**
 * @brief 入队
 *
 * @param q 队列
 * @param val 值
 * @return int 成功 1，失败 0
 */
int push(Queue *q, int val) {
  if (q == NULL) return 0;
  Node *node = getNewNode(val);
  q->tail->next = node;
  q->tail = node;
  q->length += 1;
  return 1;
}

/**
 * @brief 出队
 *
 * @param q 队列
 * @return int 成功 1，失败 0
 */
int pop(Queue *q) {
  if (q == NULL) return 0;
  if (empty(q)) return 0;
  Node *temp = q->head.next;
  q->head.next = temp->next;
  clear_node(temp);
  q->length -= 1;
  if(q->length == 0) q->tail = &(q->head);
  return 1;
}

/**
 * @brief 清除节点
 *
 * @param node 节点
 */
void clear_node(Node *node) {
  if (node == NULL) return;
  free(node);
  return;
}

/**
 * @brief 清除队列
 *
 * @param q 队列
 */
void clear(Queue *q) {
  if (q == NULL) return;
  Node *p = q->head.next, *temp;
  while (p != NULL) {
    temp = p->next;
    clear_node(p);
    p = temp;
  }
  free(q);
  return;
}

void output(Queue *q) {
  printf(YELLOW("Queue(%d) : ["), q->length);
  for (Node *p = q->head.next;p != NULL;p = p->next) {
    p != q->head.next && printf(" ");
    printf(YELLOW("%d"), p->data);
  }
  printf(YELLOW("]\n"));
  return;
}

int main() {
  srand(time(0)); // 加了这行，才会每次运行都是生成随机数。不然每次的随机数是一致的。
#define MAX_OP 20
  Queue *q = init_linkQueue();
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