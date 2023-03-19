#include <bits/stdc++.h>
using namespace std;
template<typename T>
void qsort_range(vector<T>&arr,int left,int right){
    if(left>=right)return;
    int pivot=left;
    int l=left+1,r=right;
    while(l<r){
        while(l<r&&arr[l]<arr[pivot]){
            ++l;
        }
        while(l<r&&arr[r]>=arr[pivot]){
            --r;
        }
        swap(arr[l],arr[r]);
    }
    if(arr[l]<arr[pivot]){
        swap(arr[l],arr[pivot]);
    }
    else{
        --l;//should decrease since a[l] is ordered
    }
    int mid=(left+right)>>1;
    qsort_range(arr,left,l-1);
    qsort_range(arr,l+1,right);
}
template<typename T>
void qsort(vector<T>& arr){
    int left=0,right=arr.size()-1;
    if(left<right){
        qsort_range(arr,left,right);
    }
}
int main(){
  vector<int>a;
  for(int i=10;i>=1;--i)a.push_back(i);
  qsort<int>(a);
  for(auto& c:a){
    cout<<c<<' ';
  }
  cout<<'\n';
  return 0;
}