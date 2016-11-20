#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<long long, long long> mp;
long long a[100005];
long long powersOfTwo[63];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], mp[a[i]]++;
	long long ans = 0;
	powersOfTwo[0] = 1;
	for (int i = 1; i < 63; i++)
		powersOfTwo[i] = powersOfTwo[i - 1] * 2;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < 63; j++){
			if (mp.count(powersOfTwo[j] - a[i]))
				ans += mp[powersOfTwo[j] - a[i]];
			if (a[i] == powersOfTwo[j] - a[i])
				ans--;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
