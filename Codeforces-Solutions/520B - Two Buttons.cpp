#include <bits/stdc++.h>
using namespace std;

bool vis[int(1e5 + 5)];
int main() {
	int n, m;
	cin >> n >> m;
	queue<pair<int, int> > q;
	q.push(make_pair(n ,0));
	while(!q.empty()){
		int number = q.front().first;
		int pushes = q.front().second;
		q.pop();
		if(number == m){
			cout << pushes << endl; break;
		}
		vis[number] = true;
		if(number == 0)
			continue;
		if(!vis[number * 2] && number < m)
			q.push(make_pair(number * 2, pushes + 1));
		if(!vis[number - 1])
			q.push(make_pair(number - 1, pushes + 1));
		vis[number * 2] = vis[number - 1] = true;
	}
	return 0;
}
