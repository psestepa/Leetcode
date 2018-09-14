#ifndef HEADER_H
#define HEADER_H
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	Solution();
	~Solution();
	vector<int> twoSum(vector<int>&, int);
	void print();
private:
	vector <int> result;
};

Solution::Solution()
{
}

Solution::~Solution()
{
}

vector<int> Solution::twoSum(vector<int>& nums, int target )
{
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i; j < nums.size(); j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
}
void Solution::print()
{
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i]<< " ";
	}
	cout << endl;	
}

#endif