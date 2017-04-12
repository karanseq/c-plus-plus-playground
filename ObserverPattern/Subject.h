#include <vector>
#include <iostream>

class SubjectListener;		// forward declaration

class Subject
{
public:
	Subject(int value) : value_(value)
	{
		listeners_.clear();
		std::cout << "Subject initiated with value:" << value_ << std::endl;
	};
	virtual ~Subject();
	
	inline void AddListener(SubjectListener* listener) { listeners_.push_back(listener); }
	inline int GetNumListeners() { return listeners_.size(); }
	
	void SetValue(int value);
	inline int GetValue() { return value_; }
	
protected:
	int value_;
	std::vector<SubjectListener*> listeners_;
};
