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

int total_num_requests;

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

int application_node(char application){
	return application - 'A' + 10;
}
char application_name(int node){
	return node - 10 + 'A';
}
void init(){
	total_num_requests = 0;
	last_edge = 0;
	memset(nxt, -1, sizeof nxt);
	memset(head, -1, sizeof head);
	src = 10 + 26;
	sink = 10 + 26 + 1;
}
void parse_line(const string& line){
	int u = application_node(line[0]);
	int num_requests = line[1] - '0';
	total_num_requests += num_requests;
	int idx = 3;
	while(line[idx] != ';'){
		int v = line[idx] - '0';
		add_edge(u, v, 1);
		idx ++;
	}
	add_edge(src, u, num_requests);
}
void connect_sink(){
	for(int i = 0; i < 10; i ++){
		add_edge(i, sink, 1);
	}
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

void print_output(){
	for(int i = 0; i < 10; i ++){
		bool computer_used = false;
		for(int e = head[i]; e != -1 && !computer_used; e = nxt[e]){
			int v = to[e];
			int c = cap[e];
			if(v != sink && cap[e] > 0){
				cout << application_name(v);
				computer_used = true;
			}
		}
		if(!computer_used)
			cout << "_";
	}
	cout << endl;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "r+", stdout);
#endif
	string line;
	while(!cin.eof()){
		init();
		while(getline(cin, line), line != ""){
			parse_line(line);
			if(cin.eof())
				break;
		}
		connect_sink();
		if(max_flow() == total_num_requests){
			print_output();
		}
		else{
			cout << '!' << endl;
		}
	}
}
