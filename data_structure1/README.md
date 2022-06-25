# c 语言数据结构

```sh
# 编译
gcc ${fileName}.c -o ${fileName}.out
# 运行
./${fileName}.out
```

### [格式化文件配置](https://www.cnblogs.com/jie828/p/13737885.html)

```sh
clang-format -style=llvm -dump-config > .clang-format
```

### 顺序表
### 链表
### 队列
#### 循环队列
### 链队列
### 栈
### 二叉树
#### 广义表转二叉树
#### 线索化二叉树

### 排序算法
#### 稳定排序
  - 插入排序
  - 冒泡排序
  - 归并排序
#### 非稳定排序
  - 选择排序
  - 快速排序
  - 快速排序(优化后)
### 哈希表
### 堆与优先队列
### 森林与并查集


指针 = 存内存地址的变量
`*` 标记加在类型之后标记了的变量是用于存储地址值而不是普通的数值的
`&` 取地址符

```cpp
#include <stdio.h>

int main() {
  int i = 1;
  printf("i is %d\n", i);
  int *d;
  printf("d is %p\n", d);
  printf("d is %p\n", &d);

  int year = 2022;
  int *p_year;
  p_year = &year;
  printf("year is %d\n", year);
  printf("&year is %p\n", &year);
  printf("p_year is %p\n", p_year);
  printf("*p_year is %d\n", *p_year);
  printf("&p_year is %p\n", &p_year);
}
// 输出如下：
// i is 1
// d is 0x13
// d is 0x7ff7bcb194e0
// year is 2022
// &year is 0x7ff7bcb194dc
// p_year is 0x7ff7bcb194dc
// *p_year is 2022
// &p_year is 0x7ff7bcb194d0
```


[vsCode c 语言 代码格式化](https://blog.csdn.net/booksyhay/article/details/121105145)