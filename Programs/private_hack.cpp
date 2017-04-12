#include <stdio.h>
#include <string.h>

class TestClass {
public:
	inline void SetA(int a) { this->a = a; }
	inline void SetB(int b) { this->b = b; }
	inline void SetC(int c) { this->c = c; }

	inline int GetA() { return this->a; }
	inline int GetB() { return this->b; }
	inline int GetC() { return this->c; }
private:
	int a;
	int b;
	int c;
};


class HackClass {
public:
	int a;
	int b;
	int c;
};

void SomeFunc(int some_int)
{
	printf("Some int:%d\n", some_int);
}

typedef void (*kuch_alag_func_ptr)();

int main()
{
	TestClass obj;
	obj.SetA(11);
	obj.SetB(22);
	obj.SetC(33);

	HackClass hack;
	hack.a = 1;
	hack.b = 2;
	hack.c = 3;

	memcpy(&obj, &hack, sizeof(hack));

	printf("TEST.A = %d\n", obj.GetA());
	printf("TEST.B = %d\n", obj.GetB());
	printf("TEST.C = %d\n", obj.GetC());

	printf("Testing Function pointer hack\n");
	void (*some_func_ptr)(int) = &SomeFunc;

//	(some_func_ptr)(123);

	int* some_address = (int*)(some_func_ptr);

	void (*some_other_func_ptr)() = (kuch_alag_func_ptr)(some_address);

	(some_other_func_ptr)();

	printf("Some func ptr:%p\t\tSome address:%p\n", some_func_ptr, some_address);

	return 0;
}

