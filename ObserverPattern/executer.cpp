#include <iostream>

#include "Listener.h"
#include "Subject.h"

void CreateSubjects(std::vector<Subject*>& subjects, int num_subjects)
{
	for(auto i = 0; i < num_subjects; ++i)
	{
		subjects.push_back(new Subject((int)(rand() % 100)));
	}
}

void CreateListeners(std::vector<Listener*>& listeners, int num_listeners)
{
	for(auto i = 0; i < num_listeners; ++i)
	{
		listeners.push_back(new Listener());
	}
}

void AssignListeners(std::vector<Subject*>& subjects, std::vector<Listener*>& listeners)
{
	auto num_subjects = subjects.size();
	for(auto listener : listeners)
	{
		auto subject_picker = rand() % num_subjects;
		subjects[subject_picker]->AddListener(listener);
	}
}

int main()
{
	srand(time(0));
	
	std::vector<Subject*> subjects;
	subjects.clear();
	CreateSubjects(subjects, 2);
	
	std::vector<Listener*> listeners;
	listeners.clear();
	CreateListeners(listeners, 10);
	
	AssignListeners(subjects, listeners);
	
	std::cout << "~~~~~~~~~~~~~~~~ DUMP ~~~~~~~~~~~~~\n";
	auto counter = 0;
	for(auto subject : subjects)
	{
		std::cout << "Subject-" << ++counter << " has " << subject->GetNumListeners() << " listeners" << std::endl;
	}
	
	/*std::cout << "~~~~~~~~~~~~~~~ BOO! ~~~~~~~~~~~~~~\n";
	for(auto subject : subjects)
	{
		subject->SetValue(rand() % 100);
	}*/
	
	subjects[0]->SetValue(rand() % 100);
}
