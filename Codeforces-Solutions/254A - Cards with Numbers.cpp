#include <bits/stdc++.h>
using namespace std;

vector<int> indices[int(1e6)];
vector<pair<int, int> > ans;
int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n; cin >> n;
	int me = -1;
	for(int i = 1; i <= 2* n; i ++){
		int a; cin >> a;
		indices[a].push_back(i);
		me = max(me, a);
	}
	for(int i = 1; i <= me; i ++){
		if(indices[i].size() % 2 == 1){
			cout << -1 << endl;
			exit(0);
		}
		else{
			for(int j = 0; j < indices[i].size(); j += 2){
				ans.push_back(make_pair(indices[i][j], indices[i][j + 1]));
			}
		}
	}
	for(int i = 0; i < ans.size(); i ++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
