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

### 输入输出对比

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

### 引用
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


### 函数重载
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

### 命名空间
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

### sort （排序）

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

- class 访问权限

`public`: 公共权限--类内可访问，类外可访问
`private`: 私有权限--类内可访问，类外不可访问
`protected`: 受保护的权限--类内不可访问，但可被派生类访问
`friend`: 友元--类外可以访问 `private` 权限

`class` 内默认权限是 `private`, `struct` 内默认权限是 `public`

