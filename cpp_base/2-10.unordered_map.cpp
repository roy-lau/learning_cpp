/**
 * @file 2-10.unordered_map.cpp
 * @author RoyLau (897379293@qq.com)
 * @brief 无序映射的使用
 * @version 0.1
 * @date 2022-07-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
  unordered_map<int,string> um;
  um[99] = ">_<";
  um[66] = "@_@";
  um[88] = "-_-";
  um[77] = "^_^";
  um[55] = "$_$";
  cout << "key = 99 value = " << um[99] << endl;
  cout << "size : " << um.size() << endl << endl;

  um.erase(99);
  cout << (um.count(99) ? "key = 99 exist!" : "key = 99 no exist!") << endl;
  cout << "size : " << um.size() << endl << endl;
  for(auto &x : um) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;

}