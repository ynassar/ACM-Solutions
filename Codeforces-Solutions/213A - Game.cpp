#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <stack>
#include <string>
using namespace std;

int adjMat[201][201];
int computer[201];
int indegree[201];
int originalIndegree[201];
bool done[201];
int n;
int costStartingFrom(int startingComputer)
{
	for(int i = 1; i <= n; i ++) indegree[i] = originalIndegree[i];
	memset(done, false, sizeof done);
	int currentComputer = startingComputer;
	int ret = 0;
	queue<int> qs[4];
	for(int i = 1; i <= n; i ++)
	{
		if(!indegree[i])
		{
			qs[computer[i]].push(i);
		}
	}
	while(!(qs[1].empty() && qs[2].empty() && qs[3].empty()))
	{
		while(!qs[currentComputer].empty())
		{
			int task = qs[currentComputer].front();
			done[task] = true;
			ret ++;
			qs[currentComputer].pop();
			for(int i = 1; i <= n; i ++)
			{
				if(adjMat[task][i])
				{
					if(indegree[i]) indegree[i] --;
					if(!indegree[i] && !done[i]) qs[computer[i]].push(i);
				}
			}
		}
		if(!(qs[1].empty() && qs[2].empty() && qs[3].empty())){
			currentComputer ++;
			currentComputer %= 4;
			currentComputer = max(currentComputer, 1);
			ret ++;
		}
	}
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> computer[i];
	for(int i = 1; i <= n; i ++)
	{
		int k; cin >> k;
		for(int j = 0; j < k; j ++)
		{
			int u; cin >> u;
			adjMat[u][i] = true;
			originalIndegree[i] ++;
		}
	}
	int minCost = INT_MAX;
	for(int i = 1; i<= 3; i ++)
	{
		minCost = min(minCost, costStartingFrom(i));
	}
	cout << minCost << endl;
}
