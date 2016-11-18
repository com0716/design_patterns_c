#include <iostream>
#include <string>
using namespace std;

//single
//单例设计模式，保证类的对象实例只能存在一个
//实现步骤有三：
//1 创建一个私有的实例对象
//2 屏蔽相关默认构造函数
//3 提供一个可以获取对象实例的函数

class SingleDemo {
public:
	static SingleDemo& getInstance(){
		return *pSingleDemo;
	}
	
	void setName(string n) {name=n;}
	string getName() const {return name;}

private:
	SingleDemo(){}
	SingleDemo(const SingleDemo &){}
	
	static SingleDemo *pSingleDemo;

	string name;
};

SingleDemo* SingleDemo::pSingleDemo = new SingleDemo();

int main(int argc, char *argv[])
{
	SingleDemo &instance = SingleDemo::getInstance();
	instance.setName("bjtu");

	SingleDemo &demo = SingleDemo::getInstance();
	cout<<demo.getName()<<endl;

	return 0;
}
