#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
int main(){
  int* arr=(int*)malloc(sizeof(int));
  assert(arr!=nullptr);
  free(arr);
  arr=nullptr;
  assert(arr==nullptr);
  int* new_arr=new int(10);
  assert(new_arr!=nullptr);
  for(int i=0;i<20;++i){
    cout<<new_arr[i]<<' ';
  }
  return 0;
}