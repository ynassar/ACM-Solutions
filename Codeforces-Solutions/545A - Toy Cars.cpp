#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int matrix[101][101];
	vector<int> uncollidedCars;
	int numberOfCars; cin >> numberOfCars;

	for(int i = 1; i <= numberOfCars; i ++)
		for(int j = 1; j <= numberOfCars; j ++)
			cin >> matrix[i][j];

	for(int i = 1; i <= numberOfCars; i ++)
	{
		bool ithCarTurnedOver = false;
		for(int j = 1; j <= numberOfCars && !ithCarTurnedOver; j ++)
		{
			if(matrix[i][j] == 1 || matrix[i][j] == 3)
				ithCarTurnedOver = true;
		}
		if(!ithCarTurnedOver)
			uncollidedCars.push_back(i);
	}
	cout << uncollidedCars.size() << endl;
	for(int i = 0; i < uncollidedCars.size(); i ++)
		cout << uncollidedCars[i] << " \n"[i == uncollidedCars.size() - 1];
}
