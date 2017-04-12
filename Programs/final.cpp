#include <iostream>

class A
{
public:
	A() : i_(0)
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual ~A() {}

	// my children should have no right to this function, hence the final
	virtual void foo() final
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}

protected:
	int i_;
};

class B : public A
{
public:
	B()
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual ~B() {}

	// trying to touch things that my parent doesn't want me to
	void foo() override
	{
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
};

int main()
{
	std::cout << "----------" << std::endl;
	B b;

	return 0;
}
