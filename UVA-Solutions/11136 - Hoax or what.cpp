#include <bits/stdc++.h>
using namespace std;

int a[100005];
int main() {
	int n;
	while(cin >> n, n != 0){
		map<int, int> st;
		long long ans = 0;
		while(n--){
			int k; cin >> k;
			for(int i = 0; i < k; i ++)
				cin >> a[i], st[a[i]]++;
			int minVal = (*st.begin()).first;
			int maxVal = (*st.rbegin()).first;
			ans += maxVal - minVal;
			st[minVal] --;
			st[maxVal] --;
			if(st[minVal] == 0)
				st.erase(minVal);
			if(st[maxVal] == 0)
				st.erase(maxVal);
		}
		cout << ans << endl;
	}
	return 0;
}
