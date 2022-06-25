/**
 * @file 3-1.vector.c
 * @author RoyLau (897379293@qq.com)
 * @brief 线性表 - 顺序表
 * @version 0.1
 * @date 2022-06-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>

 /**
  * @brief 定义顺序表数据类型
  * @param {int} *data 数据
  * @param {int} size 元素数量
  * @param {int} cap 容量上限
  */
typedef struct vector {
  int *data;
  int size, cap;
} Vector;

/**
 * @brief 初始化顺序表
 *
 * @param n 顺序表容量
 * @return Vector*
 */
Vector *init_vector(int n) {
  Vector *v = (Vector *)malloc(sizeof(Vector));
  v->data = (int *)malloc(sizeof(int) * n);
  v->size = 0;
  v->cap = n;
  return v;
}

/**
 * @brief 删除顺序表
 *
 * @param v 顺序表指针
 */
void delete_vector(Vector *v) {
  free(v->data);
  free(v);
  return;
}

/**
 * @brief 插入元素
 *
 * @param v
 * @param ind 下标(从 0 开始)
 * @param val 值
 * @return int
 */
int insert_ele(Vector *v, int ind, int val) {
  if (ind > v->size) return -1; // 越界
  // 扩容
  if (v->cap == v->size) {
    v->cap = 2;
    v->data = (int *)realloc(v->data, sizeof(int) * v->cap);
    printf("exp\n");
  }
  for (int i = v->size;i > ind;i--) {
    v->data[i] = v->data[i - 1];
  }
  v->data[ind] = val;
  v->size++;
  return 0;
}

/**
 * @brief 删除元素
 *
 * @param v
 * @param ind 删除的下标
 * @return int
 */
int delete_ele(Vector *v, int ind) {
  if (v->size <= ind) return -1;
  for (int i = ind + 1;i < v->size;i++) {
    v->data[i - 1] = v->data[i];
  }
  v->size--;
  return 1;
}

/**
 * @brief 展示顺序表的信息
 * 
 * @param v 
 */
void show_vector(Vector *v) {
  printf("v->size = %d, v->cap = %d\n", v->size, v->cap);
  for (int i = 0;i < v->size;i++) {
    printf("%d ", v->data[i]);
  }
  printf("\n--------------\n");
}


int main() {
  int max, n;
  scanf("%d%d", &max, &n);
  Vector *v = init_vector(max);
  for (int i = 0;i < n;i++) {
    int a, b, c;
    scanf("%d", &a);
    if (a == 0) {
      scanf("%d%d", &b, &c);
      insert_ele(v, b, c);
    } else {
      scanf("%d", &b);
      delete_ele(v, b);
    }
    show_vector(v);
  }
  delete_vector(v);

  return 0;
}