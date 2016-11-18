#include <iostream>
#include <string>
using namespace std;

//iterator
//迭代器模式，STL
class MyIterator {
public:
	virtual ~MyIterator(){}
	virtual void* begin() = 0;
	virtual void* end() = 0;
};

class MyIntList : public MyIterator {
public:
	MyIntList(int l) :length(l){
		pArray = new int[l];
	}
	void* begin(){ return (void *)pArray;}
	void* end() {return (void *)(pArray + length);}

	void setByIndex(int index, int value) {
		if (index < length)
			pArray[index] = value;
		else
			cout<<"illegal index"<<endl;
	}

private:
	int *pArray;
	int length;
};

int main(int argc, char *argv[])
{
	MyIntList list(10);

	list.setByIndex(0, 10);

	cout<<*(int *)list.begin()<<endl;

	return 0;
}
