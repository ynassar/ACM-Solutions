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

char grid[50][50];
int vertex_number[50][50];
int last_vertex;
int last_edge;
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
int num_alone = 0;
int src, sink;

vector<vector<int> > adj_list;

int color[1000];

int head[1000];
int to[100000];
int nxt[100000];
int cap[100000];

int h, w;

bool in_range(int i, int j){
	return i >= 0 && j >= 0 && i < h && j < w;
}
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
	adj_list.clear();
	adj_list.resize(1000);
	memset(head, -1, sizeof head);
	memset(nxt, -1, sizeof nxt);
	num_alone = 0;
	last_vertex = 0;
	memset(vertex_number, -1, sizeof vertex_number);
}
void assign_vertex_numbers(){
	for(int i = 0; i < h; i ++){
		for(int j = 0; j < w; j ++){
			if(grid[i][j] == '*'){
				bool has_adj = false;
				for(int k = 0; k < 4 && !has_adj; k ++){
					int new_i = i + di[k];
					int new_j = j + dj[k];
					if(in_range(new_i, new_j)){
						if(grid[new_i][new_j] == '*')
							has_adj = true;
					}
				}
				if(!has_adj){
					vertex_number[i][j] = -2;
					num_alone ++;
				}
			}
			else{
				vertex_number[i][j] = -2;
			}
		}
	}
	for(int i = 0; i < h; i ++){
		for(int j = 0; j < w; j ++){
			if(vertex_number[i][j] != -2){
				vertex_number[i][j] = last_vertex ++;
			}
		}
	}
}
void build_graph(){
	for(int i = 0; i < h; i ++){
		for(int j = 0; j < w; j ++){
			if(vertex_number[i][j] != -2){
				int u = vertex_number[i][j];
				for(int k = 0; k < 4; k ++){
					int new_i = i + di[k];
					int new_j = j + dj[k];
					if(in_range(new_i, new_j)){
						int v = vertex_number[new_i][new_j];
						if(v != -2){
							adj_list[u].push_back(v);
						}
					}
				}
			}
		}
	}
}
void bfs(int start){
	queue<int> q;
	q.push(start);
	color[start] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v : adj_list[u]){
			if(color[v] == -1){
				color[v] = !color[u];
				q.push(v);
			}
		}
	}
}
void color_graph(){
	memset(color, -1, sizeof color);
	for(int i = 0; i < last_vertex; i ++){
		if(color[i] == -1)
			bfs(i);
	}
}
void build_network(){
	int n_vertices = last_vertex;
	src = last_vertex ++;
	sink = last_vertex ++;
	for(int i = 0; i < n_vertices; i ++){
		if(color[i] == 0){
			add_edge(src, i, 1);
			for(int v : adj_list[i]){
				add_edge(i, v, 1);
			}
		}
		else{
			add_edge(i, sink, 1);
		}
	}
}
int augment_path(){
	vector<bool> vis(1000, false);
	vector<int> parent(1000, -1);
	vector<int> edge_idx(1000);

	queue<int> q;
	q.push(src);
	vis[src] = true;
	bool found_path = false;

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

	int cur = sink;
	int min_edge = INT_MAX;
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
	int t; cin >> t;
	while(t--){
		cin >> h >> w;
		init();
		for(int i = 0; i < h; i ++){
			for(int j = 0; j < w; j ++){
				cin >> grid[i][j];
			}
		}
		assign_vertex_numbers();
		build_graph();
		color_graph();
		build_network();
		int n_vertices = last_vertex - 2;
		int num_matchings = max_flow();
		int ans = num_matchings + num_alone + (n_vertices - num_matchings * 2);
		cout << ans << endl;
	}
}
