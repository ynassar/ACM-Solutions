#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
 
 
bool taken[4000];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n; cin >> n;
	int temp;
	for(int i = 0; i < n; i ++){
		cin >> temp;
		taken[temp] = true;
	}
	for(int i = 1; i < 4000; i ++)
	{
		if(!taken[i])
		{
			cout << i << endl; exit(0);
		}
	}
}
