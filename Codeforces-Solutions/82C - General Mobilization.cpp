#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <stack>
#include <fstream>
#include <string>
#include <map>
using namespace std;

vector<pair<int, int> > adjList[int(1e5 +5)];
int priorities[int(1e5 + 5)];
int numReached = 1;
priority_queue<pair<int, int> >  divisionsAt[int(1e5 + 5)];
int timeToReachRoot[int(1e5 +5 )];
int currentTime = 1;
int n;
queue<pair<int, pair<int, int> >> toMove;
void moveDivisionsUp(int lower, int upper, int capacity)
{
	int numMoved = 0;
//	int alreadyMovedIdx = 0;
	while(numMoved < capacity && !divisionsAt[lower].empty())
	{
		int division = divisionsAt[lower].top().second;
		numMoved ++;
		divisionsAt[lower].pop();
		toMove.push(make_pair(upper, make_pair(-priorities[division], division)));
		if(upper == 0){
			numReached ++;
			timeToReachRoot[division] = currentTime;
		}
	}
}
void depthFirstSimulation(int node, int prev)
{
	for(int i= 0; i < adjList[node].size(); i ++)
	{
		if(adjList[node][i].first != prev && !divisionsAt[adjList[node][i].first].empty())
		{
			depthFirstSimulation(adjList[node][i].first, node);
			moveDivisionsUp(adjList[node][i].first, node, adjList[node][i].second);
		}
	}
}
void applyMovements()
{
	while(!toMove.empty())
	{
		int destination = toMove.front().first;
		divisionsAt[destination].push(toMove.front().second);
		toMove.pop();
	}
}
int main(){
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
#endif
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> priorities[i];
		divisionsAt[i].push(make_pair(-priorities[i], i));
	}
	for(int i = 0; i < n- 1; i ++)
	{
		int u, v, c; cin >> u >> v >> c;
		u --; v--;
		adjList[u].push_back(make_pair(v,c));
		adjList[v].push_back(make_pair(u,c));
	}
	timeToReachRoot[0] = 0;
	while(numReached < n)
	{
		depthFirstSimulation(0, -1);
		currentTime ++;
		applyMovements();
	}
	for(int i = 0; i < n; i ++)
		cout << timeToReachRoot[i] << ' ';
}
