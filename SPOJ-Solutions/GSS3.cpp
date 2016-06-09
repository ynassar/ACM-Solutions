#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

#define MAXSZ 500005

struct node
{
	int maxLeft, maxRight, sum, maxSum;
};
long long n;
long long arr[MAXSZ];
node tree[4 * MAXSZ];
long long qs, qe;
node WNA;

bool operator ==(node a, node b)
{
	return a.maxLeft == b.maxLeft && a.maxRight == b.maxRight && a.maxSum == b.maxSum && a.sum == b.sum;
}
bool operator != (node a, node b)
{
	return !(a == b);
}
/*
long long minIdx(long long idx1, long long idx2)
{
	if(idx1 == -1) return idx2;
	if(idx2 == -1) return idx1;
	return (arr[idx1] > arr[idx2]) ? idx2 : idx1;
}*/
/*
long long buildTree(long long ss = 0, long long se = n - 1, long long ti = 1)
{
	if(ss > se) return -1;
	if(ss == se)
		return tree[ti] = ss;
	long long mid = (ss + se) / 2;
	return tree[ti] = minIdx(buildTree(ss, mid, 2*ti), buildTree(mid + 1, se, 2*ti + 1));
}
*/
node parentFromChildren(node leftChild, node rightChild)
{
	node parent;
	if(leftChild == WNA)
		parent = rightChild;
	if(rightChild == WNA)
		parent = leftChild;
	if(leftChild != WNA && rightChild != WNA){
		parent.maxLeft = max(leftChild.maxLeft, max(leftChild.sum + rightChild.maxLeft, leftChild.sum + rightChild.sum));
		parent.maxRight = max(rightChild.maxRight, max(rightChild.sum + leftChild.maxRight, leftChild.sum + rightChild.sum));
		parent.sum = leftChild.sum + rightChild.sum;
		parent.maxSum = max( leftChild.maxRight + rightChild.maxLeft, max(leftChild.maxSum, rightChild.maxSum)); 
	}
	if(leftChild == WNA && rightChild == WNA)
		parent = WNA;

	return parent;
}
node buildTree(long long ss = 0, long long se = n-1, long long ti = 1)
{
	if(ss > se) return WNA;
	if(ss == se){
		node n;
		n.maxLeft = n.maxRight = n.sum = n.maxSum = arr[ss];
		return tree[ti] = n;
	}
	long long mid = (ss + se) / 2;
	node leftChild = buildTree(ss, mid, 2*ti);
	node rightChild = buildTree(mid + 1, se, 2*ti + 1);
	node parent = parentFromChildren(leftChild, rightChild);
	
	return tree[ti] = parent;
}
node pointUpdate(long long idx, long long newVal, long long ss = 0, long long se = n - 1, long long ti = 1)
{
	if(ss > se) return WNA;
	if(ss == se && ss == idx){
		node n;
		n.sum = n.maxLeft = n.maxRight = n.maxSum = newVal;
		return tree[ti] = n;
	}
	if(ss > idx || se < idx) return tree[ti];
	long long mid = (ss + se) /2;
	node leftChild = pointUpdate(idx, newVal, ss, mid, 2*ti);
	node rightChild = pointUpdate(idx, newVal, mid + 1, se, 2*ti + 1);
	node parent = parentFromChildren(leftChild, rightChild);
	return tree[ti] = parent;
}
/*
long long getMinIdx(long long ss, long long se, long long ti = 1)
{
	if(se < qs || ss > qe) return -1;
	if(se <= qe && ss >= qs) return tree[ti];
	long long mid = (ss + se) / 2;
	return minIdx(getMinIdx(ss, mid, 2*ti), getMinIdx(mid + 1, se, 2*ti + 1));
}
*/
node getMaxInRange(long long ss = 0, long long se = n - 1, long long ti = 1)
{
	if(se < qs || ss > qe) return WNA;
	if(se <= qe && ss >= qs) return tree[ti];
	long long mid = (ss + se) / 2;
	return parentFromChildren(getMaxInRange(ss, mid, 2*ti), getMaxInRange(mid + 1, se, 2*ti + 1));
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	WNA.maxLeft = WNA.maxRight = WNA.sum = WNA.maxSum = int(-1e9);
	cin >> n;
	for(long long i = 0; i < n; i ++) scanf("%d", &arr[i]);
	buildTree();
	long long m; cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int queryType, x, y;
		scanf("%d %d %d", &queryType, &x, &y);
		if(queryType == 0)
		{
			x --;
			pointUpdate(x, y);
		}
		else
		{
			x --; y--;
			qs = x, qe = y;
			printf("%d\n", getMaxInRange().maxSum);
		}
	}
}
