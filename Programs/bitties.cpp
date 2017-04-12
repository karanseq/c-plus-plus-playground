#include <iostream>

int main()
{
	std::cout << "----------" << std::endl;
	int bitty = 1 << 0;
	std::cout << bitty << std::endl;
	bitty = 1 << 1;
	std::cout << bitty << std::endl;
	bitty = 1 << 6;
	std::cout << bitty << std::endl;
	bitty = 1 << 8;
	std::cout << bitty << std::endl;
	return 0;
}
