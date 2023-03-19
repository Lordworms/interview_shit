#include <bits/stdc++.h>
using namespace std;
class Dad{
    virtual void print(){
        cout<<"I am a dad\n";
    }
};
class Son:public Dad{
    void print()override{
        cout<<"I am a son\n";
    }
};
class Daughter:public Dad{
    void print()override{
        cout<<"I am a Daughter!\n";
    }
};
int main(){
  Son son1;
  Dad* d=dynamic_cast<Dad*>(&son1);
  assert(d!=nullptr);
  Daughter* dau=dynamic_cast<Daughter*>(d);
  assert(dau==nullptr);
  try{
    Daughter& dd=dynamic_cast<Daughter&>(son1);
  }catch(std::exception& e){
    std::cout<<e.what()<<"wrong!"<<'\n';
  }
  return 0;
}