#include <iostream>
#include <string>
using namespace std;

//prototype
//原型模式，通过这些原型实例指定创建对象的种类

class Prototype {
public:
	virtual ~Prototype(){}
	virtual Prototype* clone() = 0;
};

class Student : public Prototype {
public:
	Student(string n) :name(n){}
	void display() {cout<<name<<endl;}
	Prototype* clone() {return new Student(*this);}
private:
	string name;
};



int main(int argc, char *argv[])
{
	Student xiaoming("xiaoming");

	Student *ps = dynamic_cast<Student *>(xiaoming.clone());

	ps->display();

	return 0;
}
