#include <iostream>

class A
{
public:
	A() : i_(0)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual ~A() {}

protected:
	int i_;
};

class B
{
public:
	B()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual ~B() {}

protected:
	const A a;
};

int main()
{
	std::cout << "----------" << std::endl;
	B b;

	return 0;
}
