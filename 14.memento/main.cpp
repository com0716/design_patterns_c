#include <iostream>
#include <string>
using namespace std;

//memento
//备忘录模式，能够保存历史状态，并进行状态的回退
//

class Memento {
public:
	Memento(){}
	Memento(string s) :state(s){}
	string getState() const {return state;}
	void setState(string s) {state = s;}
private:
	string state;
};

class Originator {
public:
	Memento* createMemento(){ return new Memento(state);}
	void restoreMemento(const Memento &m) {state = m.getState();}
	
	string getState() const {return state;}
	void setState(string s) {state = s;}
private:
	string state;
};

class Caretaker {
public:
	void setMemento(Memento &m) {pm = &m;}
	Memento* getMemento() { return pm;}
private:
	Memento *pm;
};

int main(int argc, char *argv[])
{
	Originator o1;
	o1.setState("state1");
	cout<<o1.getState()<<endl;

	Caretaker c1;
	c1.setMemento(*o1.createMemento());

	o1.setState("state2");
	cout<<o1.getState()<<endl;

	o1.restoreMemento(*c1.getMemento());
	cout<<o1.getState()<<endl;

	return 0;
}
