#include <bits/stdc++.h>
using namespace std;
template<typename T>
union bits{
    T value;
    bitset<sizeof(T)*8>bit;
    bits(T v):value(v){}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  bits<int>test(4);
  cout<<test.bit<<'\n';
  bits<double>double_test(3.5);
  cout<<double_test.bit<<'\n';//IEEE shit
  return 0;
}