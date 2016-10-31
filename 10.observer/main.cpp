#include <iostream>
#include <string>
#include <list>
using namespace std;

//observer
//观察者模式，和观察者模式相对应的就是事件处理机制，当一个
//时间触发的时候，事件的观察者应该做出什么样的反应，并且如
//何通知观察者

//场景：孩子醒了，父亲喂孩子吃饭
class WakenUpListener {
public:
	virtual ~WakenUpListener(){}
	virtual void wakenUpAction() = 0;
};

class Child {
public:
	void wakenUp() {
		cout<<"小孩醒了"<<endl;
		for (auto p : listeners) {
			p->wakenUpAction();
		}
	}
	
	Child& addObserver(WakenUpListener *p) { 
		listeners.push_back(p);
		return *this;
	}
		
private:
	list<WakenUpListener *> listeners;
};

class Father : public WakenUpListener {
public:
	void wakenUpAction(){
		cout<<"父亲喂孩子吃饭"<<endl;
	} 
};

class GrandFather : public WakenUpListener {
public:
	void wakenUpAction() {
		cout<<"爷爷带着孩子出去晒太阳"<<endl;
	}
};

int main(int argc, char *argv[])
{
	Child c1;
	c1.addObserver(new Father())
	  .addObserver(new GrandFather());
	c1.wakenUp();
	
	return 0;
}
