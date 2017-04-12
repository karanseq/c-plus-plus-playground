#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

void GetIntListFromString(const string& input, vector<int>& output)
{
	string local_input = input;
	if(local_input == "")
		return;

	local_input.erase(remove(local_input.begin(), local_input.end(), ' '), local_input.end());

	stringstream ss(local_input);
	int i;
	while (ss >> i)
	{
		output.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
	}
}

void GetStringFromIntList(const vector<int>& input, string& output)
{
	int input_size = input.size();
	if(input_size <= 0)
	{
		return;
	}

	stringstream converter;
	converter << input[0];
	output = converter.str();

	for(int i = 1; i < input_size; ++i)
	{
		converter.str("");
		converter << input[i];
		output += "," + converter.str();
	}
}

int main()
{
	const string input_1 = "5,4, 3, 2,1";
	vector<int> output_1;
	output_1.clear();
	GetIntListFromString(input_1, output_1);

	cout << "\nPrinting output1:\n";
	for(auto o : output_1)
	{
		cout << o << "  ";
	}

	abort();

	string output_2 = "";
	GetStringFromIntList(output_1, output_2);
	cout << "\nPrinting output2:\n";
	cout << output_2 << endl;

	return 0;
}
