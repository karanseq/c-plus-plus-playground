#include <assert.h>
#include <chrono>
#include <iostream>
#include <time.h>
#include <vector>

#include "bubble_sort.hpp"
#include "helper.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "selection_sort.hpp"
#include "shell_sort.hpp"

static const size_t MAX_VALUE = 1000;
static const size_t PRINT_CRITERIA = 100;

template<typename T>
void Sort(const size_t i_array_size, const AlgorithmType i_algorithm)
{
	assert(i_array_size);

	using namespace std;

	cout << "\n\n" << GetAlgorithmName(i_algorithm) << endl;
	cout << "--------------" << endl;

	// generate an unsorted array of integers
	vector<T> array;
	GenerateUnsortedArray<T>(array, i_array_size, MAX_VALUE);

	chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
	if (i_array_size <= PRINT_CRITERIA) PrintArray<T>(i_array_size, array);

	switch (i_algorithm)
	{
		case AlgorithmType::kBubbleSort:
		BubbleSort<T>(i_array_size, array);
		break;

		case AlgorithmType::kSelectionSort:
		SelectionSort<T>(i_array_size, array);
		break;

		case AlgorithmType::kInsertionSort:
		InsertionSort<T>(i_array_size, array);
		break;

		case AlgorithmType::kMergeSort:
		MergeSort<T>(i_array_size, array);
		break;

		case AlgorithmType::kShellSort:
		ShellSort<T>(i_array_size, array);
		break;

		case AlgorithmType::kQuickSort:
		QuickSort<T>(i_array_size, array);
		break;

		default:
		return;
	}

	chrono::duration<double> execution_time = chrono::system_clock::now() - start;
	cout << "Execution time:" << execution_time.count() << " seconds" << endl;

	if (i_array_size <= PRINT_CRITERIA)
	{
		cout << "\nResult:" << endl;
		PrintArray<T>(i_array_size, array);
	}
}

int main(int argc, char* argv[])
{
	using namespace std;

	size_t array_size = 25000;
	std::vector<AlgorithmType> enabled_algorithms;
	if (argc > 2)
	{
		array_size = atof(argv[1]);
		GetEnabledAlgorithms(enabled_algorithms, argv[2]);
	}

	cout << "The sorting suite" << endl;
	cout << "-----------------" << endl;
	cout << "Array size:" << array_size << endl;

	srand(static_cast<unsigned int>(time(0)));

	for (const auto& i : enabled_algorithms)
	{
		Sort<int>(array_size, i);
	}

	cout << endl;
	return 0;
}
