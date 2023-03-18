#include <bits/stdc++.h>
int main(){
  std::shared_ptr<int>p(new int(3));//cannot use a stack shit to do it
  std::cout<<p.get()<<'\n';
  *p=2;
  std::cout<<p.get()<<'\n';
  std::shared_ptr<int>p1=std::make_shared<int>(3);
  std::cout<<p1.get()<<'\n';
  p1=std::move(p);
  std::cout<<p.get()<<'\n';
  std::cout<<p1.get()<<'\n';
  int* test_multy=new int;
  std::shared_ptr<int>test_p1(test_multy);
  //std::shared_ptr<int>test_p2(test_multy);//could not assign twice
  std::shared_ptr<int>test_p2(test_p1);
  std::cout<<p1.use_count()<<'\n';
  std::cout<<test_p1.use_count()<<'\n';
  return 0;
}