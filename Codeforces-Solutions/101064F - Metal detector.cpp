#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("Text.txt", "r", stdin);
#endif
	int t; cin >> t;
	while (t--)
	{
		int n, i; cin >> n >> i;
		int ans = 0;
		bool niae = true;
		while (true)
		{
			if (niae) {
				if (n % 2 == 1)
					niae = !niae;
				if (i % 2 == 1) {
					cout << ans + (i + 1) / 2 << endl;
					break;
				}
				else
				{
					ans += (n + 1) / 2;
					n /= 2;
					i /= 2;
				}
			}
			else
			{
				if (n % 2 == 1)
					niae = !niae;
				if (i % 2 == 0) {
					cout << ans + (i) / 2 << endl;
					break;
				}
				else {
					ans += n / 2;
					n = (n + 1) / 2;
					i = (i + 1) / 2;
				}
			}
		}
	}
	return 0;
}
