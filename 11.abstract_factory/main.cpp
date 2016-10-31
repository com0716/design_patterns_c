#include <iostream>
#include <string>
using namespace std;

//abstract factory
//抽象工厂模式，生成的是不同的工厂，然后由工厂去产生不同的
//产品
class Product {
public:
	virtual ~Product(){}
	virtual void display() = 0; 
};

class AbstractFactory {
public:
	virtual ~AbstractFactory(){}
	virtual Product* createProductA() = 0;
	virtual Product* createProductB() = 0;
};

class ProductA : public Product {
public:
	void display() {cout<<"ProductA"<<endl;}
};

class ProductB : public Product {
public:
	void display() {cout<<"ProductB"<<endl;}
};

class ConcreteFactory : public AbstractFactory {
public:
	Product* createProductA() {return new ProductA();}
	Product* createProductB() {return new ProductB();}
};

int main(int argc, char *argv[])
{
	AbstractFactory *paf = new ConcreteFactory();
	paf->createProductA()->display();
	paf->createProductB()->display();

	return 0;
}
