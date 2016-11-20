#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <assert.h>
#include <set>
#include <vector>
#include <time.h>
#include <iomanip>
#include <map>
using namespace std;

int maxAllowed[26];
map<int, bool> taken;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
#endif
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> maxAllowed[i];
	}
	sort(maxAllowed, maxAllowed + n);
	long long ans = 0;
	for(int i = n - 1; i >= 0; i --)
	{
		int allowed = maxAllowed[i];
		while(taken[allowed] && allowed > 0)
		{
			allowed --;
		}
		taken[allowed] = true;
		ans += allowed;
	}
	cout << ans << endl;
}
