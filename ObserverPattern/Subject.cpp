#include "Subject.h"
#include "SubjectListener.h"

Subject::~Subject()
{
	listeners_.clear();
}

void Subject::SetValue(int value)
{
	value_ = value;
	
	for(auto listener : listeners_)
	{
		listener->OnChange(this);
	}	
}
