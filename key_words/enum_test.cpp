#include <bits/stdc++.h>
using namespace std;
enum class people{woman,man,kids};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a=5;
  int& ref_a=a;
  // int& ref_b=5; panic! since we cannot assign a constant to a non-lvalue

  return 0;
}