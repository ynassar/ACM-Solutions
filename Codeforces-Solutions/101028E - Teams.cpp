#include <bits/stdc++.h>
using namespace std;

int a[1001];
int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i ++){
		int n; cin >> n;
		int d = 0;
		int sum = 0;
		for(int j = 0; j < n; j ++){
			cin >> a[j];
			d = gcd(d, a[j]);
			sum += a[j];
		}
		
		cout << d << " " << sum / d << endl;
		
	}
	return 0;
}
