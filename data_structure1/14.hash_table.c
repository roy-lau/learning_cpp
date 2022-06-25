/**
 * @file 14.hash_table.c
 * @author RoyLau
 * @brief 数据结构 - 哈希表
 * @version 0.1
 * @date 2022-05-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 /**
  * @brief 哈希表节点 的结构定义
  *
  * @param *str 节点值
  * @param *next 下一节点指针
  */
typedef struct Node {
  char *str;
  struct Node *next;
} Node;

/**
 * @brief 哈希表 的结构定义
 *
 * @param *data 节点数据
 * @param size  哈希表大小内存
 */
typedef struct HashTable {
  Node **data;
  int size;
} HashTable;


/**
 * @brief 初始化 节点
 *
 * @param str 字符串值
 * @param head 头指针
 * @return Node* 节点
 * @tip 头插法
 */
Node *init_node(char *str, Node *head) {
  Node *p = (Node *)malloc(sizeof(Node));
  p->str = strdup(str); // strdup: 拷贝字符串
  p->next = head;
  return p;
}

/**
 * @brief 初始化 哈希表
 *
 * @param n 长度
 * @return HashTable 哈表 
 */
HashTable *init_hashtable(int n) {
  HashTable *h = (HashTable *)malloc(sizeof(HashTable));
  h->size = n << 1;
  h->data = (Node **)calloc(h->size, sizeof(Node *));
  return h;
}

/**
 * @brief 生成 hash 值
 *
 * @param str 字符值
 * @return int 哈希值
 */
int BKDRHash(char *str) {
  int seed = 31, hash = 0;
  for (int i = 0; str[i]; i++) hash = hash * seed + str[i];
  return hash & 0x7fffffff;
}

/**
 * @brief 哈希表 插入操作
 *
 * @param h 哈希表
 * @param str 插入字符
 * @return int 1 成功，0 失败
 */
int insert(HashTable *h, char *str) {
  int hash = BKDRHash(str);
  int ind = hash % h->size;
  h->data[ind] = init_node(str, h->data[ind]);
  return 1;
}

/**
 * @brief 哈希表 查找操作
 *
 * @param h 哈希表
 * @param str 查找字符值
 * @return int 1 成功，0 失败
 */
int search(HashTable *h, char *str) {
  int hash = BKDRHash(str);
  int ind = hash % h->size;
  Node *p = h->data[ind];
  while (p && strcmp(p->str, str)) p = p->next;
  return p != NULL;
}

/**
 * @brief 哈希表格 清除节点操作
 *
 * @param node 节点
 */
void clear_node(Node *node) {
  if (node == NULL) return;
  Node *p = node, *q;
  while (p) {
    q = p->next;
    free(p->str);
    free(p);
    p = q;
  }
  return;
}

/**
 * @brief 清除哈希表操作
 *
 * @param h 哈希表
 */
void clear(HashTable *h) {
  if (h == NULL) return;
  for (int i = 0; i < h->size;i++) {
    clear_node(h->data[i]);
  }
  free(h->data);
  free(h);
  return;
}


int main() {
  int op;
#define MAX_N 100
  char str[MAX_N + 5] = { 0 };
  HashTable *h = init_hashtable(MAX_N + 5);
  printf("插入哈希表格: 输入 0 然后输入字符\n查询哈希表: 输入 1 然后输入字符\n");
  while (~scanf("%d%s", &op, str)) {
    switch (op) {
      case 0: {
        printf("insert %s to HashTable\n", str);
        insert(h, str);
        break;
      }
      case 1: {
        printf("search %s from HashTable result = %d\n", str, search(h, str));
        break;
      }
      default: {
        printf("输入有误！\n");
      }
    }
  }
#undef MAX_N
  clear(h);
  return 0;
}