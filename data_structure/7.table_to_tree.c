/**
 * @file 7.table_to_tree.c
 * @author RoyLau
 * @brief 数据结构 - 广义表转二叉树
 * @version 0.1
 * @date 2022-05-14
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

 // 定义颜色的宏
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
// #define RED(a) COLOR(a, 31)    // 红色
// #define GREEN(a) COLOR(a, 32)  // 绿色
// #define YELLOW(a) COLOR(a, 33) // 黄色
// #define BLUE(a) COLOR(a, 34)   // 蓝色
#define PURPLE(a) COLOR(a, 35) // 紫色

 /**
  * @brief 树节点 的结构定义
  *
  * @param data 树节点数据
  * @param lchild 树左节点
  * @param rchild 树右节点
  */
typedef struct Node {
  char data;
  struct Node *lchild, *rchild;
} Node;

/**
 * @brief 树 的结构定义
 *
 * @param *root 根节点
 * @param length 树的节点数量
 */
typedef struct Tree {
  Node *root;
  int length;
} Tree;

/**
 * @brief 栈 的结构定义
 *
 * @param **data 栈节点数据
 * @param top 栈顶指针
 * @param size 栈内存
 */
typedef struct Stack {
  Node **data;
  int top, size;
} Stack;


/**
 * @brief 获取新的树节点
 *
 * @param val 值
 * @return Node* 节点
 */
Node *getNewNode(char val) {
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
 * @brief 初始化栈
 *
 * @param n 栈初始化的大小
 * @return Stack* 栈
 */
Stack *init_stack(int n) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->data = (Node **)malloc(sizeof(Node *) * n);
  s->top = -1;
  s->size = n;
  return s;
}

/**
 * @brief 获取栈顶元素
 *
 * @param s 栈
 * @return Node* 栈顶节点
 */
Node *top(Stack *s) {
  return s->data[s->top];
}

/**
 * @brief 判断栈是否为空
 *
 * @param s 栈
 * @return int 1 空，0 非空
 */
int empty(Stack *s) {
  return s->top == -1;
}

/**
 * @brief 入栈（压栈）
 *
 * @param s 栈
 * @param val 值
 * @return int 1 成功，0 失败
 */
int push(Stack *s, Node *val) {
  if (s == NULL) return 0;
  if (s->top == s->size - 1) return 0;
  s->data[++(s->top)] = val;
  return 1;
}

/**
 * @brief 出栈（弹栈）
 *
 * @param s 栈
 * @return int 1 成功，0 失败
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
void clear_stack(Stack *s) {
  if (s == NULL) return;
  free(s->data);
  free(s);
  return;
}

/**
 * @brief 清空 树节点
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
 * @brief 清空 树
 *
 * @param tree 树
 */
void clear_tree(Tree *tree) {
  if (tree == NULL) return;
  clear_node(tree->root);
  free(tree);
  return;
}

/**
 * @brief 前序遍历 - 节点
 *
 * @param root 根节点
 */
void pre_order_node(Node *root) {
  if (root == NULL) return;
  printf(PURPLE("%c "), root->data); // 注意： 前、中、后 序遍历，只是这一行的位置变化
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
  printf(PURPLE("%c "), root->data); // 注意： 前、中、后 序遍历，只是这一行的位置变化
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
  printf(PURPLE("%c "), root->data); // 注意： 前、中、后 序遍历，只是这一行的位置变化
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
 * @brief 构建树的根节点
 *
 * @param str 广义表字符串
 * @param node_num 节点数量
 * @return Node* 节点
 */
Node *build(const char *str, int *node_num) {
  Stack *s = init_stack(strlen(str));
  int flag = 0;
  Node *temp = NULL, *p = NULL;
  while (str[0]) {
    switch (str[0]) {
      case '(': {
        push(s, temp);
        flag = 0;
      } break;
      case ')': {
        p = top(s);
        pop(s);
      } break;
      case ',': {
        flag = 1;
      } break;
      case ' ': break;
      default: {
        temp = getNewNode(str[0]);
        if (!empty(s) && flag == 0) {
          top(s)->lchild = temp;
        } else if (!empty(s) && flag == 1) {
          top(s)->rchild = temp;
        }
        ++(*node_num);
      } break;
    }
    str++;
  }
  clear_stack(s);
  if (temp && p == NULL) p = temp;
  return p;
}

int main() {
  char str[1000] = { 0 };
  int node_num = 0;

  printf("请输入广义表：\n");
  scanf("%[^\n]s", str); // 获取带空格的字符
  getchar(); // 清除输入的换行

  Tree *tree = getNewTree();
  tree->root = build(str, &node_num);
  tree->length = node_num;

  pre_order(tree);
  in_order(tree);
  post_order(tree);
  clear_tree(tree);
  return 0;
}