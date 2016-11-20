#include <bits/stdc++.h>
using namespace std;


int main() {
	int t; cin >> t;
	for(int i = 0; i < t; i ++){
		int h, w, d; cin >> h >> w >> d;
		int n = (h - 1) / (w - 1);
		int finalRow;
		int remainingNazlat = h - 1 - (n * (w - 1));
		if(n % 2 == 1){
			finalRow = w - remainingNazlat;
		}
		else{
			finalRow = 1 + remainingNazlat;
		}
		if(finalRow == d)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
