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
int arr[500][500];
int cumul[500][500];
void duplicate_array(){
	for(int i = 0; i < 2*n; i ++){
		for(int j = 0; j < 2*n; j ++){
			int corr_i = (i >= n) ? i - n : i;
			int corr_j = (j >= n) ? j - n : j;
			arr[i][j] = arr[corr_i][corr_j];
		}
	}
	n *= 2;
}
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
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				cin >> arr[i][j];
			}
		}
		duplicate_array();
		build_cumul();
		n /= 2;
		int ans = INT_MIN;
		for(int si = 0; si < n; si ++){
			for(int sj = 0; sj < n; sj ++){
				for(int ei = si; ei < si + n; ei ++){
					for(int ej = sj; ej < sj + n; ej ++){
						ans = max(ans, get_sum(si,ei,sj,ej));
					}
				}
			}
		}
		cout << ans << endl;
	}
}
