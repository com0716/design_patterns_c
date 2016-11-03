#include <iostream>
#include <string>
#include <list>
using namespace std;

//composite
//组合模式，这是很常见的一种模式，主要是解除不同层级之间的
//耦合。界面编程中不同组件之间的组合就是使用这样的模式。

class Education {
public:
	Education(string n) :name(n){}
	virtual ~Education(){}
	virtual Education& addChild(const Education &e) = 0;
	virtual void display(int depth) const = 0;
protected:
	string name;
};

class School : public Education {
public:
	School(string n) :Education(n){}
	Education& addChild(const Education &e) {
		children.push_back(&e);
		return *this;
	}
	void display(int depth) const {
		cout<<string(depth, '-')<<name<<endl;
		for (auto p : children) {
			p->display(depth + 2);
		}
	}
private:
	list<const Education *> children;
};

class Student : public Education {
public:
	Student(string n) :Education(n) {}
	Education& addChild(const Education &e){return *this;}
	void display(int depth) const {
		cout<<string(depth, '-')<<name<<endl;
	}
};

int main(int argc, char *argv[])
{
	Student s1("张三"), s2("李四"), s3("王五"), s4("赵柳"), s5("孙霸");

	School telecom("电子学院");
	School transport("运输学院");

	School bjtu("北京交通大学");

	telecom.addChild(s1).addChild(s2).addChild(s3);
	transport.addChild(s4).addChild(s5);

	bjtu.addChild(telecom).addChild(transport);
	bjtu.display(0);

	return 0;
}
//其实就是借助链表建立了一个区分级别的树行结构。然后在访问的过
//程中进行遍历。
