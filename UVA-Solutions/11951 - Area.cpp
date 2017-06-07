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

const long long inf = 100000000;

long long n,m,k;
long long arr[500][500];
long long cumul[500][500];
void build_cumul(){
	for(long long i = 0; i < n; i ++){
		for(long long j = 0; j < m; j ++){
			if(i == 0 && j == 0){
				cumul[i][j] = arr[i][j];
			}
			else{
				long long top, left, small;
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
long long get_sum(long long si, long long ei, long long sj, long long ej){
	long long top, left, small, big;
	long long large = cumul[ei][ej];
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
	long long t; cin >> t;
	long long case_num = 1;
	while(t--){
		cin >> n >> m >> k; 
		for(long long i = 0; i < n; i ++){
			for(long long j = 0; j < m; j ++){
				cin >> arr[i][j];
			}
		}
		build_cumul();
		long long ans = LLONG_MIN;
		long long best_cost;
		bool found_plot = false;
		for(long long si = 0; si < n; si ++){
			for(long long sj = 0; sj < m; sj ++){
				for(long long ei = si; ei < n; ei ++){
					for(long long ej = sj; ej < m; ej ++){
						long long cost = get_sum(si, ei, sj, ej);
						if(cost <= k){
							found_plot = true;
							long long plot_size = (ei - si + 1) * (ej - sj + 1);
							if(plot_size > ans || plot_size == ans && cost < best_cost){
								ans = plot_size;
								best_cost = cost;
							}
						}
					}
				}
			}
		}
		if(found_plot)
			cout << "Case #" << case_num ++ << ": " << ans << " " << best_cost << endl;
		else
			cout << "Case #" << case_num ++ << ": " << 0 << " " << 0 << endl;
	}
}
