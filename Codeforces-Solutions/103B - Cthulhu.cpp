#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <stack>
#include <climits>
using namespace std;

bool visited[101];
vector<int> adjList[101];
void dfs(int node)
{
	visited[node] = true;
	for(int i = 0; i < adjList[node].size(); i ++)
	{
		if(!visited[adjList[node][i]])
		{
			dfs(adjList[node][i]);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, m; cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	bool allVisited = true;
	dfs(1);
	for(int i = 1; i <= n; i ++)
	{
		if(!visited[i])
		{
			allVisited = false;
		}
	}
	if(allVisited && n == m)
	{
		cout << "FHTAGN!" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
