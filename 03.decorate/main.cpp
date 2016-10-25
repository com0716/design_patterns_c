#include <iostream>
#include <string>
using namespace std;

//decorate
//装饰模式的主要作用是实现对象的动态扩展，是替代继承的一种
//设计模式。

class Person {
public:
	Person(){}
	Person(string n) :name(n){}
	virtual ~Person(){}
	virtual void display()
	{
		cout<<"装饰的"<<name<<endl;
	}
private:
	string name;
};

class Finery : public Person {
public:
	Finery(){}
	void decorate(Person &p)
	{
		this->p = &p;
	}

	virtual void display()
	{
		if (p) p->display();
	}
private:
	Person *p;
};

class Hat : public Finery {
public:
	void display()
	{
		cout<<"帽子"<<" ";
		Finery::display();
	}
};

class Glasses : public Finery {
public:
	void display()
	{
		cout<<"眼镜"<<" ";
		Finery::display();
	}
};


int main(int argc, char *argv[])
{
	Person xiaoming("小明");

	Hat ht;
	Glasses gl;

	ht.decorate(xiaoming);
	gl.decorate(ht);

	gl.display();

	return 0;
}
