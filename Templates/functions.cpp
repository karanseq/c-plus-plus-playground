#include <iostream>

using namespace std;

template<typename T>
T GetAverageOf(const T* elements, int num_elements)
{
	T sum = T();
	for(auto i = 0; i < num_elements; ++i)
	{
		sum += elements[i];
	}

	return sum / num_elements;
}

template<typename T1, typename T2>
void PrintValues(const T1& value1, const T2& value2)
{
	cout << "Value1:" << value1 << "  Value2:" << value2 << endl;
}

template<typename T1, typename T2>
T1 Sum(const T2& value1, const T2& value2)
{
	T1 sum = T1();
	sum = value1 + value2;
	return sum;
}

int main()
{
	cout << "\n********** Template Function Test **********\n";

	int int_array[5] = {10, 20, 30, 40, 50};
	float float_array[5] = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f};

	cout << "Average of int_array is:" << GetAverageOf(int_array, 5) << endl;
	cout << "Average of float_array is:" << GetAverageOf(float_array, 5) << endl;

	cout << "\n~~~~~~~~~~~~~~~~~~~~\n";

	cout << "PrintValues<double, double>:";
	PrintValues<int, int>(123.123, 456.456);
	cout << "PrintValues:";
	PrintValues(123, 456.456);

	cout << "\n~~~~~~~~~~~~~~~~~~~~\n";

	cout << "Sum<double>(12.55, 15.55):" << Sum<double>(12.55, 15.55) << endl;
	cout << "Sum<int>(12.55, 15.55):" << Sum<int>(12.55, 15.55) << endl;

	return 0;
}
