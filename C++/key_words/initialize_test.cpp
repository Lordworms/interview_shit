#include <bits/stdc++.h>
#include <initializer_list>
using namespace std;
template<typename T>
struct S{
    vector<T>v;
    S(std::initializer_list<T> l):v(l){
        cout<<"initialized "<<l.size()<<" elements\n";
    }
    void append(initializer_list<T> app){
        v.insert(app.begin(),app.end(),v.end());
    }
    pair<const T*,size_t>size(){
        return {&v[0],v.size()};
    }
};
template<typename T>
void test(T){}
int main(){
  auto li={1,3,2};//if use auto, it becomes an initializer_list
  S<int> vec={1,3,2};//could not use if S is explicit
  S<int>s=li;
  cout<<s.size().second<<'\n';
  test<initializer_list<int>>(li);
  return 0;
}