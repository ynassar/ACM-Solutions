#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<int> adjList[int(1e4 +5)];
vector<int> roots;
int rootCosts[int(1e4 +5)];
int getHeight(int curNode)
{
	int height = 0;
	for(int i = 0; i < adjList[curNode].size(); i ++)
	{
		height = max(height, 1 + getHeight(adjList[curNode][i]));
	}
	return height;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
	{
		int parent; cin >> parent;
		if(parent == -1) roots.push_back(i);
		else {
			parent --;
			adjList[parent].push_back(i);
		}
	}
	int minHeight = 0;
	for(int i = 0; i < roots.size(); i ++)
	{
			minHeight = max(minHeight, getHeight(roots[i]));
	}
	cout << minHeight + 1<< endl;
}
