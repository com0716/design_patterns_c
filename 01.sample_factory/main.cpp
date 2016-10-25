#include <iostream>
#include <string>
using namespace std;

//sample factory
//简单工程模式，这是一个很简单的设计模式。但是在刚开始入门的时
//候这个模式还是比较抽象的。即使是简单的设计模式，也涉及到多态
//和抽象类。
//

class Animal {
public:
	virtual ~Animal(){}
	virtual void display()=0;
};

class Cat : public Animal {
public:
	virtual void display()
	{
		cout<<"Cat miaomiao"<<endl;
	}
};

class Dog : public Animal {
public:
	virtual void display()
	{
		cout<<"Dog wangwang"<<endl;
	}
};

class SampleFactory {
public:
	Animal *creatAnimal(string type)
	{
		if ("Cat" == type)
			return new Cat();
		else if ("Dog" == type)
			return new Dog();
		else
			return NULL;
	}
};

int main(int argc, char *argv[])
{
	SampleFactory sfactory;

	if (argc < 2) {
		cout<<"error:argc < 2"<<endl;
		return -1;
	}

	Animal *pa = sfactory.creatAnimal(string(argv[1]));
	if (pa) {
		pa->display();
	}

	return 0;
}

//设计模式的主要思想是解耦合，如果在不增加新类的情况下，不同类
//的变化只需要改变传入工厂类的字符串，不需要修改其他操作。但是
//在增加新类的时候，需要修改工程类，也要修改调用时传入的字符串
//，这一点违背了开发--封闭原则（不可修改，可扩展，这一原则也是
//为了解耦合）。
