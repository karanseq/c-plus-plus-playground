#include <assert.h>
#include <vector>

template<typename T>
void SelectionSort(const size_t i_size, std::vector<T>& io_array)
{
	assert(i_size > 1);

	for (size_t i = 0; i < i_size; ++i)
	{
		size_t min = i;

		for (size_t j = i + 1; j < i_size; ++j)
		{
			if (io_array[j] < io_array[min])
			{
				min = j;
			}
		}

		if (io_array[i] > io_array[min])
		{
			T swap = io_array[i];
			io_array[i] = io_array[min];
			io_array[min] = swap;
		}
	}
}
