#include <bits/stdc++.h>
using namespace std;

map<int, int> colorsInComponent;
int maxOccurrences = 0;
bool visited[int(1e6)];
int colorOf[int(1e6)];
vector<int> adjList[int(1e6)];
int n, m, k;
int sizeOfComponent(int node){
	colorsInComponent[colorOf[node]]++;
	maxOccurrences = max(maxOccurrences, colorsInComponent[colorOf[node]]);
	visited[node] = true;
	int ans = 1;
	for(int i = 0; i < adjList[node].size(); i ++){
		if(!visited[adjList[node][i]]){
			ans += sizeOfComponent(adjList[node][i]);
		}
	}
	return ans;
}
int main() {
	cin >> n >> m >> k;
	for(int i = 0; i < n; i ++) cin >> colorOf[i];
	for(int i = 0; i < m; i ++){
		int u, v; cin >> u >> v;
		u--; v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	int ans = 0;
	for(int i = 0; i < n; i ++){
		if(!visited[i]){
			colorsInComponent.clear();
			maxOccurrences = 0;
			int componentSize = sizeOfComponent(i);
			ans += componentSize - maxOccurrences;
		}
	}
	cout << ans << endl;
	return 0;
}
