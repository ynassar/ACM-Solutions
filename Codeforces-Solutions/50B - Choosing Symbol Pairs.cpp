#include <bits/stdc++.h>
using namespace std;

map<char, int> occ;
int main() {
	string str; cin >> str;
	for(int i = 0; i < str.size(); i ++){
		occ[str[i]]++;
	}
	long long ans = 0;
	for(int i = 0; i < str.size(); i ++){
		ans += occ[str[i]];
	}
	cout << ans << endl;
	return 0;
}
