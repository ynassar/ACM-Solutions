#include <iostream>
#include <queue>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

vector<int> adjList[105];
vector<int> knows[105];
bool visited[105];
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
	ifstream cin("input.txt");
#endif
	int n, m;
	cin >> n >> m;
	bool know = false;
	for(int i = 0; i < n; i ++)
	{
		int numLanguages;
		cin >> numLanguages;
		know |= (numLanguages != 0);
		for(int j = 0; j < numLanguages; j ++)
		{
			int language; cin >> language;
			for(int k = 0; k < knows[language].size(); k ++)
			{
				int u = i, v = knows[language][k];
				adjList[u].push_back(v);
				adjList[v].push_back(u);
			}
			knows[language].push_back(i);
		}
	}
	int numDfs = 0;
	for(int i = 0; i < n; i ++)
	{
		if(!visited[i])
		{
			dfs(i);
			numDfs++;
		}
	}
	cout << numDfs - 1 + !know << endl;
}
