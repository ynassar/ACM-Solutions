
#include <bits/stdc++.h>
using namespace std;

int main() {
	string str; cin >> str;
	int ans = 0;
	char curChar = 'a';
	for(int i = 0; i < str.size(); i ++){
		ans += min(abs(curChar - str[i]), 26 - abs(curChar - str[i]));
		curChar = str[i];
	}
	cout << ans << endl;
	return 0;
}
