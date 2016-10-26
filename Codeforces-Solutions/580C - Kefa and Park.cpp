#include <vector>
#include <iostream>
using namespace std;

int n, m;
vector<int> adjList[int(1e5 + 5)];
bool hasCat[int(1e5 + 5)];
int leavesToVisit(int node, int prev, int cats){
	if (hasCat[node])
		cats++;
	else cats = 0;
	if (cats > m)
		return 0;
	int ans = 0;
	bool enterred = false;
	for (int i = 0; i < adjList[node].size(); i++){
		int nextNode = adjList[node][i];
		if (nextNode != prev){
			enterred = true;
			ans += leavesToVisit(nextNode, node, cats);
		}
	}
	if (!enterred)
		return 1;
	return ans;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> hasCat[i];
	for (int i = 0; i < n - 1; i++){
		int u, v; cin >> u >> v;
		u--; v--;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	cout << leavesToVisit(0, -1, 0) << endl;
}
