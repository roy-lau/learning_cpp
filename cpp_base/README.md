# cpp 

## C 语言与 C++语言

**c 语言**：面向过程  
**c++ 语言**：面向过程，面向对象，……

C++语言是为了字啊兼容 C 语言的前提下增加面向对象的编程凡是而设计的语言（初期）

### 头文件的区别

|C 语言|C++ 语言
|-|-
|`stdio.h` 标准输入输出 | **C**`stdio` C语言标准输入输出
|`stdlib.h` 标准库 | **C**`stdlib` C语言标准库
|`string.h` 字符串库 | **C**`string` C语言字符串库
|`match.h` 字符串库 | **C**`match` C语言数学库
| ………… | `iostream` 输入输出流
| | `algorithm` 算法库
| | `string` 字符串库
| | …………

### 简单的代码对比
- C++语言
```cpp
#include <iostream>
using namespace std;
int main(){
  return 0;
}
```
- C 语言
```C
#include <stdio.h>
int main(){
  return 0;
}
```

### 编译器对比

> LLVM(low level virtual machine)
- C 语言： `gcc`
- C++ 语言： `g++`

### [输入输出对比](./1-1.c_cpp_in_out.cpp)

|C 语言|C++ 语言
|-|-
|`scanf("%d",&x);` | `scanf("%d",&x);`
|`scanf("%lf",&y);` | `scanf("%lf",&y);`
|`printf("%d",&x);` | `printf("%d",&x);`
| | `cin >> x;`
| | `cin >> y;`
| | `cout << x << endl;`

未经任何操作的 `cin` 与 `cout` 在效率上低于 `scanf` 与 `printf`

- `ios_base::sync_with_stdio(false);` 解除与 c 风格输入输出同步
- `cin.tie(NULL);` 解除 `cin` 与 `cout` 同步




## 类与对象

### [引用](./1-2.c_cpp_cite.cpp)

> 引用：即为元素的别名。

C 语言
```C
int a = 5;
int *b = &a;
*b = 6;
printf("%d\n", a); // 输出 6
```

C++ 语言
```cpp
int a = 5;
int &b = a; // &b 引用类型
b = 6;
cout << a << endl; // 输出 6
```


### [函数重载](./1-3.fun_overload.cpp)

> 函数重载即为同名函数，根据 **参数类型** 与 **参数数量** 区分。此处注意默认参数

C 语言
```C
// c 语言不支持重载
int add_i(int a,int b);
float add_f(float a,float b);
```
C++语言
```cpp
int add(int a,int b);
float add(float a,float b);
```

### [命名空间](./1-4.namespace.cpp)

> 可以简单理解为作用域

C 语言
```C
int a;
int main(){
  a = 7;
  int a;
  if(true){
    int a;
    a = 5;
  }
  a = 6;
  printf("%d", a);
}
```

C++ 语言
```cpp
int a;
namespace my{
  int a;
}
int main(){
  int a;
  a = 5;
  ::a = 6;
  my::a = 7;
  cout << a <<endl; // 默认作用域的 a
  cout << ::a <<endl; // ::a 全局区的 a
  cout << my::a <<endl; // my 命名空间下的 a
}
```

### [sort （排序）](./1-5.sort_fun.cpp)

头文件 `<algorithm>`

参数描述：sort(排序起始位，排序结束位的后一位，排序方法)

```cpp
int mun[105];
sort(num, num + 100) // 从下标 0 排序到下标 99
```

### 类与对象
- 类： 可以简单的理解为带有方法的结构体
- 对象：可以简单的理解为结构体“变量”

C 语言
```C
// 结构体
struct node {
  int x,y;
}
```

C++ 语言
```cpp
// 类
class node {
  public:
    int x,y;
    void func();
}
```

- [class 访问权限](./1-7.class_access_auth.cpp)

`public`: 公共权限--类内可访问，类外可访问  
`private`: 私有权限--类内可访问，类外不可访问  
`protected`: 受保护的权限--类内不可访问，但可被派生类访问  
`friend`: 友元--类外可以访问 `private` 权限  

`class` 内默认权限是 `private`, `struct` 内默认权限是 `public`

### [构造与析构](./1-9.class_copy.cpp)

- [构造函数](./1-8.constructor.cpp)：默认构造函数、有参构造函数、拷贝构造函数……
- [析构函数](./1-8.constructor.cpp)：析构函数

构造函数：可理解为高级 `alloc`，用来初始化对象
析构函数：可理解为高阶 `free`，用来销毁对象

浅拷贝(默认)会影响原来的值，深拷贝不会影响原有的值。

|C 语言|C++ 语言
|-|-
|`malloc` 开辟空间 | `new` 开辟空间+构造函数
|`free` 释放空间 | `delete` 析构函数+释放空间

### [运算符重载](./1-10.operator_overload.cpp)

重写有对象参与的某个运算符的运算规则。

运算符重载：只针对自定义类型。不同类型，不同重载。
`a+b` : 看似执行运算，实则执行函数。

### 字符串

|C 语言|C++ 语言
|-|-
|`string.h` `cstring` | `string`
|`strlen(s)` \0 | `s.size()` `s.length()` 获取长度
| | `s.empty()` 是否为空
| | `s.clear()` 清空字符串
| | `s.insert(ind,"hello")` 在下标 ind 插入 hello
| | `s.substr(ind,length)` 截取
| | `s.find("hello",ind)` 查找
| | `s.replace(ind,length,"hello")` 替换
| | `=` `[]` `<` `>` …… c++中重载了运算符

- [练习题：实现 `my_string` 类]()

1. 必须用到 `public/private`
2. 构造函数（有参，无参，拷贝）
3. 运算符重载（`< > == >= <= != + += [] ()`）
4. 使用 `cin/cout` 输入输出




## STL 容器的使用

STL：标准模板库

1. 容器
2. 适配器
3. 算法
4. 迭代器
5. [仿函数](./2-5.priority_queue.cpp)
6. 分配器

### 容器

#### 有序容器

- [`vector` 向量（动态数组）](./2-1.vector.cpp)
> 向量是一个容器  https://zh.cppreference.com/w/cpp/container/vector

```cpp
#include <vector>

vector<int> v; // vector 类，<int> 模板参数， v 对象

// 向量的操作
v.size();       // 返回元素数量
v.push_back(x); // 向动态数组末尾加入 x 元素
v.pop_back(); // 将最后一个元素移除
v[i];         // 访问下标为 i 的元素
v.empty();    // 判断是否为空
v.resize(x);  // 将容器调整为 x
```

- [`stack` 栈](./2-2.stack.cpp)
> 栈实际上是一个适配器(适配器是容器的二次封装)，底层是个双端队列的二次封装

```cpp
#include <stack>

stack<int> s; // stack 类，<int> 模板参数， s 对象

// 栈的操作
s.size();   // 返回元素数量
s.push(x);  // 向栈顶加入元素 x
s.pop();    // 删除栈顶元素
s.top();    // 获得栈顶元素
s.empty();  // 栈是否为空
```

- [`queue` 队列](./2-3.queue.cpp)
> 队列实际上是一个适配器(适配器是容器的二次封装)，底层是个双端队列的二次封装

```cpp
#include <queue>

queue<int> q; // queue 类，<int> 模板参数， q 对象

// 队列的操作
q.size();  // 返回元素数量
q.push(x); // 向队尾加入元素 x
q.pop();   // 弹出队首元素
q.fornt(); // 访问队首元素
q.back();  // 访问队尾元素
q.empty(); // 队列是否为空
```

- [`deque` 双端队列](./2-4.deque.cpp)
https://zh.cppreference.com/w/cpp/container/deque
> 双端队列内部是非线性的

```cpp
#include <deque>

deque<int> d; // deque 类，<int> 模板参数， d 对象

// 双端队列的操作
d.size();  // 返回元素数量
d.push_front(x); // 向队首加入元素 x
d.push_back(x); // 向队尾加入元素 x
d.pop_front(); // 弹出队首元素
d.pop_back(); // 弹出队尾元素
d.fornt(); // 访问队首元素
d.back();  // 访问队尾元素
d.empty(); // 队列是否为空
```

- [`priority_deque` 优先队列](./2-5.priority_deque.cpp)
> 优先队列也就是堆，用数组模拟的完全二叉树。

```cpp
#include <deque>

priority_deque<int> d; // priority_deque 类，<int> 模板参数， d 对象

// 优先队列的操作（默认是大顶堆）
d.size();  // 返回元素数量 O(1)
d.push(x); // 向堆加入元素 x, O(logN)
d.pop(); // 弹出堆顶元素 O(logN)
d.top();  // 获得堆顶元素 O(1)
d.empty(); // 堆是否为空 O(1)
```


- [`set` 有序集合](./2-7.set.cpp)
> 有序集合的作用有：排序，去重。经常用于判断某个元素是否在集合中，或者不在集合中。

multiset: 多重有序集合

```cpp
#include <set>

set<int> s; // set 类，<int> 模板参数， s 对象

// 有序集合的操作
s.size();  // 返回元素数量  O(1)
s.insert(x); // 向集合插入元素 x  O(logN)
s.erase(); // 清除元素  O(logN)
s.find(x);  // 查找元素，返回一个迭代器  O(logN)
s.count(x);  // 统计 x 的出现次数  O(1)
s.empty(); // 堆是否为空  O(1)
```

- [`map` 有序映射](./2-8.map.cpp)
> 有序映射的主要作用有：排序、去重和映射。对于 `map` 而言，`key` 是唯一的，`value` 可以重复。

> `pair` 是对，也就是一对 `{key,value}`, `pair` 的 `frist` 对应 `key` , `second` 对应 `value`

multimap: 多重有序映射

```cpp
#include <map>

map<int,int> m; // map 类，<int,int> 模板参数<key,value>， m 对象

// 映射的操作
m.size();  // 返回元素数量  O(1)
m.insert({x,y}); // 插入一组映射关系{key,value}  O(logN)
m[x] = y; // 修改和插入  O(logN)
m.erase(x); // 清除 key 为 x 的元素  O(logN)
m.count(x);  // 统计 key 为 x 的元素出现次数  O(1)
m.empty(); // 是否为空  O(1)
```

#### 无序容器
> c++11（含）后才有无序容器

- [`unordered_set` 无序集合](./2-9.unordered_set.cpp)
> 无序集合内部是通过 hash 表实现的。
模板参数：`unordered_set<key,hash,== >`   

unordered_multiset: 多重无序集合

```cpp
#include <unordered_set>

unordered_set<int> us; // unordered_set 类，<int> 模板参数， us 对象

// 无序集合的操作
s.size();     // 返回元素数量  O(1)
s.insert(x);  // 向集合插入元素 x  O(1)
s.erase();    // 清除元素  O(1)
s.find(x);    // 查找元素，返回一个迭代器  O(1)
s.count(x);   // 统计 x 的出现次数  O(1)
s.empty();    // 堆是否为空  O(1)
```

- [`unordered_map` 无序映射](./2-10.unordered_map.cpp)
> 无序映射内部是通过 hash 表实现的。
模板参数：`unordered_map<key,value,hash,== >`  

unordered_multimap: 多重无序映射

```cpp
#include <unordered_map>

unordered_map<key,value> um; // unordered_map 类，<key,value> 模板参数， um 对象

// 无序映射的操作
um.size();     // 返回元素数量  O(1)
um.insert(x);  // 向集合插入元素 x  O(1)
um[x] = y;     // 修改和插入
um.erase();    // 清除元素  O(1)
um.count(x);   // 统计 x 的出现次数  O(1)
um.empty();    // 堆是否为空  O(1)
```
