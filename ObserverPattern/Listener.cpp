#include "Listener.h"
#include "Subject.h"
#include <iostream>

void Listener::OnChange(Subject* subject)
{
	std::cout << __FILE__ << "::" << __FUNCTION__ << "Value:" << subject->GetValue() << std::endl;
}
