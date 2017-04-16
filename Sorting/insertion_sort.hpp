#include <assert.h>
#include <vector>

template<typename T>
void InsertionSort(const size_t i_size, std::vector<T>& io_array)
{
	assert(i_size > 1);

	T swap;
	size_t j = 0;

	for (size_t i = 1; i < i_size; ++i)
	{
		swap = io_array[i];
		j = i;

		while (j > 0 && io_array[j - 1] >= swap)
		{
			io_array[j] = io_array[j - 1];
			--j;
		}

		io_array[j] = swap;
	}
}
