/*
	Solution Explanation:
	Combine all bars of equal height. Keep track of the heights that have already been combined, either by deleting them 
	from the vector/array, or by keeping another array that records whether a given height has been used. Combining n bars
	reduces the number of towers by n-1.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int NumberOfBarsWithHeight(int height, const vector<int>& barHeights)
{
	int numberOfBarsWithHeight = 0;
	for(int i = 0; i < barHeights.size(); i ++)
		if(height == barHeights[i])
			numberOfBarsWithHeight ++;
	return numberOfBarsWithHeight;
}
int main()
{
	int numberOfBars;
	cin >> numberOfBars;
	vector<int> barHeights;
	barHeights.resize(numberOfBars);
	vector<bool> heightUsed(1001, false);
	for(int i = 0; i < numberOfBars; i++)
	cin >> barHeights[i];
	int numberOfTowers = numberOfBars, maximumHeight = 1;
	for(int i = 0; i < numberOfBars; i++)
	{
		int numberOfBarsWithHeight = NumberOfBarsWithHeight(barHeights[i], barHeights);
		if (numberOfBarsWithHeight >= 2 && !heightUsed[barHeights[i]])
		{
			numberOfTowers -= (numberOfBarsWithHeight - 1);
			heightUsed[barHeights[i]] = true;
			maximumHeight = max(maximumHeight, numberOfBarsWithHeight);
		}
	}
	cout << maximumHeight << " " << numberOfTowers;
}
