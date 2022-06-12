# c 语言基础

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

`EOF`: 文件末尾，同： `-1`

- [`scanf`](2-1.scanf.c) 从标准输入中取数据
- [`sscanf`](2-2.sscanf.c) 从**字符数组中**取数据，一般用于字符串的剪裁
- [`fscanf`](2-3.fscanf.c) 从**文件中**取数据