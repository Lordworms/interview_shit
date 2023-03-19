#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <memory>
class A;
class B{
   public:
   ~B() {
     std::cout << "B destory, a_ptr use_count:" << a_ptr.use_count() << "\n";
   }
   
   std::shared_ptr<A> a_ptr;
 };
 
class A{
public:
    ~A() {
        std::cout << "A destory, b_ptr use_count:" << b_ptr.use_count() << "\n";
    }
      
    std::shared_ptr<B> b_ptr;
};
int main(){
  shared_ptr<int>p1(new int(3));
  shared_ptr<int>p2(p1);
  weak_ptr<int>pp1(p1);
  cout<<pp1.use_count()<<'\n';
  p2.reset();
  cout<<pp1.use_count()<<'\n';
  cout<<*pp1.lock()<<'\n';
  p1.reset();
  cout<<pp1.use_count()<<'\n';
  cout<<pp1.expired()<<'\n';

  std::shared_ptr<A> a(new A());
  std::shared_ptr<B> b(new B());
  a->b_ptr=b;
  b->a_ptr=a;

  std::cout << "A:" << a.use_count() << "\n";
  std::cout << "B:" << b.use_count() << "\n";
  return 0;
}