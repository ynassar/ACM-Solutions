#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

long long paints[long long(1e6)];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	long long n; cin >> n;
	long long minimum = LLONG_MAX;
	long long lowestIdx;
	for(long long i = 0; i < n; i ++){
		cin >>  paints[i];
		if(paints[i] < minimum)
		{
			minimum = paints[i];
			lowestIdx = i;
		}
	}
	long long maxDist = 0;
	long long curDist = 0;
	long long i = lowestIdx + 1;
	i = i % n;
	while(i != lowestIdx){
		curDist ++;
		if(paints[i] == minimum)
		{
			curDist = 0;
		}
		maxDist = max(curDist, maxDist);
		i ++;
		i %= n;
	}
 	cout << minimum * n + maxDist << endl;
}
