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
