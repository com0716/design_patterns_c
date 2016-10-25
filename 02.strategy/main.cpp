#include <iostream>
#include <string>
using namespace std;

//strategy
//策略模式能够定义算法家族，通过一个类中包含一个算法抽象类实现
//算法和具体类的解耦合

class Comparator {
public:
	virtual ~Comparator(){}
	virtual int compare(const void *, const void *) = 0;
};

class Student {
public:
	Student(int m, int p) :math(m), phy(p){}

	int getMath() const {return math; }
	int getPhy() const {return phy; }

	static void setComparator(Comparator *p)
	{
		pc = p;
	}

	int compareTo(const Student &s)
	{
		return pc->compare(this, &s);
	}
private:
	int math;
	int phy;

	static Comparator *pc;
};

class StudentMathComparator : public Comparator {
public:
	int compare(const void *s1, const void *s2)
	{
		return ((Student*)s1)->getMath()
			- ((Student*)s2)->getMath();
	}
};

Comparator* Student::pc = new StudentMathComparator();

class StudentPhyComparator : public Comparator {
public:
	int compare(const void *s1, const void *s2)
	{
		return ((Student*)s1)->getPhy()
			- ((Student*)s2)->getPhy();
	}
};

int main(int argc, char *argv[])
{
	Student s1(60, 80), s2(70, 70);

	Student::setComparator(new StudentPhyComparator());

	if (s1.compareTo(s2) > 0)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	
	return 0;
}
//如果要改变比较的策略，只需要创建新的类，或者使用已有的类即可
//上面的例子只是实现类实例之间的比较，如果想要通过一个类实现所
//有类的排序，那就需要抽象出另一个类。这就是java中的Comparable
//接口和Comparator接口，实现也较为简单，留给以后补充。
//策略模式是一个接口很明显的模式，使用了组合结构。
