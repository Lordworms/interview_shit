#include <bits/stdc++.h>
using namespace std;
class friend_B{
    friend_A a;
    public:
        void modify(){
            a.wallet++;//could access
        }
};
class friend_A{
    friend class friend_B;
    private:
        int wallet;
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}