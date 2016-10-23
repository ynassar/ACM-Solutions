#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int mval = -1;
int agnescard[2005];
int card[2005];
int dp[2005][2005];
int n, m;

int crosscountry(int i, int j)
{
	if (i == n || j == m)
		return 0;
	int & ref = dp[i][j];
	if (ref != -1)
		return ref;
	if (agnescard[j] == card[i])
		return ref = 1 + crosscountry(i + 1, j + 1);
	return ref = max(crosscountry(i + 1, j), crosscountry(i, j + 1));
}

int main()
{
	int d, first;
	cin >> d;
	while (d--)
	{
		mval = -1;
		memset(agnescard, -1, sizeof agnescard);
		int idx = 0;
		while (true)
		{
			cin >> first;
			if (first == 0) break;
			agnescard[idx++] = first;
		}
		m = idx;
		bool cont = false;
		while (true)
		{
			memset(card, -1, sizeof card);
			memset(dp, -1, sizeof dp);
			cin >> first;
			if (first == 0){
				cont = true; break;
			}
			int cardidx = 0;
			card[cardidx++] = first;
			while (cin >> first, first != 0)
			{
				card[cardidx++] = first;
			}
			n = cardidx;
			int cur = crosscountry(0, 0);
			mval = max(mval, cur);
		}
		cout << mval << endl;
		if (cont) continue;
	}
}
