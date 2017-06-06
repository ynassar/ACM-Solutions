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

int n, m;
int start[1000];
int m_end[1000];
set<int> break_points;
int thirstiness[1000];
int last_vertex;
int last_edge;
int num_intervals;
int src, sink;
int total_thirstiness;
int interval_start[1000];
int interval_end[1000];
int interval_vertex[1000];
int inverse_interval_vertex[1000];

int head[1000];
int cap[100000];
int cap_cpy[100000];
int nxt[100000];
int to[100000];


void add_edge(int u, int v, int c){
	cap[last_edge] = c;
	to[last_edge] = v;
	nxt[last_edge] = head[u];
	head[u] = last_edge++;

	cap[last_edge] = 0;
	to[last_edge] = u;
	nxt[last_edge] = head[v];
	head[v] = last_edge ++;
}
void init(){
	total_thirstiness = 0;
	memset(head, -1, sizeof head);
	memset(nxt, -1, sizeof nxt);
	last_edge = 0;
	last_vertex = 0;
	num_intervals = 0;
	break_points.clear();
}
void connect_intervals(){
	for(int i = 0; i < n; i ++){
		int j = lower_bound(interval_start, interval_start + num_intervals, start[i]) - interval_start;
		while(j < num_intervals && interval_end[j] <= m_end[i]){
			int u = i;
			int v = interval_vertex[j];
			int c = interval_end[j] - interval_start[j];
			add_edge(u, v, c);
			j ++;
		}
	}
}
void connect_src_sink(){
	for(int i = 0; i < n; i ++){
		add_edge(src, i, thirstiness[i]);
	}
	for(int i = 0; i < num_intervals; i ++){
		add_edge(interval_vertex[i], sink, m * (interval_end[i] - interval_start[i]));
	}
}
int augment_path(){
	vector<bool> vis(1000, false);
	vector<int> parent(1000, -1);
	vector<int> edge_idx(1000, -1);

	bool found_sink = false;
	queue<int> q;
	vis[src] = true;
	q.push(src);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		if(u == sink){
			found_sink = true;
			break;
		}
		for(int e = head[u]; e != -1; e = nxt[e]){
			int v = to[e];
			int c = cap[e];
			if(!vis[v] && c > 0){
				vis[v] = true;
				parent[v] = u;
				edge_idx[v] = e;
				q.push(v);
			}
		}
	}
	if(!found_sink)
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
	memcpy(cap_cpy, cap, sizeof cap);
	int total_flow = 0;
	while(true){
		int flow = augment_path();
		if(flow == 0)
			return total_flow;
		else
			total_flow += flow;
	}
}
void print_answer(){
	int last_free_time[10000];
	memset(last_free_time, -1, sizeof last_free_time);
	for(int i = 0; i < n; i ++){
		vector<pair<int, int> > intervals;
		for(int e = head[i]; e != -1; e = nxt[e]){
			int c = cap[e^1];
			int v = to[e];
			if(c > 0 && v != src){
				int interval_idx = inverse_interval_vertex[v];
				if(last_free_time[interval_idx] == -1)
					last_free_time[interval_idx] = interval_start[interval_idx];
				int st = last_free_time[interval_idx];
				int en = st + c;
				if(en > interval_end[interval_idx]){
					intervals.push_back(make_pair(st, interval_end[interval_idx]));
					int leftover = en - interval_end[interval_idx];
					int st_2 = interval_start[interval_idx];
					int en_2 = st_2 + leftover;
					intervals.push_back(make_pair(st_2, en_2));
					last_free_time[interval_idx] = en_2;
				}
				else{
					intervals.push_back(make_pair(st, en));
					last_free_time[interval_idx] = en;
				}

				if(last_free_time[interval_idx] == interval_end[interval_idx])
					last_free_time[interval_idx] = interval_start[interval_idx];
			}
		}
		sort(intervals.begin(), intervals.end());
		vector<pair<int, int> > compressed_intervals;
		int idx = 0;
		while(idx < intervals.size()){
			int st = intervals[idx].first;
			while(idx < intervals.size() - 1 && intervals[idx].second == intervals[idx + 1].first){
				idx ++;
			}
			int en = intervals[idx].second;
			compressed_intervals.push_back(make_pair(st, en));
			idx ++;
		}
		cout << compressed_intervals.size();
		for(int j = 0; j < compressed_intervals.size(); j ++){
			cout << " (" << compressed_intervals[j].first << "," << compressed_intervals[j].second << ")";
		}
		cout << endl;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "r+", stdout);
#endif
	int case_num = 1;
	while(cin >> n, n != 0){
		cin >> m;
		init();
		for(int i = 0; i < n; i ++){
			cin >> thirstiness[i] >> start[i] >> m_end[i];
			break_points.insert(start[i]);
			break_points.insert(m_end[i]);
			total_thirstiness += thirstiness[i];
		}
		last_vertex = n;
		for(auto it = break_points.begin(); next(it,1) != break_points.end(); it ++){
			int st = *it;
			int en = *next(it,1);
			interval_start[num_intervals] = st;
			interval_end[num_intervals] = en;
			inverse_interval_vertex[last_vertex] = num_intervals;
			interval_vertex[num_intervals] = last_vertex ++;
			num_intervals ++;
		}
		src = last_vertex ++;
		sink = last_vertex ++;
		connect_intervals();
		connect_src_sink();
		cout << "Case " << case_num ++ << ": ";
		if(max_flow() == total_thirstiness){
			cout << "Yes" << endl;
			print_answer();
		}
		else{
			cout << "No" << endl;
		}
	}
}
