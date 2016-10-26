#include <iostream>
#include <string>
using namespace std;

//proxy
//有些类对象不能被客户端直接访问，需要一个中间对象进行传递
//，这时候就需要代理模式。

class Person {
public:
	virtual ~Person(){}
	virtual void display() = 0;
	virtual void draw() = 0;
	virtual void write() = 0;
};

class PersonProxy : public Person{
public:
	PersonProxy(Person &person) :p(&person){}

	void display(){p->display();}
	void draw(){p->draw();}
	void write() {p->write();}

private:
	Person *p;
};

class Student : public Person {
public:
	Student(string n) :name(n){}
	void display() {cout<<name<<" display"<<endl;}
	void draw() {cout<<name<<" draw"<<endl;}
	void write() {cout<<name<<" write"<<endl;}
private:
	string name;
};

int main(int argc, char *argv[])
{
	Student s1("xiaoming");

	PersonProxy pp(s1);
	pp.display();
	pp.draw();
	pp.write();

	return 0;
}
//上面的代理模式的实现应该叫做静态代理，而真正有用的，值得学习
//的是动态代理模式。这个在C++中的实现难度较大，但是在java中借助
//jar包就可以实现。
