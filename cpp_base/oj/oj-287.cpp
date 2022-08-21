/**
 * @file oj-287.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 合并果子
 * @version 0.1
 * @date 2022-08-21
 * 
 * @copyright Copyright (c) 2022
 * 
 * @input
3 
1 2 9 
 */
#include <iostream>
#include <queue>
using namespace std;


int main(){
  int n ;
  cin >> n;
  priority_queue<int, vector<int>, greater<int> > que; // 小顶堆
  for(int i = 0;i<n;i++){
    int fruit;
    cin >> fruit;
    que.push(fruit);
  }
  int ans = 0;
  while(que.size() != 1){
    int a = que.top();
    que.pop();
    int b = que.top();
    que.pop();
    ans += a+b; // 每次拿两个最小的进行合并
    que.push(a+b);
  }
  cout << ans << endl;
  return 0;
}