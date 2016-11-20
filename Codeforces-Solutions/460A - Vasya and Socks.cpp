#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	int dayNumber = 0;
	while(n){
		n --;
		dayNumber ++;
		if(dayNumber % m == 0)
			n ++;
	}
	cout << dayNumber << endl;
	return 0;
}
