/**
 * @file oj-576.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 最大收益
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 * @input
3 5
apple 1 100
pear 5 90
football 30 10
pear 24
apple 18
football 4
pear 1
football 6
 * @output
    443
 */
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct node {
  int m, cnt;
};

int main() {
  int n, k;
  cin >> n >> k;
  unordered_map<string, node> m;
  for (int i = 0; i < n;i++) {
    string name;
    int s, c;
    cin >> name >> s >> c;
    m[name] = (node){ s,c };
  }

  long long ans=0;
  for (int i = 1; i <= k;i++) {
    string f_name;
    int p;
    cin >> f_name >> p;
    if (m[f_name].cnt < p) {
      cout << "-" << i << endl;
      return 0;
    }
    m[f_name].cnt = m[f_name].cnt - p;
    ans += p * m[f_name].m;
  }
  cout << ans << endl;

  return 0;
}