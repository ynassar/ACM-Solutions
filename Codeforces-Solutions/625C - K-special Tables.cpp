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
#include <set>
#include <stack>
#include <iomanip>
using namespace std;

int table[505][505];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	int rowWorkingOn = 1;
	int colWorkingOn = n;
	int rem = (n - k ) + 1;
	int i;
	int sum = 0;
	for(i = n * n; i >= 1 && rowWorkingOn <= n; i --){
		table[rowWorkingOn][colWorkingOn] = i;
		if(colWorkingOn == k){
			sum += i;
			rowWorkingOn ++;
			colWorkingOn = n;
		}
		else{
			colWorkingOn --;
		}
	}
	cout << sum << endl;
	rowWorkingOn = 1; colWorkingOn = k - 1;
	for(i; i >= 1; i --){
		table[rowWorkingOn][colWorkingOn] = i;
		if(colWorkingOn == 1){
			colWorkingOn = k - 1;
			rowWorkingOn ++;
		}
		else{
			colWorkingOn --;
		}
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			cout << table[i][j] << " \n"[j ==n];
		}
	}
	return 0;
}
