#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s;
int dp[207][207][207];
int rock(int index, int sw, int so)
{
	int& ref = dp[index][sw][so];
	if (index == n)
	{
		if (sw > so)
			return sw + so;
		else
			return 0;
	}
	if (ref != -1)
		return ref;
	if (sw <= so)
		return ref = max(rock(index + 1, 0, 0) 
		,rock(index + 1, s[index] - '0' + sw, !(s[index] - '0') + so));
	return ref = max(sw + so + rock(index + 1, s[index] - '0', !(s[index] - '0')),
		rock(index + 1, s[index] - '0' + sw, !(s[index] - '0') + so));
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> n >> s;
		cout << rock(0, 0, 0) << endl;
	}
}
