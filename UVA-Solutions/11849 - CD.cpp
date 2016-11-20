#include <bits/stdc++.h>
using namespace std;

map<int, int> all;

int main(){
	int n, m;
	while(cin >> n >> m, n != 0 && m != 0){
		all.clear();
		for(int i = 0; i < n; i ++)
		{
			int t; cin >> t;
			all[t] ++;
		}
		for(int i = 0; i < m; i ++){
			int t; cin >> t;
			all[t]++;
		}
		int ans = 0;
		for(auto it:all){
			ans += it.second / 2;
		}
		cout << ans << endl;
	}
}
