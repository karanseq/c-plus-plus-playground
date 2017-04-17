#include <assert.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <vector>

enum class AlgorithmType {
	kNone = 0,
	kBubbleSort = 1,
	kSelectionSort = 2,
	kInsertionSort = 3,
	kMergeSort = 4,
	kShellSort = 5,
	kQuickSort = 6,
	kMax = 7
};

void GetEnabledAlgorithms(std::vector<AlgorithmType>& o_algorithms, const char* i_input)
{
	uint32_t input = atoi(i_input);
	if (input > 0)
	{
		while (input > 0)
		{
			o_algorithms.push_back(static_cast<AlgorithmType>(input % 10));
			input /= 10;
		}	
	}
	else
	{
		o_algorithms = { AlgorithmType::kBubbleSort,
			AlgorithmType::kSelectionSort,
			AlgorithmType::kInsertionSort,
			AlgorithmType::kMergeSort,
			AlgorithmType::kShellSort,
			AlgorithmType::kQuickSort };
	}
}

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
	
	case AlgorithmType::kShellSort:
		return "Shell Sort";
	
	case AlgorithmType::kQuickSort:
		return "Quick Sort";

	default:
		return "";
	}
}

template<typename T>
void GenerateUnsortedArray(std::vector<T>& o_array, const size_t i_size, const T i_max_value)
{
	assert(i_size);

	using namespace std;

	o_array.reserve(i_size);

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
