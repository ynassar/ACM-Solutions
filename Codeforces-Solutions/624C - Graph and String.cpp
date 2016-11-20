#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <assert.h>
#include <set>
#include <vector>
#include <time.h>
#include <iomanip>
#include <map>
using namespace std;

int adjmat[500][500];
int type[500];
vector<int> as, bs, cs;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		int u, v; cin >> u >> v; u --; v --;
		adjmat[u][v] = 1;
		adjmat[v][u] = 1;
	}
	for(int i = 0; i < n; i ++)
	{
		for(int j= 0 ; j < n; j ++)
		{
			if(adjmat[i][j] != adjmat[j][i])
			{
				cout << "No"; exit(0);
			}
		}
	}
	for(int i = 0; i < n; i ++)
	{
		bool done = false;
		for(int j = 0; j < n && !done; j ++)
		{
			for(int k = j + 1; k < n && !done; k ++)
			{
				if(adjmat[i][j] && adjmat[i][k] && !adjmat[j][k])
				{
					for(int l = 0; l < bs.size(); l ++)
					{
						if(!adjmat[i][bs[l]])
						{
							cout << "No"; exit(0);
						}
					}
					type[i] = 1;
					bs.push_back(i);
					done = true;
				}
			}
		}
	}
	for(int i = 0; i < n; i ++)
	{
		if(type[i] == 1) continue;
		bool connectedToBs = true, connectedToAs = true, connectedToCs = true;
		for(int j = 0; j < bs.size(); j ++)
		{
			if(!adjmat[i][bs[j]]) connectedToBs = false;
		}
		for(int j = 0; j < as.size(); j ++)
		{
			if(!adjmat[i][as[j]]) connectedToAs = false;
		}
		for(int j = 0; j < cs.size(); j ++)
		{
			if(!adjmat[i][cs[j]]) connectedToCs = false;
		}
		if(connectedToBs && connectedToAs){
			type[i] = 0;
			as.push_back(i);
		}
		else if(connectedToBs && connectedToCs){
			type[i] = 2;
			cs.push_back(i);
		}
		else if(connectedToAs && connectedToBs && connectedToCs && as.size() && cs.size()){
			type[i] = 1;
			bs.push_back(i);
		}
		else{
			cout << "No"; exit(0);
		}
	}
	cout << "Yes" << endl;
	for(int i = 0; i < n; i ++)
	{
		cout << char('a' + type[i]); 
	}
}
