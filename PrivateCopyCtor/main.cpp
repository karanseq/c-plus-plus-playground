#include <iostream>

#include "theclass.h"

ContainsPrivateCopyCtor::ContainsPrivateCopyCtor(const ContainsPrivateCopyCtor& source)
{
    data_1_ = source.GetData1();
    data_2_ = source.GetData2();
}

void ContainsPrivateCopyCtor::operator=(const ContainsPrivateCopyCtor& source)
{
    data_1_ = source.GetData1();
    data_2_ = source.GetData2();
}

int main()
{
    std::cout << "Testing private copy constructors and private copy assignment operators" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "Creating an object of the Class....." << std::endl;
    ContainsPrivateCopyCtor obj1;
//    ContainsPrivateCopyCtor obj2(obj1);
    return 0;
}
