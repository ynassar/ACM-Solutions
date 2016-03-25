#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

int parent[10000];
int getAbsoluteParent(int node)
{
	return parent[node] = (parent[node] == node) ? node : getAbsoluteParent(parent[node]);
}
bool areConnected(int u, int v)
{
	return getAbsoluteParent(u) == getAbsoluteParent(v);
}
void addEdge(int u, int v)
{
	if(!areConnected(u,v))
		parent[getAbsoluteParent(u)] = getAbsoluteParent(v);
}
int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
	ifstream cin("input.txt");
//	ofstream cout("output.txt");
#endif
	string line;
	stringstream linestream;
	int t;
	getline(cin, line);
	linestream.str(line);
	linestream >> t;
	linestream.clear();
	bool first = true;
	getline(cin, line);
	while(t--)
	{
		if(!first) cout << '\n';
		first = false;
		int successes = 0, failures = 0;
		int n;
		getline(cin, line);
		linestream.str(line);
		linestream >> n;
		linestream.clear();
		for(int i = 0; i < n; i ++)
			parent[i] = i;
		getline(cin, line);
		while(line != "" && !cin.eof())
		{
			linestream.str(line);
			char type;
			int u, v;
			linestream >> type >> u >> v;
			linestream.clear();
			u--; v--;
			if(type == 'c')
			{
				addEdge(u, v);
			}
			else
			{
				bool connected = areConnected(u,v);
				successes += connected;
				failures += !connected;
			}
			getline(cin, line);
		}
		cout << successes << ',' << failures << endl;
	}
}
