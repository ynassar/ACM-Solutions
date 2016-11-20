#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
#include <cstring>
using namespace std;

vector<pair<int, bool> > adjList[int(1e6 + 5)];
bool visited[int(1e6 + 5)];
int costs[int(1e6 + 5)];

int main()
{
	int n; cin >> n;
	for(int i = 0; i < n - 1; i ++)
	{
		int u, v; cin >> u >> v; u--; v --;
		adjList[u].push_back(make_pair(v, 1));
		adjList[v].push_back(make_pair(u, 0));
	}
	int numToReverse = 0;
	stack<int> stateStack;
	stateStack.push(0);
	while(!stateStack.empty())
	{
		int node = stateStack.top();
		if(!visited[node]) {
			visited[node] = true;
			for(int i = 0; i < adjList[node].size(); i++) {
				int child = adjList[node][i].first;
				if(!visited[child]) {
					if(!adjList[node][i].second) {
						numToReverse++;
					}
					stateStack.push(child);
				}
			}
		} else {
			stateStack.pop();
		}
	}
	costs[0] = numToReverse;
	int minCost = INT_MAX;
	stateStack.push(0);
	memset(visited, 0, sizeof visited);
	while(!stateStack.empty())
	{
		int node = stateStack.top();
		minCost = min(costs[node],minCost);
		if(!visited[node]) {
			visited[node] = true;
			for(int i = 0; i < adjList[node].size(); i++) {
				int child = adjList[node][i].first;
				if(!visited[child]) {
					if(!adjList[node][i].second) {
						costs[child] = costs[node]-1;
					} else {
						costs[child] = costs[node]+1;
					}
					stateStack.push(child);
				}
			}
		} else {
			stateStack.pop();
		}
	}
	cout << minCost << endl;
	for(int i = 0; i < n; i++) {
		if(costs[i] == minCost) {
			cout << i+1 << " ";
		}
	}

}
