#include <bits/stdc++.h>
using namespace std;

int d[105];
int main() {
	int n; cin >> n;
	for(int i = 1; i < n; i ++)
		cin >> d[i];
	int a, b; cin >> a >> b;
	int sum = 0;
	for(int i = a; i < b; i ++)
		sum += d[i];
	cout << sum << endl;
	return 0;
}
