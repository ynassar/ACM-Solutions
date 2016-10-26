#include <bits/stdc++.h>
using namespace std;

int main() {
	int tens = 1;
	int a, b; cin >> a >> b;
	int ans = 0;
	while(a || b){
		ans += tens * abs(a % 10 - b % 10);
		tens *= 10;
		a /= 10; b /= 10;
	}
	cout << ans << endl;
	return 0;
}
