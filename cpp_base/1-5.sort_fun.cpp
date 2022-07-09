/**
 * @file 1-5.sort_fun.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 排序函数
 * @version 0.1
 * @date 2022-07-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// bool cmp(int a, int b); right
// bool cmp(int &a; int &b); worng
bool cmp(const int &a, const int &b) {
  return a > b;
}

int main() {
  // 数字排序
  int n, num[105];
  cin >> n;
  for (int i = 0;i < n;i++) {
    cin >> num[i];
  }

  sort(num, num + n, cmp); // O(nlogN) , 第三个参数非必传

  for (int i = 0;i < n;i++) {
    cout << num[i] << " ";
  }
  cout << endl;

  // 字符排序
  char str[105];
  cin >> str;
  sort(str, str + strlen(str)); // O(nlogN)
  cout << str << endl;

  return 0;
}