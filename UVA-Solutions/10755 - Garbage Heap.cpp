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

long long a, b, c;
long long garbage[30][30][30];
long long cumul[30][30][30];
long long two_d_cumul[30][30][30];
void build_cumul(){
	for(int k = 0; k < c; k ++){
		for(int i = 0; i < a; i ++){
			for(int j = 0; j < b; j ++){
				if(i == 0 && j == 0){
					two_d_cumul[i][j][k] = garbage[i][j][k];
				}
				else{
					long long top;
					if(i == 0)
						top = 0;
					else 
						top = two_d_cumul[i - 1][j][k];
					long long left;
					if(j == 0)
						left = 0;
					else
						left = two_d_cumul[i][j - 1][k];

					long long small;
					if(i == 0 || j == 0)
						small = 0;
					else
						small = two_d_cumul[i - 1][j -1][k];
					two_d_cumul[i][j][k] = top + left + garbage[i][j][k] - small;
						//two_d_cumul[i - 1][j][k] + two_d_cumul[i][j - 1][k] + garbage[i][j][k] - two_d_cumul[i - 1][j - 1][k];
				}
			}
		}
	}
	for(int k = 0; k < c; k ++){
		for(int i = 0; i < a; i ++){
			for(int j = 0; j < b; j ++){
				if(k == 0){
					cumul[i][j][k] = two_d_cumul[i][j][k];
				}
				else{
					cumul[i][j][k] = cumul[i][j][k-1] + two_d_cumul[i][j][k];
				}
			}
		}
	}
}
long long garbage_sum(int sx, int ex, int sy, int ey, int sz, int ez){
	long long req_area_bottom;
	if(sz == 0){
		req_area_bottom = 0;
	}
	else{
		long long big = cumul[ex][ey][sz-1];
		long long small = (sx == 0 || sy == 0) ? 0 : cumul[sx - 1][sy - 1][sz - 1];
		long long left = (sx == 0) ? 0 : cumul[sx - 1][ey][sz - 1];
		long long top = (sy == 0) ? 0 : cumul[ex][sy - 1][sz - 1];
		req_area_bottom = big - left - top + small;
	}
	long long req_area_top;
	long long big = cumul[ex][ey][ez];
	long long small = (sx == 0 || sy == 0) ? 0 : cumul[sx - 1][sy - 1][ez];
	long long left = (sx == 0) ? 0 : cumul[sx - 1][ey][ez];
	long long top = (sy == 0) ? 0 : cumul[ex][sy - 1][ez];
	req_area_top = big - left - top + small;

	return req_area_top - req_area_bottom;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "r+", stdout);
#endif
	int t; cin >> t;
	int case_num = 1;
	while(t--){
		if(case_num != 1)
			cout << endl;
		cin >> a >> b >> c;
		
		for(int i = 0; i < a; i ++){
			for(int j = 0; j < b; j ++){
				for(int k = 0; k < c; k ++){
					cin >> garbage[i][j][k];
				}
			}
		}
		build_cumul();
		long long ans = LLONG_MIN;
		for(int x_s = 0; x_s < a; x_s ++){
			for(int x_e = x_s; x_e < a; x_e ++){
				for(int y_s = 0; y_s < b; y_s ++){
					for(int y_e = y_s; y_e < b; y_e++){
						for(int z_s = 0; z_s < c; z_s ++){
							for(int z_e = z_s; z_e < c; z_e ++){
								ans = max(ans, garbage_sum(x_s, x_e, y_s, y_e, z_s, z_e));
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
		case_num ++;
	}
}
