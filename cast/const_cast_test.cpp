#include <bits/stdc++.h>
using namespace std;
void transfer(int* x){
    cout<<"1\n";
}
int main(){
  const int a=1;
  const int* b=&a;
  int* c=const_cast<int*>(b);// now removed the const
  *c=2;//invalid and undefine behavior, should not use!
  cout<<a<<'\n';//would not change,since compiler would directly write the constant value for print

  int aa=1;
  const int* bb=&aa;
  int* cc=const_cast<int*>(bb);
  *cc=3;
  cout<<aa<<'\n';

  const int v=1;
  const int* pv=&v;

  transfer(const_cast<int*>(pv));//ok
  //transfer(pv);//panic!
  return 0;
}