#include <bits/stdc++.h>
using namespace std;

int markedByRoger[100005];
int markedByDavid[100005];
int main() {
	int t; cin >> t;
	while(t--){
		memset(markedByRoger, 0, sizeof markedByRoger);
		memset(markedByDavid, 0, sizeof markedByDavid);
		int n, d, r; cin >> n >> d >> r;
		int roger = 0, david = 0, time = 0;
		while(!markedByRoger[roger]){
			markedByRoger[roger] = time++;
			roger += r;
			roger %= n;
		}
		time = 0;
		while(!markedByDavid[david]){
			markedByDavid[david] = time++;
			david += d;
			david %= n;
		}
		int minT = INT_MAX;
		for(int i = 0; i < n; i ++){
			if(markedByRoger[i] && markedByDavid[i]){
				minT = min(minT, max(markedByRoger[i], markedByDavid[i]));
			}
		}
		cout << minT << endl;
	}
	return 0;
}
