#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> numbers = {3,3};
	int GCD = 1;
	sort(numbers.begin(), numbers.end());
	vector <int> factors;
	vector <int> minimum;
	//put all factors in 1 array
	for (int i = 0; i < numbers.size(); i++)
	{
		for (int j = 1; j <= numbers[i]; j++)
		{
			if (numbers[i] % j == 0)
			{
				factors.push_back(j);
			}
		}
	}
	//sort the factors 
	sort(factors.begin(), factors.end());
	for (int i = 0; i < factors.size(); i++)
	{
		cout << factors[i] << " ";
	}
	cout << endl;
	int count = 1; //# of duplicates
	int number_size = numbers.size(); //number of inputs

	vector <int> GCD_list;
	for (int i = 0; i < factors.size()-1; i++)
	{
		if (factors[i] == factors[i + 1])
		{
			count++;
			if ((i+1) == factors.size()-1)
			{
				if (count == number_size)
				{
					GCD_list.push_back(factors[i]);
					count = 1;
				}
			}
			
		}
		else if (count == number_size)
		{
			GCD_list.push_back(factors[i]);
			count = 1;
		}
	}
	cout << *(GCD_list.end() - 1) << endl;
	system("pause");
}