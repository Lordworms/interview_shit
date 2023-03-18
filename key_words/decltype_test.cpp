#include <bits/stdc++.h>
using namespace std;
using size_t=decltype(sizeof(0));
template<typename TX,typename TY>
auto multy(TX x,TY y)->TX{
    return x*y;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a;
  decltype(a) b;
  b=1;
  cout<<b<<'\n';
  auto cmp=[&](int a,int b){
    return a>b;
  };
  priority_queue<int,vector<int>,decltype(cmp)>q(cmp);//let others to deduce the answer
  q.push(1);
  q.push(2);
  while(!q.empty()){
    cout<<q.top()<<' ';
    q.pop();
  }
  return 0;
}