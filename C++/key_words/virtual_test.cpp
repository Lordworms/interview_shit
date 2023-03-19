#include <bits/stdc++.h>
using namespace std;
class dad{
    public:
        virtual ~dad(){
            cout<<"delete dad\n";
        }
        virtual void say(){
            cout<<"I am dad\n";
        }
        virtual void play()=0;//pure virtual
};
class son:public dad{
    public:
        void say()override{
            cout<<"I am son"<<'\n';
        }
        virtual ~son()override{
            cout<<"delete son\n";
        }
        void play()override{
            cout<<"son is playing\n";
        }
};
class daughter:public dad{
    public:
        void say()override{
            cout<<"I am daughter"<<'\n';
        }
        virtual ~daughter()override{
            cout<<"delete daughter\n";
        }
        void play()override{
            cout<<"daughter is playing\n";
        }
};  
int main(){
  dad* s=new son;
  dad* d=new daughter;
  s->play();
  delete s;//call son's first then call dad's
  d->play();
  delete d;
  return 0;
}