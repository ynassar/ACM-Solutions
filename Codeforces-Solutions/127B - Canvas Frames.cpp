#include <bits/stdc++.h>
using namespace std;

int a[101], f[101];
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		f[a[i]] ++;
	}
	int ans = 0;
	for(int i = 1; i <= 100; i ++){
		if(f[i] % 2 == 0){
			ans += f[i];
		}
		else{
			ans += f[i] - 1;
		}
	}
	cout << ans / 4 << endl;
	return 0;
}
