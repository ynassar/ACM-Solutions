#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	//freopen("Text.txt", "r", stdin);
	int n = 2;
	int N; cin >> N;
	long long num = N;
	long long denom = N;
	long long runningN = N;
	double pr = 1;
	for (n; n <= 1000; n++) {
		pr *= (1.0 * --runningN) / N;
		if (1 - pr > 0.5)
			cout << n << endl, exit(0);
	}
	return 0;
}
