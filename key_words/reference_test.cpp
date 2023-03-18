#include <bits/stdc++.h>
using namespace std;
int main(){
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
  int a=5;
  int& ref_a=a;//left value reference point to left value, pass
  // int& ref_b=5; panic! since we cannot assign a constant to a rvalue,and since rvalue did not have an address so it panics
  const int& ref_const=5;//not panic since it allocate data on stack
  int&& ref_right=5;
  //int&& ref_right=a; panic !
  ref_right=5;
  return 0;
}