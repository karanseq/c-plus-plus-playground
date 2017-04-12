#include <iostream>

using namespace std;

// simple template class
template<class T>
class Value
{
public:
	Value() : data_(T()) {};
	Value(T data) : data_(data) {};
	virtual ~Value() {};

	inline const T& GetData() const { return data_; }
	inline void SetData(T data) { data_ = data; }
private:
	T data_;
};

// template class with two types
template<class T1 = int, class T2 = int>
class PairValue
{
public:
	// constructor that works for 0 or 1 or both arguments
	PairValue(const T1& first = T1(), const T2& second = T2()) : first_(first), second_(second) { cout << __LINE__ << endl; };
	// copy constructor
	PairValue(const PairValue<T1, T2>& pair_value) : first_(pair_value.first_), second_(pair_value.second_) { cout << __LINE__ << endl; };

	// operator overloads
	void operator = (const PairValue<T1, T2>& pair_value) { first_ = pair_value.first_; second_ = pair_value.second_; cout << __LINE__ << endl; }
	bool operator == (const PairValue<T1, T2>& pair_value) { return first_ == pair_value.first_ && second_ == pair_value.second_; }
	bool operator != (const PairValue<T1, T2>& pair_value) { return first_ != pair_value.first_ || second_ != pair_value.second_; }
	bool operator > (const PairValue<T1, T2>& pair_value) { return first_ > pair_value.first_ && second_ > pair_value.second_; }
	bool operator < (const PairValue<T1, T2>& pair_value) { return first_ < pair_value.first_ && second_ < pair_value.second_; }
	bool operator >= (const PairValue<T1, T2>& pair_value) { return first_ >= pair_value.first_ && second_ >= pair_value.second_; }
	bool operator <= (const PairValue<T1, T2>& pair_value) { return first_ <= pair_value.first_ && second_ <= pair_value.second_; }

	void Swap(PairValue<T1, T2>& pair_value)
	{
		PairValue<T1, T2> swap = pair_value;
		pair_value.first_ = first_;
		pair_value.second_ = second_;
		first_ = swap.first_;
		second_ = swap.second_;
	}

	T1 first_;
	T2 second_;
};

// template with non-type arguments
template<class T = int, int size_ = 100>
class Stack
{
public:
	// default constructor
	Stack() : data_(new T[size_]) { cout << __LINE__ << endl; };
	// copy constructor
	Stack(const Stack<T>& stack) : data_(new T[size_])
	{
		for(auto i = 0; i < size_; ++i)
		{
			data_[i] = stack[i];
		}
	}

	/*~Stack()
	{
		delete[] data_;
	}*/

protected:
	T data_[size_];
};

int main()
{
	cout << "\n********** Template Class Test **********\n";

	// simple template class
	Value<int> value_int;
	cout << "Value<int>:" << value_int.GetData() << endl;
	value_int.SetData(20);
	cout << "Value<int>:" << value_int.GetData() << endl;

	Value<string> value_string;
	cout << "Value<string>:" << value_string.GetData() << endl;
	value_string.SetData("testing templates...1234");
	cout << "Value<string>:" << value_string.GetData() << endl;

	cout << "\n~~~~~~~~~~~~~~~~~~~~\n";

	// template class with two types
	PairValue<int, double> pair_value_1;
	cout << "pair_value_1 - first_:" << pair_value_1.first_ << "  second_:" << pair_value_1.second_ << endl;

	PairValue<int, double> pair_value_2 = {10, 12.34};
	cout << "pair_value_2 - first_:" << pair_value_2.first_ << "  second_:" << pair_value_2.second_ << endl;

	pair_value_1 = pair_value_2;
	cout << "pair_value_1 - first_:" << pair_value_1.first_ << "  second_:" << pair_value_1.second_ << endl;

	PairValue<int, double> pair_value_3 = {11, 12.34};
	cout << "pair_value_3 - first_:" << pair_value_3.first_ << "  second_:" << pair_value_3.second_ << endl;

	cout << "\nRelational Operators\n";
	cout << "pair_value_1 == pair_value_2:" << (pair_value_1 == pair_value_2) << endl;
	cout << "pair_value_1 != pair_value_3:" << (pair_value_1 != pair_value_3) << endl;
	cout << "pair_value_1 > pair_value_3:" << (pair_value_1 > pair_value_3) << endl;
	cout << "pair_value_1 < pair_value_3:" << (pair_value_1 < pair_value_3) << endl;
	cout << "pair_value_1 >= pair_value_3:" << (pair_value_1 >= pair_value_3) << endl;
	cout << "pair_value_1 <= pair_value_3:" << (pair_value_1 <= pair_value_3) << endl;

	cout << "" << endl;
	PairValue<int, double> pair_value_4;
	cout << "pair_value_4 - first_:" << pair_value_4.first_ << "  second_:" << pair_value_4.second_ << endl;

	cout << "\nSwap\n";
	pair_value_4.Swap(pair_value_1);
	cout << "pair_value_1 - first_:" << pair_value_1.first_ << "  second_:" << pair_value_1.second_ << endl;
	cout << "pair_value_4 - first_:" << pair_value_4.first_ << "  second_:" << pair_value_4.second_ << endl;

	cout << "\n~~~~~~~~~~~~~~~~~~~~\n";

	Stack<> default_stack;

	cout << "" << endl;
	return 0;
}
