#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

void dump(const vector<int>& data)
{
	cout << __FUNCTION__ << endl;
	for (size_t i = 0; i < data.size(); ++i) cout << data[i] << endl;
}

void sort(vector<int>& data)
{
	size_t size = data.size();
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = i + 1; j < size; ++j)
		{
			if (data[i] > data[j])
			{
				int swap = data[i];
				data[i] = data[j];
				data[j] = swap;
			}
		}
	}
}

int main()
{
	srand(time(NULL));
	cout << "SIMPLE SORT" << endl;
	
	const int count = 5;
	// fill
	vector<int> numbers;
	for (int i = 0; i < count; ++i) numbers.push_back(rand() % count);
	
	// randomize
	for (int i = 0; i < count; ++i)
	{
		int rand_index = rand() % count;
		int swap = numbers[rand_index];
		numbers[rand_index] = numbers[i];
		numbers[i] = swap;
	}
	
	dump(numbers);
	
	sort(numbers);
	
	dump(numbers);
}
