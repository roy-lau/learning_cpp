/**
 * @file 2-1.vector.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 向量的使用
 * @version 0.1
 * @date 2022-07-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node {
  int x, y;
};

void output(vector<int> v) {
  for (int i = 0;i < v.size();++i) {
    cout << v[i] << " ";
  }
  cout << endl;

}

void output(vector<string> v) {
  for (int i = 0;i < v.size();++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}

void output(vector<node> v) {
  for (int i = 0;i < v.size();++i) {
    cout << v[i].x << " " << v[i].y << " ";
  }
  cout << endl;
}

int main() {
  // 定义模板类型 int 的向量 v
  cout << "int向量类型:" << endl;
  vector<int> v;

  cout << "增:" << "\t";
  v.push_back(10);
  v.push_back(9);
  v.push_back(8);
  output(v);

  cout << "删:" << "\t";
  v.pop_back();
  output(v);

  cout << "改:" << "\t";
  v[1] = 99;
  output(v);
  cout << endl;

  // 定义模板类型 string 的向量 vs
  cout << "string向量类型:" << endl;
  vector<string> vs;
  vs.push_back("你");
  vs.push_back("是");
  vs.push_back("谁");
  vs.push_back("?");
  output(vs);
  cout << endl;

  // 定义模板类型 node 的向量 vn
  cout << "自定义向量类型:" << endl;
  vector<node> vn;
  node t;
  t.x = 5;
  t.y = 6;
  vn.push_back(t);
  vn.push_back((node) { 7, 8 });
  vn.push_back((node) { 9, 10 });
  output(vn);
  cout << endl;

  cout << "初始化向量时，定义向量长度:" << endl;
  vector<int> vinit(10);
  vinit[8] = 80; // 如果初始化向量时不定义长度，无法访问到下标 8
  cout << vinit[8] << endl;

  cout << "初始化向量并填充值:" << endl;
  vector<int> vfull(10, 9);
  output(vfull);
  cout << endl;


  // 二维向量初始化
  cout << "二维向量:" << endl;
  vector<vector<int> > vv;
  vv.push_back(vector<int>(5, 5));
  vv.push_back(vector<int>(4, 4));
  vv.push_back(vector<int>(6, 6));
  vv[1].push_back(8888);
  for (int i = 0;i < vv.size();++i) {
    for (int j = 0; j < vv[i].size();++j) {
      cout << vv[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;


  vector<vector<int> > v2(5, vector<int>(6, -3));
  for (int i = 0; i < v2.size(); ++i) {
    for (int j = 0; j < v2[i].size();++j) {
      cout << v2[i][j] << " ";
    }
    cout << endl;
  }

  cout << "列表初始化:" << endl;
  vector<int> vlist = {1,2,3,4,5,6,7,8,9};
  output(vlist);

  // 下面两种访问方式是 C++11 才有的,编译时需要加 -std=c++11

  cout << "正向迭代器访问:" << endl;
  for (auto it = vlist.begin(); it != vlist.end(); it++) { // auto 自定推断类型
    cout << *it << " "; // it 是指针
  }
  cout << endl;
  
  // cout << "反向迭代器访问:" << endl;
  // for (auto it1 = vlist.rbegin(); it1 != vlist.rend(); it1--) { // auto 自定推断类型
  //   cout << *it1 << " ";
  // }
  // cout << endl;

  cout << "列表访问:" << endl;
  for (auto &x : vlist) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}