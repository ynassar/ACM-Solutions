#include <bits/stdc++.h>
using namespace std;

int a[int(1e5)];
map<int, int> o, l, r;
int main() {
	int n; cin >> n;
	int maxO = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(!l.count(a[i]))
			l[a[i]] = i;
		r[a[i]] = i;
		o[a[i]]++;
		maxO = max(maxO, o[a[i]]);
	}
	int diff = n;
	int left, right;
	for(auto it : o){
		if(it.second == maxO){
			if(r[it.first] - l[it.first] + 1 <= diff){
				diff = r[it.first] - l[it.first] + 1;
				left = l[it.first];
				right = r[it.first];
			}
		}
	}
	cout << left + 1 << " " << right + 1 << endl;
	return 0;
}
