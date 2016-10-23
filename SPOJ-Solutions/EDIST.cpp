#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string a, b;

int dp[2005][2005];
int edist(int i, int j)
{
	if (i == a.length())
		return (b.length() - j);
	if (j == b.length())
		return (a.length() - i);
	if (dp[i][j] != -1)
		return dp[i][j];
	if (a[i] == b[j])
		return dp[i][j] = edist(i + 1, j + 1);
	return dp[i][j] = 1 + min(edist(i + 1, j + 1), min(edist(i, j + 1), edist(i + 1, j)));
}
int main()
{
	int t; cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof dp);
		cin >> a >> b;
		cout << edist(0, 0) << endl;
	}
}
