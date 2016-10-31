#include <iostream>
#include <string>
using namespace std;

//facade
//初次接触外观模式，很难理解它的应用场景。感觉像在其他地方
//写了好多函数，封装之后在另外一个地方调用，这样做的目的是
//减少对客户端程序的改写，只对封装的函数的进行改写

class Light {
public:
	void turnOff(){cout<<"turn off the light"<<endl;}
	void tutnOn(){cout<<"turn on the light"<<endl;}
};

class Door {
public:
	void openDoor(){cout<<"open the door"<<endl;}
	void closeDoor(){cout<<"close the door"<<endl;}
};

class HomeFacade {
public:
	HomeFacade(){
		pl = new Light();
		pd = new Door();
	}

	void arrive(){
		pd->openDoor();
		pl->tutnOn();
	}

	void leave(){
		pl->turnOff();
		pd->closeDoor();
	}
private:
	Light *pl;
	Door *pd;
};

int main(int argc, char *argv[])
{
	HomeFacade hf;
	hf.arrive();
	hf.leave();
	
	return 0;
}
