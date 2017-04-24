#include <assert.h>
#include <vector>

template<typename T>
void Merge(std::vector<T>& io_array, size_t i_lower, size_t i_mid, size_t i_upper)
{
	std::vector<T> low;
	low.insert(low.begin(), io_array.begin() + i_lower, io_array.begin() + i_mid + 1);

	std::vector<T> high;
	high.insert(high.begin(), io_array.begin() + i_mid + 1, io_array.begin() + i_upper + 1);

	size_t k = i_lower;
	size_t i = 0;
	size_t j = 0;

	while (k <= i_upper && i <= i_mid - i_lower && j < i_upper - i_mid)
	{
		if (low[i] <= high[j])
		{
			io_array[k] = low[i];
			++i;
		}
		else
		{
			io_array[k] = high[j];
			++j;
		}
		++k;
	}

	while (k <= i_upper)
	{
		if (i <= i_mid - i_lower)
		{
			io_array[k] = low[i];
			++i;
		}
		else if (j < i_upper - i_mid)
		{
			io_array[k] = high[j];
			++j;
		}
		++k;
	}
}

template<typename T>
void Split(std::vector<T>& i_array, size_t i_lower, size_t i_upper)
{
	if (i_lower == i_upper)
	{
		return;
	}

	size_t mid = (i_lower + i_upper) >> 1;

	Split(i_array, i_lower, mid);
	Split(i_array, mid + 1, i_upper);
	Merge(i_array, i_lower, mid, i_upper);
}

template<typename T>
void MergeSort(const size_t i_size, std::vector<T>& io_array)
{
	assert(i_size > 1);
	Split(io_array, 0, i_size - 1);
}
