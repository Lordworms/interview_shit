#include <bits/stdc++.h>
#include<assert.h>
using namespace std;
class Int{
    private:
        int x;
    public:
        Int(int a):x(a){
            cout<<"call contructor!\n";
        }
        operator string(){
            cout<<"call operator!\n";
            return to_string(this->x);
        }
        int value(){
            return this->x;
        }
        friend ostream& operator<<(ostream& out,Int& a){
            out<<a.x<<'\n';
            return out;
        }
};
class Dad{

};
class Son:private Dad{

};
class Son_1:public Dad{

};
class Son_2:public Dad{

};
int main(){
   
  float a_f=1.1;
  int a_i=static_cast<int>(a_f);
  assert(a_i==1);
  
  Int obj(3);
  cout<<obj<<'\n';
  string obj_str=static_cast<string>(obj);
  assert(obj_str=="3");

  obj=static_cast<Int>(9);
  assert(obj.value()==9);
  
  int* b_int=new int;
  char* b_char=new char;
  //b_int=(int*)(b_char);//could pass,but wrong in runing
  
  // b_int=static_cast<int*>(b_char);//fail since static_cast would check!

  Son s;
  //Dad* d=(Dad*)&s;//could pass wrong in runing since it is private inherient

  //Dad* d=static_cast<Dad*>(&s);//could not pass unless it is public

  Son_1 s1;
  Son_2 s2;
  Dad* d1=static_cast<Dad*>(&s1);
  Dad* d2=static_cast<Dad*>(&s2);
  
  Son_2* s22=static_cast<Son_2*>(d1);//should never use static_cast!
  Son_1* s11=static_cast<Son_1*>(d2);
  
  int i=10;
  void* ptr=static_cast<void*>(&i);//always use static_cast
  int* new_i=static_cast<int*>(ptr);
  return 0;
}