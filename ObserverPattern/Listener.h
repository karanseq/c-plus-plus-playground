#include "SubjectListener.h"

class Subject;		// forward declaration

class Listener : public SubjectListener
{
public:
	Listener(){};
	virtual ~Listener(){};
	
	void OnChange(Subject*);
protected:
};
