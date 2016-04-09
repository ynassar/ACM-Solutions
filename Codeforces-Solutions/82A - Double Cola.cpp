#include <iostream>
#include <string>
using namespace std;

int logBaseTwo(int n);
int twoPower(int n);
int main()
{
	string personNumber[5] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
	int numberInQueue; cin >> numberInQueue;
	numberInQueue --;
	int rotationNumber = logBaseTwo((numberInQueue + 5)/ 5) + 1;
	int startOfRotation = 5 * twoPower(rotationNumber - 1) - 5;
	cout << personNumber[(numberInQueue - startOfRotation) / twoPower(rotationNumber-1)] << endl;
}
int logBaseTwo(int n)
{
	int log = 0;
	while(n != 0)
	{
		n /= 2;
		log ++;
	}
	return log - 1;
}
int twoPower(int n)
{
	int answer = 1;
	for(int i = 0; i < n; i ++)
		answer *= 2;
	return answer;
}
