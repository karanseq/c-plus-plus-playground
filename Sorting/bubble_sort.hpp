#include <assert.h>
#include <vector>

template<typename T>
void BubbleSort(const size_t i_size, std::vector<T>& io_array)
{
	assert(i_size > 1);

	for (size_t i = i_size - 1; i > 0; --i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			if (io_array[j] > io_array[j + 1])
			{
				T swap = io_array[j];
				io_array[j] = io_array[j + 1];
				io_array[j + 1] = swap;
			}
		}
	}
}
