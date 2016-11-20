#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int heights[1005];
int n;
int watered(int section)
{
	int lastHeight = heights[section];
	int ret = 0;
	for(int i = section - 1; i >= 0; i --)
	{
		if(heights[i] > lastHeight) break;
		ret ++;
		lastHeight = heights[i];
	}
	lastHeight = heights[section];
	for(int i = section + 1; i < n; i ++)
	{
		if(heights[i] > lastHeight) break;
		ret ++;
		lastHeight = heights[i];
	}
	return ret + 1;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> heights[i];
	int ans = 0;
	for(int i = 0; i < n; i ++) ans = max(ans, watered(i));
	cout << ans << endl;
}
