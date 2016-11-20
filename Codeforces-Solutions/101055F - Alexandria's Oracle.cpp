#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; cin >> q;
	while(q--){
		string str; cin >> str;
		int idx;
		for(idx = 0; idx < str.size() && str[idx] != '!'; idx++);
		int k = str.size() - idx;
		int n = atoi(str.substr(0, idx).c_str());
		long long ans = 1;
		while(n > 0){
			ans *= n;
			n -= k;
		}
		cout << ans << endl;
	}
	return 0;
}
