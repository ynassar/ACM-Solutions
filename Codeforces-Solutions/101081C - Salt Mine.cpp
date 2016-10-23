#include <iostream>
#include<cmath>
#include<algorithm>
#include <string>
#include<vector>
#include <cstring>
using namespace std;
#define MAX int(1e5 + 5)

int main()
{
#ifndef ONLINE_JUDGE
	freopen("Text.txt", "r", stdin);
#endif // !ONLINE_JUDGE

	int t; cin >> t;
	while (t--)
	{
		long long n, x0; cin >> n >> x0;
		long long a[16];
		for (int i = 0; i <= n; i++)
			cin >> a[i];
		long long q[16];
		q[n - 1] = a[n];
		for (int i = n - 2; i >= 0; i--)
			q[i] = a[i + 1] + x0 * q[i + 1];
		long long r = a[0] + x0 * q[0];
		cout << r << endl;
		for (int i = 0; i < n; i++)
			cout << q[i] << " \n"[i == n - 1];
	}
}

