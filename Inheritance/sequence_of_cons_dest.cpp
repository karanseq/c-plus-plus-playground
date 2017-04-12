#include <iostream>

using namespace std;

class Base1
{
public:
	Base1() { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~Base1() { cout << __PRETTY_FUNCTION__ << endl; }
};

class Base2
{
public:
	Base2() { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~Base2() { cout << __PRETTY_FUNCTION__ << endl; }
};

class Child1 : public Base1
{
public:
	Child1() { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~Child1() { cout << __PRETTY_FUNCTION__ << endl; }
};

class Child2 : public Child1
{
public:
	Child2() { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~Child2() { cout << __PRETTY_FUNCTION__ << endl; }
};

class Child3 : public Base1, public Base2
{
public:
	Child3() { cout << __PRETTY_FUNCTION__ << endl; }
	virtual ~Child3() { cout << __PRETTY_FUNCTION__ << endl; }
};

int main()
{
	cout << "Demonstrating executing sequence of constructor & destructors" << endl;

	cout << "Creating objects now" << endl;
	Child1 *c1 = new Child1();
	cout << "--------------------" << endl;
	Child2 *c2 = new Child2();
	cout << "--------------------" << endl;
	Child3 *c3 = new Child3();
	cout << "--------------------" << endl;

	cout << "Destroying objects now" << endl;
	delete c1;
	cout << "--------------------" << endl;
	delete c2;
	cout << "--------------------" << endl;
	delete c3;
	cout << "--------------------" << endl;

	cout << "Done" << endl;
}
