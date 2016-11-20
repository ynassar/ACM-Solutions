#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i ++){
		string s; cin >> s;
		if(!m.count(s)){
			cout << "OK" << endl;
			m[s] = 1;
		}
		else{
			cout << s << m[s] << endl;
			m[s] ++;
		}
	}
	return 0;
}
