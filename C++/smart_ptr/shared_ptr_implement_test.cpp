#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
class Counter{
    private:
        uint64_t cnt=0;
    public:
        Counter():cnt(0){}
        Counter(const Counter& c)=delete;
        Counter& operator=(const Counter& c)=delete;
        ~Counter(){}
        void reset(){
            this->cnt=0;
        }
        uint64_t get(){
            return this->cnt;
        }
        void operator++(){
            this->cnt++;
        }
        void operator++(int){
            this->cnt++;
        }
        void operator--(){
            this->cnt--;
        }
        void operator--(int){
            this->cnt--;
        }
        friend ofstream& operator<<(ofstream& out,const Counter& c){
            out<<c.cnt<<'\n';
            return out;
        }
};
template<typename T>
class Shared_ptr{
    private:
        Counter* counter;
        T* ptr;
    public:
        explicit Shared_ptr(T* ptr=nullptr){
            this->counter=new Counter();
            this->ptr=ptr;
            (*this->counter)++;
        }
        Shared_ptr(Shared_ptr<T>& sp){
            this->counter=sp.counter;
            this->ptr=sp.ptr;
            (*this->counter)++;
        }
        T* get(){
            return this->ptr;
        }
        uint64_t get_cnt(){
            return this->counter->get();
        }
        T& operator*(){
            return *this->ptr;
        }
        T* operator->(){
            return this->ptr;
        }
        ~Shared_ptr(){
            (*counter)--;
            if(this->counter->get()==0){
                delete counter;
                delete this->ptr;
            }
        }
        friend ostream& operator<<(ostream& out,Shared_ptr<T>&ptr){//watch out for the &,if not then call Shared_ptr(Shared_ptr<T>& sp)
            out<<"address is"<<ptr.get()<<'\n';
            out<<"counter is"<<ptr.get_cnt()<<'\n';
            return out;
        }
};
int main(){
  auto a=new int(3);
  assert(a!=nullptr);
  Shared_ptr<int> ptr1(a);
  std::cout<<ptr1<<'\n';
  Shared_ptr<int>ptr2(ptr1);
  std::cout<<ptr2<<'\n';
  {
  std::cout<<ptr1<<"\n";
  }
  return 0;
}