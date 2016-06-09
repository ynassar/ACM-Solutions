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


long long n;
long long arr[100005];
long long tree[4 * int(1e5 + 5)];
long long qs, qe;

long long minIdx(long long idx1, long long idx2)
{
	if(idx1 == -1) return idx2;
	if(idx2 == -1) return idx1;
	return (arr[idx1] > arr[idx2]) ? idx2 : idx1;
}
long long buildTree(long long ss, long long se, long long ti = 1)
{
	if(ss > se) return -1;
	if(ss == se)
		return tree[ti] = ss;
	long long mid = (ss + se) / 2;
	return tree[ti] = minIdx(buildTree(ss, mid, 2*ti), buildTree(mid + 1, se, 2*ti + 1));
}
long long getMinIdx(long long ss, long long se, long long ti = 1)
{
	if(se < qs || ss > qe) return -1;
	if(se <= qe && ss >= qs) return tree[ti];
	long long mid = (ss + se) / 2;
	return minIdx(getMinIdx(ss, mid, 2*ti), getMinIdx(mid + 1, se, 2*ti + 1));
}
long long largestRect(long long l, long long r)
{
	if(l > r) return -1;
	if(l == r) return arr[l];
	qs = l, qe = r;
	long long mIdx = getMinIdx(0, n - 1);
	return max(arr[mIdx] * (r - l + 1), max(largestRect(l, mIdx -1), largestRect(mIdx + 1, r)));
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	while(cin >> n, n != 0)
	{
		for(long long i = 0; i < n; i ++) scanf("%d", &arr[i]);
		buildTree(0, n- 1);
		long long ans = largestRect(0, n - 1);
		
		printf("%lld\n", ans);
	}
}
