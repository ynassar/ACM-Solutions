#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
		int n, r; cin >> n >> r;
		r -= 1500;
		for(int i = 0; i < n; i ++){
			int temp; cin >> temp;
			r -= temp;
		}
		cout << ((r) ? "Bug" : "Correct") << endl;
	}
	return 0;
}
