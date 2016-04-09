/*
	Solution Explanation:
		The number of swaps required to move the 1 from any row a to any other row b is the absolute value of (a - b).
		The number of swaps required to move the 1 from any column c to any other column d is the absolute value of (c - d).
		Thus, the total number of swaps required to move the 1 from row i and column j to row x and column y is
		|i-x| + |j-y|. The problem asks for the miniumum number of swaps required to move the 1 from it's current position
		to the center of the matrix (which is at row 2 and column 2). To do this we first identify the row i where the 1 is,
		and the column j where the 1 is. Our answer is then |i - 2| + |j - 2|.
*/
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
