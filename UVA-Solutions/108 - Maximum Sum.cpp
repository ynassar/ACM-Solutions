#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <sstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <iomanip>
using namespace std;

const int inf = 100000000;

int n;
int arr[200][200];
int cumul[200][200];
void build_cumul(){
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			if(i == 0 && j == 0){
				cumul[i][j] = arr[i][j];
			}
			else{
				int top, left, small;
				if(i == 0)
					top = 0;
				else 
					top = cumul[i - 1][j];
				if(j == 0)
					left = 0;
				else
					left = cumul[i][j - 1];
				if(i == 0 || j == 0)
					small = 0;
				else
					small = cumul[i - 1][j -1];
				cumul[i][j] = top + left - small + arr[i][j];
			}
		}
	}
}
int get_sum(int si, int ei, int sj, int ej){
	int top, left, small, big;
	int large = cumul[ei][ej];
	if(si == 0)
		top = 0;
	else
		top = cumul[si - 1][ej];
	if(sj == 0)
		left = 0;
	else
		left = cumul[ei][sj - 1];
	if(si == 0 || sj == 0)
		small = 0;
	else
		small = cumul[si - 1][sj - 1];

	return large - left - top + small;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "r+", stdout);
#endif
	cin >> n;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			cin >> arr[i][j];
		}
	}
	build_cumul();
	int ans = INT_MIN;
	for(int si = 0; si < n; si ++){
		for(int sj = 0; sj < n; sj ++){
			for(int ei = si; ei < n; ei ++){
				for(int ej = sj; ej < n; ej ++){
					ans = max(ans, get_sum(si, ei, sj, ej));
				}
			}
		}
	}
	cout << ans << endl;
}
