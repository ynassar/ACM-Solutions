#include <iostream>
using namespace std;

const int rows = 5, columns = 5;

int distanceBetween(int rowOne, int columnOne, int rowTwo, int columnTwo);
int main()
{
	int matrix[rows][columns];
	int centerRow = rows / 2;
	int centerColumn = columns / 2;
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			cin >> matrix[i][j];
		}
	}
	int rowWithOne, columnWithOne;
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < columns; ++j)
		{
			if(matrix[i][j] == 1)
			{
				rowWithOne = i;
				columnWithOne = j;
			}
		}
	}
	cout << distanceBetween(centerRow, centerColumn, rowWithOne, columnWithOne) << endl;
}

int distanceBetween(int rowOne, int columnOne, int rowTwo, int columnTwo)
{
	return abs(rowOne - rowTwo) + abs(columnOne - columnTwo);
}
