#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> adjList[int(1e5)];
int visited[int(1e5)];
void dfs(int node)
{
	visited[node] = true;
	for(int i = 0; i < adjList[node].size(); i ++)
	{
		if(!visited[adjList[node][i]])
			dfs(adjList[node][i]);
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n; cin >> n;
	memset(visited, -1, sizeof visited);
	for(int i = 0; i < n; i ++)
	{
		int x, y; cin >> x >> y;
		visited[x] = 0; visited[y + 1005] = 0;
		adjList[x].push_back(y + 1005);
		adjList[y + 1005].push_back(x);
	}
	int ans = 0;
	for(int i = 0; i < int(1e5); i ++)
	{
		if(visited[i] == -1 || visited[i] == 1) continue;
		dfs(i);
		ans ++;
	}
	cout << ans -1 << endl;
}
