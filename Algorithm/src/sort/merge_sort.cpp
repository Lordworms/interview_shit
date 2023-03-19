#include <bits/stdc++.h>
using namespace std;
template<typename T>
void merge(vector<T>&arr,vector<T>&tmp,int left,int right){
    if(left>=right)return;
    int mid=(left+right)>>1;
    merge(arr,tmp,left,mid);
    merge(arr,tmp,mid+1,right);
    int k=left;
    int l1=left,l2=mid+1;
    while(l1<=mid&&l2<=right){
        tmp[k++]=arr[l1]>arr[l2]?arr[l1++]:arr[l2++];
    }
    while(l1<=mid){
        tmp[k++]=arr[l1++];
    }
    while(l2<=right){
        tmp[k++]=arr[l2++];
    }
    for(int i=left;i<=right;++i){
        arr[i]=tmp[i];
    }
}
template<typename T>
void merge_sort(vector<T>&arr){
    if(arr.size()>1){
        vector<int>tmp(arr.size());
        merge(arr,tmp,0,arr.size()-1);
    }
}
int main(){
  vector<int>a;
  for(int i=10;i>=1;--i)a.push_back(i);
  merge_sort<int>(a);
  for(auto& c:a){
    cout<<c<<' ';
  }
  cout<<'\n';
  return 0;
}