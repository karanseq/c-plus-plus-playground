class Subject;		// forward declaration

class SubjectListener
{
public:
	virtual void OnChange(Subject*) = 0;
};
