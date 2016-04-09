/*
	Solution Explanation: 
	To create the lucky number with the required sum of digits x, you need n 4's and m 7's such that
	n*4 + m*7 = x. Looping over all possible values of m, you can obtain values for n = (x - m*7)/4 
	only if (x - m * 7) is divisible by 4. Out of all values of n and m, the minimum lucky number will have the
	smallest total number of digits, i.e. the smallest n + m. The lucky number is impossible to construct if for all values
	of m, there is no suitable value of n.
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int requiredSumOfDigits;
	cin >> requiredSumOfDigits;
	int numberOfFours;
	int minimumNumberOfFours = -1;
	int minimumNumberOfSevens = -1;
	int minimumNumberOfDigits = INT_MAX;
	for(int numberOfSevens = 0; numberOfSevens <= (requiredSumOfDigits / 7); numberOfSevens ++)
	{
		if((requiredSumOfDigits - 7 * numberOfSevens) % 4 == 0)
		{
			numberOfFours = (requiredSumOfDigits - 7 * numberOfSevens) / 4;
			if(numberOfFours + numberOfSevens <= minimumNumberOfDigits)
			{
				minimumNumberOfDigits = numberOfFours + numberOfSevens;
				minimumNumberOfFours = numberOfFours;
				minimumNumberOfSevens = numberOfSevens;
			}
		}
	}

	if(minimumNumberOfFours == -1)
	{
		cout << -1 << endl;
	}
	else
	{
		for(int i = 0; i < minimumNumberOfFours; i ++)
			cout << '4';
		for(int i = 0; i < minimumNumberOfSevens; i ++)
			cout << '7';
		cout << endl;
	}

}
