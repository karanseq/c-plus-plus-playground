#include <iostream>
#include <typeinfo>

using namespace std;

class A
{
public:
	A()
	{ cout << __PRETTY_FUNCTION__ << endl; }

	virtual ~A()
	{ cout << __PRETTY_FUNCTION__ << endl; }
};

class B : public A
{
public:
	B()
	{ cout << __PRETTY_FUNCTION__ << endl; }

	virtual ~B()
	{ cout << __PRETTY_FUNCTION__ << endl; }
};

class C : public B
{	
public:
	C()
	{ cout << __PRETTY_FUNCTION__ << endl; }

	virtual ~C()
	{ cout << __PRETTY_FUNCTION__ << endl; }
};

class D
{
public:
	D()
	{ cout << __PRETTY_FUNCTION__ << endl; }

	virtual ~D()
	{ cout << __PRETTY_FUNCTION__ << endl; }
protected:
	A obj;
};

int main()
{
/*	C* obj = new C();

	void* obj_v = (void*) obj;

	cout << "Deleting the void object" << endl;

	cout << "Type of obj = " << typeid(obj).name() << endl;
	cout << "Type of obj_v = " << typeid(obj_v).name() << endl;

	delete (A*)obj_v;*/


	D* obj = new D();
	void* obj_v = (void*)obj;
	delete (D*)obj_v;


	return 0;
}
