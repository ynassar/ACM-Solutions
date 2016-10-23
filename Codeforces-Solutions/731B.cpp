#include <bits/stdc++.h>
using namespace std;

int a[int(1e6)];
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	for(int i = 0; i < n - 1; i ++){
		if(a[i] % 2 == 1){
			if(a[i + 1] == 0){
				cout << "NO" << endl;
				return 0;
			}
			a[i + 1] --;
		}
	}
	cout << ((a[n - 1] % 2) ? "NO" : "YES") << endl;
	return 0;
}
