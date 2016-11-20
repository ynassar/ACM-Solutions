#include <bits/stdc++.h>
using namespace std;

int malesThatCanCome[400];
int femalesThatCanCome[400];
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i ++){
		char c; int a, b; cin >> c >> a >> b;
		if(c == 'M'){
			for(int j = a; j <= b; j ++){
				malesThatCanCome[j] ++;
			}
		}
		else if(c == 'F'){
			for(int j = a; j <= b; j ++){
				femalesThatCanCome[j] ++;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= 366; i ++){
		ans = max(ans, 2 * min(malesThatCanCome[i], femalesThatCanCome[i]));
	}
	cout << ans << endl;
	return 0;
}
