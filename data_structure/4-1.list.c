/**
 * @file 4-1.list.c
 * @author RoyLau (897379293@qq.com)
 * @brief 线性表 - 单链表
 * @version 0.1
 * @date 2022-06-25
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

typedef struct list {
  struct node *head;
  int size;
}List;

/**
 * @brief 获取一个新节点
 *
 * @param x 值
 * @return Node*
 */
Node *get_new_node(int x) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = x;
  n->next = NULL;
  return n;
}

/**
 * @brief 初始化链表
 *
 * @return List*
 */
List *init_list() {
  List *l = (List *)malloc(sizeof(List));
  l->head = get_new_node(-1);
  l->size = 0;
  return l;
}

/**
 * @brief 删除链表及节点
 *
 * @param l
 */
void delete_list(List *l) {
  Node *n = l->head;
  while (n != NULL) {
    Node *t = n->next;
    free(n);
    n = t;
  }
  free(l);
  return;
}

/**
 * @brief 插入元素
 *
 * @param l 链表
 * @param ind 下标(从 0 开始)
 * @param val 值
 * @return int -1 失败， 0 成功；
 */
int insert_ele(List *l, int ind, int val) {
  if (ind > l->size) return -1;
  Node *n = l->head;
  for (int i = 0;i < ind;i++) {
    n = n->next;
  }
  Node *t = get_new_node(val);
  t->next = n->next;
  n->next = t;
  l->size++;
  return 0;
}

/**
 * @brief 删除元素
 *
 * @param l 链表
 * @param ind 下标
 * @return int -1 失败，0 成功；
 */
int delete_ele(List *l, int ind) {
  if (l->size <= ind) return -1;
  Node *n = l->head;
  for (int i = 0; i < ind; i++) {
    n = n->next;
  }
  Node *t = n->next;
  n->next = t->next;
  free(t);
  l->size--;
  return 0;
}

/**
 * @brief 展示链表
 *
 * @param l
 */
void show_list(List *l) {
  printf("l->size = %d\n", l->size);
  for (Node *n = l->head->next; n != NULL;n = n->next) {
    printf("%d-->", n->data);
  }
  printf("\n------------------------\n");
}

int main() {
  int n;
  scanf("%d", &n); // 操作次数
  List *l = init_list();
  for (int i = 0;i < n;i++) {
    int a, b, c;
    scanf("%d", &a);
    if (a == 0) { // 0 插入元素
      scanf("%d%d", &b, &c);
      insert_ele(l, b, c);
    } else { // 非0 删除元素
      scanf("%d", &b);
      delete_ele(l, b);
    }
    show_list(l);
  }
  delete_list(l);

  return 0;
}