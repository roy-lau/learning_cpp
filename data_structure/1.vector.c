/**
 * @file 1.vector.c
 * @author RoyLau
 * @brief 数据结构 - 顺序表
 * @version 0.1
 * @date 2022-05-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h> // malloc 动态内存申请，向内存堆区申请空间
#include <time.h>

 // 定义颜色的宏
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define RED(a) COLOR(a, 31)    // 红色
#define GREEN(a) COLOR(a, 32)  // 绿色
#define YELLOW(a) COLOR(a, 33) // 黄色
#define BLUE(a) COLOR(a, 34)   // 蓝色

//  顺序表的结构定义
typedef struct Vector {
    int *data;
    int size, length;
} Vector;

//  顺序表的初始化操作
Vector *init(int n) {
    // malloc 申请内存大小
    Vector *v = (Vector *)malloc(sizeof(Vector)); //  给结构体申请空间
    v->data = (int *)malloc(sizeof(int) * n);     //  申请 n 个空间，转为 int类型，赋值给 data
    // 初始化size length字段
    v->size = n;
    v->length = 0;
    return v;
}

// 扩容(开辟空间)
int expand(Vector *v) {
    int extr_size = v->size;
    int *p;
    while (extr_size) {
        // 在原有空间大小上开辟 extr_size 大小的空间
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));
        // 不为 null 说明扩容成功
        if (p != NULL)
            break;
        // 右移一位，相当于在原有的基础上除以 2.
        extr_size >>= 1;
    }
    // 扩容失败，返回 0
    if (p == NULL) return 0;
    // 将扩容后的空间大小和原来的数据赋值给 v->data
    v->data = p;
    // 增加扩容后的空间大小
    v->size += extr_size;
    return 1;
}

/**
 * 插入数据
 */
int insert(Vector *v, int ind, int val) {
    if (v == NULL) return 0;
    // if(v->length == v->size) return 0; //  长度等于容量，说明链表内存满了
    if (v->length == v->size) {
        if (!expand(v))
            return 0;
        printf(GREEN("success to expand!  the size = %d\n"), v->size);
    }
    if (ind < 0 || ind > v->length)
        return 0;
    for (int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val; // 数据赋值(更新)
    v->length += 1;     //  长度加一
    return 1;
}

// 删除数据
int erase(Vector *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

//  输出操作表的时的日志
void output(Vector *v) {
    if (v == NULL) return;
    printf("Vector : [");
    for (int i = 0; i < v->length; i++) {
        i &&printf(" ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return;
}

/**
 * @brief 清空&&销毁数据表
 *
 * @param v 数据表结构
 */
void clear(Vector *v) {
    if (v == NULL) return;    // 判断如果 v 不存在，直接 return
    free(v->data); // 释放掉 v->data
    free(v);       // 释放掉
    return;
}

//  顺序表的结构操作
int main() {
    srand(time(0)); // 加了这行，才会每次运行都是生成随机数。不然每次的随机数是一致的。
// 定义宏
#define MAX_OP 20
    Vector *v = init(1); // 通过修改初始化时候的大小，可以看到是否扩容
    /*
     * 遍历宏
     * 生成 0、1 随机数
     * 随机向链表里插入或者清除数据
     */
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;
        int val = rand() % 1000;
        int ind = rand() % (v->length + 3) - 1; // 为了测试边界情况，[-1,v->length+1]
        switch (op) {
        case 0:
        case 1:
        case 2: {
            printf("insert %d at %d to Vector = %d\n", val, ind, insert(v, ind, val));
        } break;
        case 3: {
            printf(RED("erase a iterm at %d from Vector = %d\n"), ind, erase(v, ind));
        } break;
        }
        output(v), printf("\n");
    }
#undef MAX_OP //  清除、释放宏
    clear(v); // 清除、释放链表
    return 0;
}
