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
#include <map>
#include <set>
using namespace std;


bool hasFreeSpaceRec(int left, int right, int ss, int se, vector<bool>& tree, int ti = 1)
{
	if(ss > right || se < left || ss > se)
		return false;
	if(ss >= left && se <= right)
		return tree[ti];
	int leftChild = ti * 2;
	int rightChild = ti * 2 + 1;
	int mid = (ss + se) / 2;
	return hasFreeSpaceRec(left, right, ss, mid, tree, leftChild) || hasFreeSpaceRec(left, right, mid + 1, se, tree, rightChild);
}
bool hasFreeSpace(int left, int right, vector<bool>& tree, int maxIdx)
{
	return hasFreeSpaceRec(left, right, 0, maxIdx, tree);
}
void initializeTreeRec(int ss, int se, vector<bool>& tree, int ti = 1)
{
	if(ss == se){
		tree[ti] = true;
		return;
	}
	int mid = (ss + se) / 2;
	int leftChild = ti * 2;
	int rightChild = ti * 2 + 1;
	initializeTreeRec(ss, mid, tree, leftChild);
	initializeTreeRec(mid + 1, se, tree, rightChild);
	tree[ti] = true;
}
void initializeTree(vector<bool>& tree, int maxIdx)
{
	initializeTreeRec(0, maxIdx, tree);
}
bool coverSpaceRec(int left, int right, int ss, int se, vector<bool>& tree, int ti = 1)
{
	if(se < left || ss > right)
		return tree[ti];
	if(ss == se)
	{
		return tree[ti] = false;
	}
	int mid = (ss + se) / 2;
	int leftChild = ti * 2;
	int rightChild = ti * 2 + 1;
	bool leftans = coverSpaceRec(left, right, ss, mid, tree, leftChild);
	bool rightans = coverSpaceRec(left, right, mid + 1, se, tree, rightChild);
	return tree[ti] = leftans || rightans;
}
void coverSpace(int left, int right, vector<bool>& tree, int maxIdx)
{
	coverSpaceRec(left, right, 0, maxIdx, tree);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; scanf("%d", &n);
		vector<pair<int, int> > posters(n);
		map<int, int> compress;
		set<int> values;
		for(int i = 0; i < n; i ++)
		{
			scanf("%d %d", &posters[i].first, &posters[i].second);
			values.insert(posters[i].first);
			values.insert(posters[i].second);
		}
		int compressedIdx = 0;
		for(auto it = values.begin(); it != values.end(); it ++)
		{
			compress[*it] = compressedIdx++;
		}
		vector<bool> tree(compressedIdx * 4);
		initializeTree(tree, compressedIdx);
		int ans = 0;
		for(int i = n - 1; i >= 0; i --)
		{
			int left = compress[posters[i].first], right = compress[posters[i].second];
			if(hasFreeSpace(left, right, tree, compressedIdx))
			{
				ans ++;
				coverSpace(left, right, tree, compressedIdx);
			}
		}
		printf("%d\n", ans);
	}
}
