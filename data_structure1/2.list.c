/**
 * @file 2.list.c
 * @author RoyLau
 * @brief 数据结构 - 链表
 * @version 0.1
 * @date 2022-05-07
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
#define PURPLE(a) COLOR(a, 35) // 紫色

// 结构定义
typedef struct Node {
  int data;          // 节点数据
  struct Node *next; // 指针域
} Node;

typedef struct List {
  Node head; // 虚拟头节点
  int length;
} List;

Node *getNewNode(int);
List *init_list();
void clear_node(Node *);
void clear(List *);
int insert(List *, int, int);
int erase(List *, int);

/**
 * 节点初始化
 *
 * @param val 节点值
 * @return Node* 返回节点
 */
Node *getNewNode(int val) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = val;
  p->next = NULL;
  return p;
}

/**
 * 链表初始化
 *
 * @return List* 返回链表
 */
List *init_list() {
  List *l = (List *)malloc(sizeof(List));
  l->head.next = NULL;
  l->length = 0;
  return l;
}

/**
 * @brief 插入节点
 *
 * @param l 链表
 * @param ind 下标
 * @param val 值
 * @return int 成功 1，失败 0；
 */
int insert(List *l, int ind, int val) {
  if (l == NULL) return 0;
  if (ind < 0 || ind > l->length) return 0;
  Node *p = &(l->head), *node = getNewNode(val);
  while (ind--) p = p->next;
  node->next = p->next;
  p->next = node;
  l->length += 1;
  return 1;
}

/**
 * @brief 删除指定节点
 *
 * @param l 链表
 * @param ind 下标
 * @return int
 */
int erase(List *l, int ind) {
  if (l == NULL) return 0;
  if (ind < 0 || ind > l->length) return 0;
  Node *p = &(l->head), *q;
  while (ind--) p = p->next;
  q = p->next;
  p->next = q->next;
  clear_node(q);
  l->length -= 1;
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
 * @brief 清除整个链表
 *
 * @param l 链表
 */
void clear(List *l) {
  if (l == NULL) return;
  Node *p = l->head.next, *q;
  while (p != NULL) {
    q = p->next;
    clear_node(p);
    p = q;
  };
  free(l);
  return;
}

/**
 * @brief 链表翻转
 *
 * @param l 链表
 */
void reverse(List *l) {
  if (l == NULL) return;
  Node *p = l->head.next, *q;
  l->head.next = NULL;
  while (p != NULL) {
    q = p->next;
    p->next = l->head.next;
    l->head.next = p;
    p = q;
  }
  return;
}
/**
 * @brief 输出日志
 *
 * @param l 链表
 */
void output(List *l) {
  if (l == NULL) return;
  printf(YELLOW("list(%d) : "), l->length);
  for (Node *p = l->head.next; p != NULL; p = p->next) {
    printf("%d->", p->data);
  }
  printf("NULL\n");
  return;
}

int main() {
  srand(time(0)); // 加了这行，才会每次运行都是生成随机数。不然每次的随机数是一致的。
#define MAX_OP 20
  List *l = init_list();
  for (int i = 0; i < MAX_OP; i++) {
    int op = rand() % 4;
    int val = rand() % 100;
    int ind = rand() % (l->length + 3) - 1;
    switch (op) {
      case 0:
      case 1: {
        printf(BLUE("insert %d at %d to list = %s\n"), val, ind, insert(l, ind, op)? GREEN("success") : RED("ERROR"));
      } break;
      case 2:
      {
        printf(PURPLE("reverse the List!\n"));
        reverse(l);
      } break;
      case 3:
      {
        printf(RED("erase a item at %d from List = %d\n"), ind, erase(l, ind));
      }
      break;
    }
    output(l), printf("\n");
  }
#undef MAX_OP
  clear(l);
  return 0;
}