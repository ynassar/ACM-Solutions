#include <bits/stdc++.h>
using namespace std;

long long a[200005], b[200005], c[2000005], d[2000005];
long long n,m,k,x,s;
long long minPot(long long remMana){
	return c[upper_bound(d, d + k, remMana) - d - 1];
}
int main() {
	cin >> n >> m >> k >> x >> s;
	for(int i = 0; i < m; i ++)
		cin >> a[i];
	for(int i = 0; i < m; i ++)
		cin >> b[i];
	for(int i = 0; i < k; i ++)
		cin >> c[i];
	for(int i = 0; i < k; i ++)
		cin >> d[i];
	
	long long ans = (n - minPot(s)) * x;
	for(int i = 0; i < m; i ++){
		long long rMana = s - b[i];
		if(rMana >= 0){
			long long potionCost = a[i];
			long long potsRemaining = n - minPot(rMana);
			long long cost = potsRemaining * potionCost;
			ans = min(ans, cost);
		}
	}
	cout << ans << endl;
	return 0;
}
