#include <bits/stdc++.h>
using namespace std;
class CONST_TEST{
    public:
        CONST_TEST(){
            a=-1;
        }
        void modify(){
            a=0;
        }
    private:
        int a;
};
void change_shit(int& a){
    a=-1;
}