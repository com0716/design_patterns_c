#include <iostream>
#include <string>
using namespace std;

//builder
//建造者模式，能够保证对象实例建立的一个固定的顺序

class Builder {
public:
	virtual ~Builder(){}
	virtual void first() = 0;
	virtual void second() = 0;
	virtual void third() = 0;
};

class BuilderDirector {
public:
	void construct(Builder &builder)
	{
		builder.first();
		builder.second();
		builder.third();
	}
};

class Rice : public Builder {
public:
	void first(){cout<<"淘米"<<endl;}
	void second(){cout<<"煮米"<<endl;}
	void third(){cout<<"盛饭"<<endl;}
};

int main(int argc, char *argv[])
{
	Rice r1;
	BuilderDirector bd;

	bd.construct(r1);

	return 0;
}
