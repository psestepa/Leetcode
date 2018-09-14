#include <iostream>
#include "Header.h"
using namespace std;

int main(int argc, char* argv[])
{
	Solution Vyda;
	vector<int> input = { 2, 7, 11, 15 };
	int target = 22;
	Vyda.twoSum(input, target);
	Vyda.print();

	system("pause");
}

