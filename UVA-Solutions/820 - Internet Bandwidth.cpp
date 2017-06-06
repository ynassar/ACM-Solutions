#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <sstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <iomanip>
using namespace std;

const int inf = 100000000;

int head[1000];

int to[10000];
int cap[10000];
int nxt[10000];

int last_edge;
int src, sink;

int n, m;

void add_edge(int u, int v, int c){
	to[last_edge] = v;
	cap[last_edge] = c;
	nxt[last_edge] = head[u];
	head[u] = last_edge ++;

	to[last_edge] = u;
	cap[last_edge] = 0;
	nxt[last_edge] = head[v];
	head[v] = last_edge ++;
}
void init(){
	last_edge = 0;
	memset(nxt, -1, sizeof nxt);
	memset(head, -1, sizeof head);
}
int augment_path(){
	vector<int> vis(1000, false);
	vector<int> parent(1000, -1);
	vector<int> edge_idx(1000);

	bool found_path = false;
	vis[src] = true;
	queue<int> q;
	q.push(src);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == sink){
			found_path = true;
			break;
		}
		for(int e = head[u]; e != -1; e = nxt[e]){
			int v = to[e];
			int c = cap[e];
			if(c > 0 && !vis[v]){
				vis[v] = true;
				parent[v] = u;
				edge_idx[v] = e;
				q.push(v);
			}
		}
	}
	if(!found_path)
		return 0;
	int min_edge = INT_MAX;
	int cur = sink;
	while(cur != src){
		min_edge = min(min_edge, cap[edge_idx[cur]]);
		cur = parent[cur];
	}

	cur = sink;
	while(cur != src){
		int e = edge_idx[cur];
		cap[e] -= min_edge;
		cap[e^1] += min_edge;
		cur = parent[cur];
	}
	return min_edge;
}
int max_flow(){
	int total_flow = 0;
	while(true){
		int flow = augment_path();
		if(flow == 0)
			return total_flow;
		else
			total_flow += flow;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "r+", stdout);
#endif
	int case_num = 1;
	while(cin >> n, n != 0){
		init();
		cin >> src >> sink >> m;
		src --; sink --;
		for(int i = 0; i < m; i ++){
			int u, v, c; cin >> u >> v >> c;
			u --; v--;
			add_edge(u, v, c);
			add_edge(v, u, c);
		}
		cout << "Network " << case_num ++ << endl;
		cout << "The bandwidth is " << max_flow() << "." << endl << endl;
	}
}
