#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	long long n; cin >> n;
	long long numSequence;
	for(long long i = 1; i <= n + 1; i ++)
	{
		if(i * (i + 1) / 2 >= n)
		{
			numSequence = i; break;
		}
	}
	long long startOfSequence = ((numSequence * (numSequence + 1)) / 2) - (numSequence - 1);
	cout << n % startOfSequence + 1<< endl;
}
