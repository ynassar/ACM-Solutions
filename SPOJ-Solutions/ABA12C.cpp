#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;



int prices[int(1e3)];
int dp[1005][1005];
int rec(int n, int k)
{
	if (k < 0)
		return 1e9;
	if (k == 0)
		return 0;
	if (n == 0)
		return 1e9;
	if (dp[n][k] != -1)
		return dp[n][k];
	int ans = 1e9;
	for (int i = 1; i <= k; i++)
	{
		if (prices[i] == -1) continue;
		ans = min(ans, prices[i] + rec(n - 1, k - i));
	}
	return dp[n][k] = ans;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t; cin >> t;
	while (t--){
		memset(dp, -1, sizeof dp);
		int n, k; cin >> n >> k;
		for (int i = 1; i <= k; i++)
			cin >> prices[i];
		int ans = rec(n, k);
		if (ans >= 1e9)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
