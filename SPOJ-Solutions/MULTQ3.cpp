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
#include <set>
using namespace std;
#define MAXSZ 1000005
struct node
{
	int num0;
	int num1;
	int num2;
};
node operator +(node a, node b)
{
	node ret;
	ret.num0 = a.num0 + b.num0;
	ret.num1 = a.num1 + b.num1;
	ret.num2 = a.num2 + b.num2;
	return ret;
}
node DNA;

node segTree[4*MAXSZ];
int lazy[4*MAXSZ];
inline void increment(node& a)
{
	int n0 = a.num0;
	int n1 = a.num1;
	int n2 = a.num2;
	a.num0 = n2;
	a.num1 = n0;
	a.num2 = n1;
}
inline void buildTree(int ss, int se, int ti = 1)
{
	lazy[ti] = 0;
	if(ss == se)
	{
		segTree[ti].num0 = 1;
		segTree[ti].num1 = segTree[ti].num2 = 0;
		return;
	}
	int mid = (ss + se) / 2;
	buildTree(ss, mid, 2*ti);
	buildTree(mid + 1, se, 2*ti + 1);
	segTree[ti] = segTree[2*ti] + segTree[2*ti + 1];
}
inline node query(int left, int right, int ss, int se, int ti = 1)
{
	if(lazy[ti])
	{
		for(int i = 0; i < lazy[ti] % 3; i ++)
			increment(segTree[ti]);
		if(ss != se)
		{
			lazy[2*ti] += lazy[ti];
			lazy[2*ti + 1] += lazy[ti];
		}
		lazy[ti] = 0;
	}
	if(se < left || ss > right || ss > se)
		return DNA;
	if(ss >= left && se <= right)
		return segTree[ti];
	int mid = (ss + se) / 2;
	return query(left, right, ss, mid, 2*ti) + query(left, right, mid + 1, se, 2*ti + 1);
}
inline void update(int left, int right, int ss, int se, int ti = 1)
{
	if(lazy[ti])
	{
		for(int i = 0; i < lazy[ti] % 3; i ++)
			increment(segTree[ti]);
		if(ss != se)
		{
			lazy[2*ti] += lazy[ti];
			lazy[2*ti + 1] += lazy[ti];
		}
		lazy[ti] = 0;
	}
	if(ss > right || se < left || ss > se)
		return;
	if(ss >= left && se <= right)
	{
		increment(segTree[ti]);
		if(ss != se)
		{
			lazy[2*ti] ++;
			lazy[2*ti + 1] ++;
		}
		return;
	}
	int mid = (ss + se) / 2;
	update(left, right, ss, mid, 2*ti);
	update(left, right, mid + 1, se, 2*ti + 1);
	segTree[ti] = segTree[2*ti] + segTree[2*ti + 1];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	DNA.num0 = DNA.num1 = DNA.num2 = 0;
	int n, q;
	scanf("%d %d", &n, &q);
	buildTree(0, n - 1);
	for(int i = 0; i < q; i ++)
	{
		int type, a, b;
		scanf("%d %d %d", &type, &a, &b);
		if(type)
		{
			printf("%d\n", query(a, b, 0, n - 1).num0);
		}
		else
		{
			update(a, b, 0, n -1);
		}
	}
}
