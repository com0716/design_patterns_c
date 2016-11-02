#include <iostream>
#include <string>
using namespace std;

//adapter
//适配器模式

class Target {
public:
	virtual ~Target(){}
	virtual void request() = 0;
};

class Adaptee {
public:
	void specialRequest(string name) {
		cout<<"Adaptee "<<name<<endl;
	}
};

class Adaptor : public Target {
public:
	Adaptor(Adaptee *a) :pa(a){}

	void request() {
		if (pa) pa->specialRequest("Adaptor");
	}
private:
	Adaptee *pa;
};

int main(int argc, char *argv[])
{
	Target *pt = new Adaptor(new Adaptee());

	pt->request();

	return 0;
}
