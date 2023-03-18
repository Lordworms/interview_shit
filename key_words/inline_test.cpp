#include <bits/stdc++.h>
using namespace std;
class INLINE_TEST{
    public:
    inline virtual void print()=0;
    void a_test_test(){
        int x;
    }
    void b_test_test(){
        int k;
    }
};
class INLINE_TEST_SON:public INLINE_TEST{
    public:
    inline void print()override{
        cout<<"I am a fucking son"<<'\n';
    }
};
class INLINE_TEST_SON_1:public INLINE_TEST{
    public:
        inline void print()override{
            cout<<"I am a fucking son 1"<<'\n';
        }
};
inline void print_switch(){
   int x=1;
   switch (x)
   {
   case 1:
    cout<<x<<'\n';
    break;
   default:
    break;
   }
}
inline void print_recursive(int x){
    cout<<x<<'\n';
    if(x==0)return;
    print_recursive(x-1);
}
// int main()
// {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   print_switch();
//   print_recursive(3);
// //not allowed!
// //   auto* a=new INLINE_TEST;
// //   a->print();
//   return 0;
// }