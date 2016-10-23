#include <bits/stdc++.h>
using namespace std;

double dp[560][3400];
bool hit[560][3400];
double getP(int n, int k){
	if(n == 0)
		return k == 0;
	if(n > k)
		return 0;
	if(hit[n][k])
		return dp[n][k];
	double ans = 0;
	for(int i = 1; i <= min(6, k); i ++){
		ans += getP(n - 1, k - i) / 6.0;
	}
	hit[n][k] = true;
	return dp[n][k] = ans;
}
int main() {
	int t; cin >> t;
	int n, k;
	while(cin >> n >> k){
		if(n > 545 || k > 3358)
			cout << 0 << endl;
		else{
			memset(hit, false, sizeof hit);
			cout << int( getP(n, k) * 100) << endl;
		}
	}
	return 0;
}
