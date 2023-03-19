#include <iostream>
using namespace std;
class EXP_TEST{
	public:
	EXP_TEST(int x){
		cout<<"used"<<endl;
	}
};
class Str{
	public:
	explicit Str(int x){
		cout<<"我是想把整数变字符串"<<endl;
	}
	Str(const char* a)
	{
		cout<<"我是想把字符数组变字符串"<<endl;
	}

};
static void test(EXP_TEST a){
}
int main(){
    test(1);
    //Str s='a';
	return 0;
}
