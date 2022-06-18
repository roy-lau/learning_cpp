# c 语言基础

[c 语言参考手册](https://zh.cppreference.com/w/c)
[c 语言29个标准库](https://wiki.jikexueyuan.com/project/c/c-standard-library.html)


## 第一课


### printf 家族函数

头文件：  `stdio.h` <br />
原型：  `int printf(const char *format, ...);` <br />
format： 格式化控制符 <br />
...： 可变参数列表 <br />
返回值： 输出字符串的数量 <br />

字符串数组最大长度为 **n-1** ，因为最后一位是 `\0`

`\0`: 标记字符的末尾


- [`printf`](1-1.printf.c) 向标准输出处
- [`sprintf`](1-2.sprintf.c) 向**字符数组中**输出,一般用于字符串的拼接
- [`fprintf`](1-3.fprintf.c) 向**文件中**输出


### scanf 函数

头文件：  `stdio.h` <br />
原型：  `int scanf(const char *format, ...);` <br />
format： 格式化控制符 <br />
...： 可变参数列表 <br />
返回值： 成功读入的参数个数（0 到 n） <br />

`EOF`: 文件末尾，同： `-1` 和 `~`


- [`scanf`](2-1.scanf.c) 从标准输入中取数据
- [`sscanf`](2-2.sscanf.c) 从**字符数组中**取数据，一般用于字符串的剪裁
- [`fscanf`](2-3.fscanf.c) 从**文件中**取数据

### string 字符串

[格式化字符串](https://zh.wikipedia.org/wiki/%E6%A0%BC%E5%BC%8F%E5%8C%96%E5%AD%97%E7%AC%A6%E4%B8%B2)

`%[]` 字符(正则)匹配集
`getchar()` 吞掉开头的换行符(\n)

### 数值

`int` 整型 32位 4 字节,区间 `-2*2^31` 到 `2*2^31-1`
`unsigned int` 无符号整型 32位 4 字节,区间 `0` 到 `2^31-1`
`float` 单精度 4 字节
`double` 双精度 8 字节


## 第二课

### 基本运算符

| | | |
|-|-|-|
|运算符|说明|例子🌰
|`=`|赋值运算符| `a=b`
|`+ - * / ()`|基本四则运算| `a=(b+c)*d`
|`%`|求余运算符|`a=b%2`
|`& | ^ ~`|位运算|`a=~b|c`
|`<< >>`|左移和右移|`a=b>>2`

原码：无法进行减法运算
反码：按位取反，例如：2-3 ---> 2+(-3)，计算不了 0
补码：补码=反码+1


### 数学函数库

- 头文件：math.h
> 常用函数

| | |
|-|-|
|常用函数|解释
|`pow(a,b)`| 指数运算
|`sqrt(n)`| 开平方
|`ceil(x)`| 上取整函数
|`floor(x)`| 下取整函数
|`abs(x)`| 整数绝对值函数
|`fabs(x)`| 实数绝对值函数
|`log(x)`| 以 e 为底对数函数
|`log10(x)`| 以 10 为底对数函数
|`acos(x)`| 角度的弧度值
|`……`| ……

#### pow 函数：指数函数

头文件: math.h <br />
原型: `double pow(double a,double b);`<br />
a: 底数 <br />
b: 指数 <br />
返回值：返回 $a^b$ 结果 <br />
例子： pow(2,3)=8 <br />


#### sqrt 函数：开平方函数

头文件: math.h <br />
原型: `double sqrt(double x);`<br />
x: 被开平方数 <br />
返回值：返回 $\sqrt{x}$ 结果 <br />
例子： sqrt(16)=4 <br />


#### ceil 函数：上取整函数

头文件: math.h <br />
原型: `double ceil(double x);` <br />
x:  某个实数 <br />
返回值：返回 $\lceil x \rceil$ 结果 <br />
例子： ceil(4.1)=5 <br />

####  floor 函数：下取整函数

头文件：math.h <br />
原型： `double floor(double x);` <br />
x: 某个实数 <br />
返回值：返回 $\lfloor x \rfloor$ 结果 <br />
例子： floor(4.9)=4 <br />


####  abs 函数：绝对值函数

头文件: stdlib.h <br />
原型: `int abs(int x);` <br />
x: 某个实数 <br />
返回值：返回 |x| 结果 <br />
例子： abs(-4)=4 <br />

#### fabs 函数：实数绝对值函数

头文件: math.h <br />
原型: `int fabs(int x);` <br />
x: 某个实数 <br />
返回值：返回 |x| 结果 <br />
例子： abs(-4.5)=4.5 <br />


#### log 函数：以 e 为底对数函数

头文件: math.h <br />
原型: `double log(double x);` <br />
x: 某个实数 <br />
返回值：返回 $ log{_e x} $ 结果 <br />
例子： log(9)=2.197225…… <br />

#### log10 函数：以 10 为底对数函数

头文件: math.h <br />
原型: `double log10(double x);` <br />
x: 某个实数 <br />
返回值：返回 $ log{10^x} $ 结果 <br />
例子： log10(1000)=3 <br />


#### acos 函数

头文件: math.h <br />
原型: `double acos(double x);` <br />
x: 角度的弧度值 <br />
返回值：返回 `arccos(x)` 结果 <br />
例子： acos(-1)=3.1415926 <br />

## 第三课

### 关系运算符

| | | |
|-|-|-|
|运算符|说明|例子🌰
|`==`|等于| `a==b`
|`!=`|不等于| `a!=b`
|`< >`|小于 大于|` a<b、b>a`
|`<=(=<)、 >=(=>)`|小于等于和大于等于|`a<=b、b>=a`
|`!`|非|`!(0) !(NULL)`

假值：`0` `NULL` `'\0'`
真值：非假即为真

`<=` 是两次判断，一次判断是否小于，一次判断是否等于。
`++i` 比 `i++` 要快一点点，因为 `i++` 的底层使用的中间变量。

### 逻辑判断

- `if else`
- `switch case`
- 三元运算符 ` is ? a : b`

`break` 结束循环
`continue` 跳过本轮循环

## 第四课

### 函数

- 素数例子

```c
int is_prime(int x){
  for(int i = 2; i <= x / 2; ++i){
    if(x % 2 == 0) {
      return 0;
    }
  }
  return 1;
}
```

`int` 返回值类型 <br />
`is_prime` 函数名(1、只能字符或数字开头 2、不能是数字开头 3、不能是关键字 4、语义化) <br />
`int x` 参数声明列表 <br />

`main()` 函数是由操作系统调用的，在操作系统层面 `0` 表示真值（就是 main 函数中 return 的那个）

- 递归
> 程序调用自身的编程技巧叫做 递归。

递归的组成部分：
1. 边界条件处理
2. 针对问题的 **处理过程** 和 **递归过程**
3. 返回结果

- 内存

系统栈：Linux 系统栈为 8MB(约为 8 百万字节)，Windows 系统栈为 4MB 左右。 <br />
`int arr[size]` size 最大不能超过 2 百万，因为 int 为 4 个字节，系统栈最大为 8 百万。  <br />
[`static`](./9-3.static.c) 关键字会延长变量的生命周期。

### 指针

- 函数指针

> 函数指针主要是用来存函数信息的（将函数当做变量传入函数中）

```c
int g(int (*f1)(int), int (*f2)(int), int (*f3)(int), int x){
  if(x < 0){
    return f1(x);
  }else if(x < 100){
    return f2(x);
  }
  return f3(x);
}
```

- [变参函数](./9-5.func_auto_parmas.c)

> 参数列表是可变的函数，叫做变参函数

## 第五课

### 数组

- 特性
> 数组是具有相同类型变量的集合。定义后直接赋值，静态数组
> 变量有 大小、地址、类型。

1. 数组开辟的空间一定是连续的。
2. 数组支持随机访问

- sizeof 关键字

> sizeof() 返回的单位是字节。 sizeof(int) 默认返回的是 4 字节，但和操作系统是 32 或 64 位有关，也和编译器是多少位有关。

