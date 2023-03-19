#include <bits/stdc++.h>
using namespace std;
void base_sort(vector<int>&arr){
    auto get_bits=[&](){
        auto maxx=*max_element(arr.begin(),arr.end());
        int bits=0;
        while(maxx){
          maxx/=10;
          ++bits;
        }      
        return bits;
    };
    int d=get_bits();
    vector<int>tmp(arr.size());
    vector<int>cnt(10);
    int base=1;
    for(int i=0;i<d;++i){
      fill(cnt.begin(),cnt.end(),0);
      for(int j=0;j<arr.size();++j){
        cnt[((arr[j])/base)%10]++;
      }
      for(int i=1;i<10;++i){
        cnt[i]+=cnt[i-1];
      }
      for(int i=0;i<arr.size();++i){
        int index=((arr[i])/base)%10;
        tmp[cnt[index]-1]=arr[i];
        cnt[index]--;
      }
      base*=10;
    }
    arr=std::move(tmp);
}
int main(){
  vector<int>a;
  for(int i=10;i>=1;--i)a.push_back(i);
  base_sort(a);
  for(auto& c:a){
    cout<<c<<' ';
  }
  cout<<'\n';
  return 0;
}