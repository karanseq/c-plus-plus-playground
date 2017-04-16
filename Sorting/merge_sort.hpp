#include <assert.h>
#include <vector>

// TODO
// Make use of a single temporary array that gets passed down recursively
// instead of creating new vectors for each merge.

template<typename T>
void Merge(std::vector<T>& io_array, size_t i_lower, size_t i_mid, size_t i_upper, int i_tabs = 0)
{
	using namespace std;

	vector<T> low;
	low.insert(low.begin(), io_array.begin() + i_lower, io_array.begin() + i_mid + 1);

	vector<T> high;
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
void Split(std::vector<T>& i_array, size_t i_lower, size_t i_upper, int i_tabs = 0)
{
	if (i_lower == i_upper)
	{
		return;
	}

	size_t mid = (i_lower + i_upper) >> 1;

	Split(o_placeholder, i_array, i_lower, mid, i_tabs + 1);
	Split(o_placeholder, i_array, mid + 1, i_upper, i_tabs + 1);
	Merge(o_placeholder, i_array, i_lower, mid, i_upper, i_tabs + 1);
}

template<typename T>
void MergeSort(const size_t i_size, std::vector<T>& io_array)
{
	assert(i_size > 1);

	using namespace std;

	Split(placeholder, io_array, 0, i_size - 1);
}
