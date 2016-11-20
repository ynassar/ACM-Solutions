#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	int ans = 0;
	for(int i = 0; i < n && s[i] == '<'; i++)
		ans ++;
		
	for(int i = n - 1; i >= 0 && s[i] == '>'; i --)
		ans ++;
	
	cout << ans << endl;
	
}
