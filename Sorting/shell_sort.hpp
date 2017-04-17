#include <assert.h>
#include <vector>

template<typename T>
void ShellSort(const size_t i_size, std::vector<T>& io_array)
{
	assert(i_size > 1);

	T swap;

	// calculate stride
	size_t stride = 0;
	while (stride <= i_size / 3)
	{
		stride = 3 * stride + 1;
	}

	// loop till stride is 1
	while (stride > 0)
	{
		// regular insertion sort from stride
		for (size_t i = stride; i < i_size; ++i)
		{
			swap = io_array[i];
			size_t j = i;

			// compared to insertion sort, we search backwards by stride instead of 1
			while (j > stride - 1 && io_array[j - stride] >= swap)
			{
				io_array[j] = io_array[j - stride];
				j -= stride;
			}

			io_array[j] = swap;
		}

		stride = (stride - 1) / 3;
	}
}
