/**
 * @file 8.thead_tree.c
 * @author RoyLau
 * @brief 数据结构 - 线索化二叉树
 * @version 0.1
 * @date 2022-05-15
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NORMAL 0 // 正常的节点
#define THREAD 1 // 线索

 /**
  * @brief 定义线索化二叉树节点的数据结构
  *
  * @param data 数据值
  * @param *lchild 左子树 节点
  * @param *rchild 右子树 节点
  * @param ltag 右子树 标记
  * @param rtag 右子树 标记
  */
typedef struct Node {
  int data;
  struct  Node *lchild, *rchild;
  int ltag, rtag;
} Node;

/**
 * @brief 获取节点结构
 *
 * @param val 值
 * @return Node* 节点
 */
Node *getNewNode(int val) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = val;
  p->lchild = NULL;
  p->rchild = NULL;
  p->ltag = NORMAL;
  p->rtag = NORMAL;
  return p;
}

/**
 * @brief 插入节点
 *
 * @param root 根节点
 * @param val 值
 * @return Node* 节点
 */
Node *insert(Node *root, int val) {
  if (root == NULL) return getNewNode(val);
  if (root->data == val) return root;
  if (val < root->data)root->lchild = insert(root->lchild, val);
  else root->rchild = insert(root->rchild, val);
  return root;
}

/**
 * @brief 构建线索化
 *
 * @param root 根节点
 */
void build_thread(Node *root) {
  if (root == NULL) return;
  static Node *pre = NULL; // 前驱
  build_thread(root->lchild);
  if (root->lchild == NULL) {
    root->lchild = pre;
    root->ltag = THREAD;
  }
  if (pre != NULL && pre->rchild == NULL) {
    pre->rchild = root;
    pre->rtag = THREAD;
  }
  pre = root;
  build_thread(root->rchild);
  return;
}

/**
 * @brief 找到左侧最后一个节点
 *
 * @param p
 * @return Node*
 */
Node *most_left(Node *p) {
  while (p != NULL && p->ltag == NORMAL && p->lchild != NULL) p = p->lchild;
  return p;
}

/**
 * @brief 打印日志
 *
 * @param root 根节点
 */
void output(Node *root) {
  Node *p = most_left(root);
  while (p != NULL) {
    printf("%d ", p->data);
    if (p->rtag == THREAD) {
      p = p->rchild;
    } else {
      p = most_left(p->rchild);
    }
  }
  return;
}

/**
 * @brief 中序排序
 * 
 * @param root 
 */
void in_order(Node *root){
  if(root == NULL) return;
  if(root->ltag == NORMAL) in_order(root->lchild);
  printf("%d ", root->data);
  if(root->rtag == NORMAL) in_order(root->rchild);
  return;
}

/**
 * @brief 清除 gc
 * 
 * @param root 根节点
 */
void clear(Node *root) {
  if (root == NULL) return;
  if (root->lchild == NORMAL) clear(root->lchild);
  if (root->rchild == NORMAL) clear(root->rchild);
  free(root);
  return;
}


int main() {
  srand(time(0));
#define MAX_OP 20
  Node *root = NULL;
  for (int i = 0; i < MAX_OP;i++) {
    int val = rand() % 100;
    root = insert(root, val);
  }
  build_thread(root);
  output(root), printf("\n");
  in_order(root), printf("\n");
#undef MAX_OP
  clear(root);

  return 0;
}