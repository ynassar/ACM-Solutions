#include <bits/stdc++.h>
using namespace std;

char plane[101][101];
void fill(int riStart, int ciStart, int riEnd, int ciEnd, char color){
	for(int i = riStart; i <= riEnd; i ++)
		for(int j = ciStart; j <= ciEnd; j ++)
			plane[i][j] = color;
}
int main() {
	int t; cin >> t;
	while(t--){
		int r, c, n; cin >> r >> c >> n;
		fill(1,1, r, c, '.');
		for(int i = 0; i < n; i ++){
			char color;
			int riStart, ciStart, riEnd, ciEnd; cin >> riStart >> ciStart >> riEnd >> ciEnd >> color;
			fill(riStart, ciStart, riEnd, ciEnd, color);
		}
		for(int i = 1; i <= r; i ++){
			for(int j = 1; j <= c; j ++)
				cout << plane[i][j];
			cout << endl;
		}
	}
	return 0;
}
