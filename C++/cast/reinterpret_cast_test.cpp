#include <bits/stdc++.h>
using namespace std;
class Man{
    public:
    void say_man(){
        cout<<"I am a man\n";
    }
};
class Woman{
    public:
    void say_woman(){
        cout<<"I am a woman\n";
    }
};
struct node{
    int x,y;
    char c;
    bool b;
};
int main(){
  Man* m=new Man;
  Woman* w=new Woman;

  m->say_man();
  Man* new_man=reinterpret_cast<Man*>(w);//should not use it!
  new_man->say_man();

  //when you should use re_interpret_cast
  node s;
  s.y=1;s.c='a';s.x=2;s.b=false;
  int* p=reinterpret_cast<int*>(&s);
  cout<<*p<<'\n';
  ++p;
  cout<<*p<<'\n';
  ++p;
  cout<<*(reinterpret_cast<char*>(p))<<'\n';
  return 0;
}