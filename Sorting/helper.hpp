#include <assert.h>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <vector>

enum class AlgorithmType {
	kBubbleSort = 0,
	kSelectionSort = 1,
	kInsertionSort = 2,
	kMergeSort = 3
};

const char* GetAlgorithmName(const AlgorithmType i_algorithm)
{
	switch (i_algorithm)
	{
	case AlgorithmType::kBubbleSort:
		return "Bubble Sort";
	
	case AlgorithmType::kSelectionSort:
		return "Selection Sort";
	
	case AlgorithmType::kInsertionSort:
		return "Insertion Sort";
	
	case AlgorithmType::kMergeSort:
		return "Merge Sort";
	}
}

template<typename T>
void GenerateUnsortedArray(std::vector<T>& o_array, const size_t i_size, const T i_max_value = std::numeric_limits<T>::max())
{
	assert(i_size);

	using namespace std;

	o_array.reserve(i_size);

	// cout << "Generating an unsorted array with " << i_size << " elements..." << endl;
	for (size_t i = 0; i < i_size; ++i)
	{
		o_array.push_back(static_cast<T>(rand() % int(i_max_value)));
	}
}

template<typename T>
void PrintArray(const size_t i_size, const std::vector<T>& i_array)
{
	using namespace std;

	for (const auto& i : i_array)
	{
		cout << i << " ";
	}
	cout << endl;
}
