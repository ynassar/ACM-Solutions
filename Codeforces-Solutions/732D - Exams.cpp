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


int d[100005], a[100005];
int n, m;
bool works(int numDays){
	if(numDays == n + 1)
		return true;
	vector<int> examDays;
	vector<bool> seen(100005, false);
	for(int i = numDays - 1; i >= 0; i --){
		if(d[i] != -1 && !seen[d[i]]){
			examDays.push_back(i);
			seen[d[i]] = true;
		}
	}
	if(examDays.size() != m)
		return false;
	int lastExam = -1;
	int prepDays = 0;
	for(int i = examDays.size() - 1; i >= 0; i --){
		prepDays += examDays[i] - lastExam - 1;
		if(prepDays < a[d[examDays[i]]])
			return false;
		prepDays -= a[d[examDays[i]]];
		lastExam = examDays[i];
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	for(int i = 0; i < n; i ++) cin >> d[i], d[i]--;
	for(int i = 0; i < m; i ++) cin >> a[i];
	int start = 0, end = n + 1;
	while(start < end){
		int mid = start + (end - start) / 2;
		if(works(mid)){
			end = mid;
		}
		else{
			start = mid + 1;
		}
	}
	if(start == n + 1)
		cout << -1 << endl;
	else cout << start << endl;
	return 0;
}
