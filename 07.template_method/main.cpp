#include <iostream>
#include <string>
using namespace std;

//template method
//模版方法模式是一个很简单的模式，一般说23种设计模式的时候
//，就不包含这个模式。

class Animal {
public:
	virtual ~Animal(){}
	virtual void display() = 0;

	void sound() {
		cout<<"begin"<<endl;
		display();
		cout<<"end"<<endl;
	}
};

class Cat : public Animal {
public:
	void display(){cout<<"Cat miaomiao"<<endl;}
};

class Dog : public Animal {
public:
	void display(){cout<<"Dog wangwang"<<endl;}
};

int main(int argc, char *argv[])
{
	Animal *pa = new Dog();
	//Animal *pa = new Cat();

	pa->sound();

	delete pa;
	return 0;
}
//这个模式通过留出一个钩子函数的方式，将算法的一部分内容留
//给派生类自行完成，实现算法实现的延迟
