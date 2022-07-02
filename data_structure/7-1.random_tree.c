/**
 * @file 7-1.random_tree.c
 * @author RoyLau (897379293@qq.com)
 * @brief 生成随机树
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
  char data;
  struct node *lchild, *rchild;
} Node;

Node *insert_node(Node *root, int val) {
  if (root == NULL) {
    root = (Node *)malloc(sizeof(Node));
    root->data = 'A' + val;
    root->lchild = root->rchild = NULL;
    return root;
  }
  if (rand() % 2 == 0) {
    root->lchild = insert_node(root->lchild, val);
  } else {
    root->rchild = insert_node(root->rchild, val);
  }
  return root;
}
// 先序遍历
void pre_order(Node *root) {
  if (root == NULL) return;
  printf("%c -> ", root->data);
  pre_order(root->lchild);
  pre_order(root->rchild);
}

// 中序遍历
void in_order(Node *root) {
  if (root == NULL) return;
  in_order(root->lchild);
  printf("%c -> ", root->data);
  in_order(root->rchild);
}

// 后序遍历
void back_order(Node *root) {
  if (root == NULL) return;
  back_order(root->lchild);
  back_order(root->rchild);
  printf("%c -> ", root->data);
}

// 层序遍历
void level_order(Node *root) {
  Node *que[30];
  int front = 0, rear = 1;
  que[0] = root;
  while (front != rear) {
    Node *temp = que[front];
    front++;
    printf("%c -> ", temp->data);
    if (temp->lchild != NULL) {
      que[rear] = temp->lchild;
      rear++;
    }
    if (temp->rchild != NULL) {
      que[rear] = temp->rchild;
      rear++;
    }
  }

}

int main() {
  srand(time(0));
  Node *root = NULL;
  int n;
  scanf("%d", &n);
  for (int i = 0;i < n;i++) {
    root = insert_node(root, i);
  }
  pre_order(root); // 先序遍历
  printf("\n");
  in_order(root); // 中序遍历
  printf("\n");
  back_order(root); // 后序遍历
  printf("\n");
  level_order(root); // 层序遍历
  printf("\n");
  return 0;
}