#include <iostream>

class A
{
public:
	A() : i_(0)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual ~A() {}

	// both const and non-const objects can access me
	void foo() const
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

	// only non-const objects can access me
	void foo()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

protected:
	int i_;
};

int main()
{
	std::cout << "----------" << std::endl;
	A a1;
	a1.foo();

	const A a2;
	a2.foo();

	return 0;
}
