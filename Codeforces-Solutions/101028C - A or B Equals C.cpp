#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string a, c; cin >> a >> c;
		int ways = 1;
		for(int i = 0; i < n && ways; i ++){
			if(a[i] == '1' && c[i] == '0'){
				ways = 0;
			}
			else if(a[i] == '1' && c[i] == '1'){
				ways = (ways * 2 ) % 1000000007;
			}
		}
		if(!ways){
			cout << "IMPOSSIBLE" << endl;
		}
		else{
			cout << ways << endl;
		}
	}
	return 0;
}
