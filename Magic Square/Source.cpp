#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	fstream f;
	f.open("input.txt", ios::in);
	int size;
	int temp;
	f >> size;
	vector < vector <int>> matrix;
	int error_lines = 0;
	vector <int> lines;

	//intialize matrix
	for (int i = 0; i < size; i++)
	{
		matrix.push_back(vector<int>());
		for (int j = 0; j < size; j++)
		{
			f >> temp;
			matrix[i].push_back(temp);
		}
	}

	int DiagonalSum = 0;
	//calculate diagonal sum
	for (int col = 0; col < size; col++)
	{
		DiagonalSum += matrix[col][col];

	}

	//calculate rows 
	for (int row = 0; row < size; row++) {
		int rowSum = 0;
		for (int col = 0; col < size; col++) {
			rowSum += matrix[row][col];
		}
		if (rowSum != DiagonalSum)
		{
			lines.push_back(row + 1);
			error_lines++;
		}
		
	}
	
	//calculate columns
	for (int col = 0; col < size; col++) {
		int colSum = 0;
		for (int row = 0; row < size; row++) {
			colSum += matrix[row][col];
		}
		if (colSum != DiagonalSum)
		{
			lines.push_back((col+1)*(-1));
			error_lines++;
		}

	}

	//calculate antidiagonals
	int antiDiagonalSum = 0;
	//calculate diagonal sum
	int col = size-1;
	for (int row = 0; row < size; row++)
	{
		antiDiagonalSum += matrix[row][col];
		col--;
	}
	if (antiDiagonalSum != DiagonalSum)
	{
		lines.push_back(0);
		error_lines++;
	}


	cout << error_lines << endl;
	for (int i = 0; i < lines.size(); i++)
	{
		cout<< lines[i] << endl;
	}


	system("pause");
}