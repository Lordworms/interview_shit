#include <bits/stdc++.h>
using namespace std;
class RE{
    private:
        int k;
    public:
        RE(int h):k(h){}
        void print(){
            cout<<k<<'\n';
        }
        RE operator+(const RE& a){
            this->k=a.k;
            return *this;
        }
        void operator-(const RE& a){
            cout<<"caonima\n";
        }
};
int main(){
  RE* a=new RE(10);
  RE* b=new RE(7);
  *b=*b+*a;
  b->print();
  *b-*a;
  return 0;
}