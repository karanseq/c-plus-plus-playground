#include <assert.h>
#include <iostream>
#include <vector>

template<typename T>
inline void SwapElements(std::vector<T>& io_array, const int32_t i_lhs, const int32_t i_rhs)
{
	T swap = io_array[i_lhs];
	io_array[i_lhs] = io_array[i_rhs];
	io_array[i_rhs] = swap;
}

template<typename T>
int32_t Partition(std::vector<T>& io_array, const int32_t i_low, const int32_t i_high, const T& i_pivot_value)
{
	using namespace std;

	int32_t low_index = i_low;
	int32_t high_index = i_high - 1;

	while (1)
	{
		// from the left, search for any element that is greater than or equal to pivot
		while (low_index <= high_index && io_array[low_index] < i_pivot_value)
		{
			++low_index;
		}

		// from the right, search for any element that is less than pivot
		while (high_index > 0 && io_array[high_index] >= i_pivot_value)
		{
			--high_index;
		}

		// check if the entire array has been covered
		if (low_index >= high_index)
		{
			break;
		}

		// swap the left and right elements
		SwapElements(io_array, low_index, high_index);
	}

	// put the pivot value in its proper place
	SwapElements(io_array, low_index, i_high);

	return low_index;
}

template<typename T>
void QuickSort(std::vector<T>& io_array, const int32_t i_low, const int32_t i_high)
{
	using namespace std;

	if ((i_high - i_low) <= 0)
	{
		return;
	}

	int32_t pivot = Partition(io_array, i_low, i_high, io_array[i_high]);

	QuickSort(io_array, i_low, pivot - 1);
	QuickSort(io_array, pivot + 1, i_high);
}

template<typename T>
void QuickSort(const size_t i_size, std::vector<T>& io_array)
{
	assert(i_size > 1);

	QuickSort(io_array, 0, i_size - 1);
}
