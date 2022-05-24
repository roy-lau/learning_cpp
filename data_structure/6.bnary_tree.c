/**
 * @file 6.bnary_tree.c
 * @author RoyLau
 * @brief 数据结构 - 二叉树🌲
 * @version 0.1
 * @date 2022-05-13
 * @desc 排序二叉树 lchild < root, rchild > root
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
#define PURPLE(a) COLOR(a, 35) // 紫色

 /**
  * @brief 树节点 的结构定义
  *
  * @param data 节点数据
  * @param *lchild 左孩子节点
  * @param *rchild 右孩子节点
  */
typedef struct Node {
  int data;
  struct Node *lchild, *rchild;
} Node;

/**
 * @brief 树 的结构定义
 *
 * @param *root 根节点
 * @param length 节点数量
 */
typedef struct Tree {
  struct Node *root;
  int length;
} Tree;

/**
 * @brief 获取新的树节点
 *
 * @param val 值
 * @return Node* 节点
 */
Node *getNewNode(int val) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->data = val;
  p->lchild = p->rchild = NULL;
  return p;
}

/**
 * @brief 获取新的树
 *
 * @return Tree* 树
 */
Tree *getNewTree() {
  Tree *tree = (Tree *)malloc(sizeof(Tree));
  tree->root = NULL;
  tree->length = 0;
  return tree;
}

/**
 * @brief 插入 - 节点
 *
 * @param root 跟节点
 * @param val 要插入的值
 * @param flag 节点数量标记
 * @return Node* 节点
 */
Node *insert_node(Node *root, int val, int *flag) {
  if (root == NULL) {
    *flag = 1;
    return getNewNode(val);
  }
  if (root->data == val) return root;
  else if (root->data < val) root->lchild = insert_node(root->lchild, val, flag);
  else root->rchild = insert_node(root->rchild, val, flag);
  return root;
}

/**
 * @brief 插入 - 树
 *
 * @param tree 树
 * @param val 值
 */
void insert(Tree *tree, int val) {
  if (tree == NULL) return;
  int flag = 1;
  tree->root = insert_node(tree->root, val, &flag);
  tree->length += 1;
  return;
}

/**
 * @brief 清除 - 节点
 *
 * @param root 根节点
 */
void clear_node(Node *root) {
  if (root == NULL) return;
  clear_node(root->lchild);
  clear_node(root->rchild);
  free(root);
  return;
}

/**
 * @brief 清除 - 树
 *
 * @param tree 树
 */
void clear(Tree *tree) {
  if (tree == NULL) return;
  clear_node(tree->root);
  return;
}

/**
 * @brief 前序遍历 - 节点
 *
 * @param root 根节点
 */
void pre_order_node(Node *root) {
  if (root == NULL) return;
  printf(PURPLE("%d "), root->data); // 注意： 前、中、后 序遍历，只是这一行的位置变化
  pre_order_node(root->lchild);
  pre_order_node(root->rchild);
  return;
}
/**
 * @brief 前序遍历 - 树
 *
 * @param tree
 */
void pre_order(Tree *tree) {
  if (tree == NULL) return;
  printf(PURPLE("pre_order : "));
  pre_order_node(tree->root);
  printf("\n");
  return;
}


/**
 * @brief 中序遍历 - 节点
 *
 * @param root 根节点
 */
void in_order_node(Node *root) {
  if (root == NULL) return;
  in_order_node(root->lchild);
  printf(PURPLE("%d "), root->data); // 注意： 前、中、后 序遍历，只是这一行的位置变化
  in_order_node(root->rchild);
  return;
}
/**
 * @brief 中序遍历 - 树
 *
 * @param tree
 */
void in_order(Tree *tree) {
  if (tree == NULL) return;
  printf(PURPLE("in_order : "));
  in_order_node(tree->root);
  printf("\n");
  return;
}


/**
 * @brief 后序遍历 - 节点
 *
 * @param root 根节点
 */
void post_order_node(Node *root) {
  if (root == NULL) return;
  post_order_node(root->lchild);
  post_order_node(root->rchild);
  printf(PURPLE("%d "), root->data); // 注意： 前、中、后 序遍历，只是这一行的位置变化
  return;
}
/**
 * @brief 后序遍历 - 树
 *
 * @param tree
 */
void post_order(Tree *tree) {
  if (tree == NULL) return;
  printf(PURPLE("post_order : "));
  post_order_node(tree->root);
  printf("\n");
  return;
}

/**
 * @brief 输出 - 节点
 * @summary 广义表的格式输出, 例子： A(B,C)
 *
 * @param root 根节点
 */
void output_node(Node *root) {
  if (root == NULL) return;
  printf(YELLOW("%d"), root->data);
  if (root->lchild == NULL || root->rchild == NULL) return;
  printf(YELLOW("( "));
  output_node(root->lchild);
  printf(YELLOW(", "));
  output_node(root->rchild);
  printf(YELLOW(" )"));
  return;
}

/**
 * @brief 输出 - 树
 *
 * @param tree 树
 */
void output(Tree *tree) {
  if (tree == NULL) return;
  printf(YELLOW("Tree(%d) : "), tree->length);
  output_node(tree->root);
  printf("\n");
  return;
}

int main() {
  srand(time(0));
  Tree *tree = getNewTree();
#define MAX_OP 20
  for (int i = 0; i < MAX_OP; i++) {
    int val = rand() % 100;
    insert(tree, val);
    output(tree);
  }
  pre_order(tree);
  in_order(tree);
  post_order(tree);
  clear(tree);
#undef MAX_OP

  return 0;
}