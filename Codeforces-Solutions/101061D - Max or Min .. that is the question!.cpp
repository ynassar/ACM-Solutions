#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--){
		int arr[5];
		for(int i = 0; i < 5; i ++){
			cin >> arr[i];
		}
		sort(arr, arr + 5);
		cout << arr[4] * arr[3] << endl;
	}
	return 0;
}
