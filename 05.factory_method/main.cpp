#include <iostream>
#include <string>
using namespace std;

//factory_method
//工厂方法模式，实现的是对同系列产品的创建，所生产的产品在
//同一层次上，相对于简单工厂模式，工厂方法模式对于产品的增
//加更加方便

class Animal {
public:
	virtual ~Animal(){}
	virtual void display() = 0;
};

class AnimalCreator {
public:
	virtual ~AnimalCreator(){}
	virtual Animal* creatAnimal() = 0;
};

class Cat : public Animal {
public:
	void display(){ cout<<"Cat miaomiao"<<endl;}
};

class CatCreator : public AnimalCreator {
public:
	Animal *creatAnimal(){ return new Cat();}
};

class Dog : public Animal {
public:
	void display(){ cout<<"Dog wangwang"<<endl;}
};

class DogCreator : public AnimalCreator {
public:
	Animal *creatAnimal(){ return new Dog();}
};


int main(int argc, char *argv[])
{
	AnimalCreator *pCreator = new DogCreator();
	//AnimalCreator *pCreator = new CatCreator();
	
	Animal *pa = pCreator->creatAnimal();
	pa->display();

	return 0;
}
//对于工厂方法模式的学习，主要是学习它和简单工厂模式之间的区别
//第一，简单工厂模式对于增加新的产品是不支持的，工厂方法模式支
//持产品的增加；第二，工厂和产品之间的对应关系不同，简单工厂模
//式是一个工厂对应多个产品，工厂方法模式是一个工厂对于一个产品
//；第三，因为不同的产品对应不同的工厂类，所以工厂类随着产品的
//增加增加，这是工厂方法模式的缺点。
