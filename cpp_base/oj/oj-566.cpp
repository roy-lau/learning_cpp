/**
 * @file oj-566.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 上网记录
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  int n, m, cnt = 0;
  cin >> n >> m;
  vector<vector<string> > ans(n, vector<string>{}); // 保存记录
  unordered_map<string, int>ma; // 用户名和记录下标的映射
  for (int i = 0; i < m; i++) {
    string a, b;
    cin >> a >> b;
    if (ma.count(a)) { // 如果用户已经存在
      ans[ma[a]].push_back(b);
    } else { // 如果用户不存在
      ma[a] = cnt;
      cnt++; // 当前用户数
      ans[ma[a]].push_back(a);
      ans[ma[a]].push_back(b);
    }
  }

  cout << endl;
  for (int i = 0; i < cnt;i++) {
    cout << ans[i][0];
    for (int j = 1;j < ans[i].size();j++) {
      cout << " " << ans[i][j];
    }
    cout << endl;
  }

  return 0;
}