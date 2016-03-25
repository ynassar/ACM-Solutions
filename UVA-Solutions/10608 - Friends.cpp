#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int> > adjList;
bool visited[30005];
int nodeCount = 0;
void dfs(int node)
{
	visited[node] = true;
	nodeCount ++;
	for(int i = 0; i < adjList[node].size(); i ++)
	{
		int destination = adjList[node][i];
		if(!visited[destination])
		{
			dfs(destination);
		}
	}
}
int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
	  ifstream cin("input.txt");
//	ofstream cout("output.txt");
#endif
	int t; cin >> t;
	while(t--)
	{
		adjList.clear();
		memset(visited, 0, sizeof visited);
		int n, m; cin >> n >> m;
		adjList.resize(n);
		for(int i = 0; i < m; i ++)
		{
			int u, v; cin >> u >> v;
			u--;
			v--;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		int ans = -1;
		for(int i = 0; i < n; i ++)
		{
			if(visited[i]) continue;
			nodeCount = 0;
			dfs(i);
			ans = max(ans, nodeCount);
		}
		cout << ans << endl;
	}
}
