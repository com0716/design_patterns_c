#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//state
//状态模式实现的是对状态的扩展

class Work;
class State {
public:
	virtual ~State(){}
	virtual void checkTime(Work &) = 0;
};

class Work {
public:
	void setState(State *p){ps = p;}
	void setTime(int t) {time = t;}
	int getTime() const {return time;}
	void currentWork(){ps->checkTime(*this);}
private:
	State *ps;
	int time;
};


class NightState : public State{
public:
	void checkTime(Work &w) {
		cout<<"时间:"<<w.getTime()<<",晚上就应该早点休息"<<endl;
	}
};

class NoonState : public State{
public:
	void checkTime(Work &w) {
		if (w.getTime() > 17) {
			w.setState(new NightState());
			w.currentWork();
		}
		else
			cout<<"时间:"<<w.getTime()<<",中午可以趴在桌子上小憩一会"<<endl;
	}
};

class MorningState : public State{
public:
	void checkTime(Work &w) {
		if (w.getTime() > 12) {
			w.setState(new NoonState());
			w.currentWork();
		}
		else
			cout<<"时间:"<<w.getTime()<<",早起吃早餐，上午干劲十足"<<endl;
	}
};

int main(int argc, char *argv[])
{
	Work w;
	
	w.setState(new MorningState());
	w.setTime(atoi(argv[1]));
	w.currentWork();

	return 0;
}
