#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string c[int(1e5 + 5)];
vector<int> positions[27];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	long long n, k; cin >> n >> k;
	string s; cin >> s;
	for(int i = 0; i < k; i ++)
	{
		positions[s[i] - 'a'].push_back(i);
	}
	for(int i = 0; i < n; i ++){
		cin >> c[i];
		long long erf = 0;
		for(int j = 0; j < c[i].size(); j ++)
		{
			if(positions[c[i][j] -'a'].size() == 0) {
				erf += c[i].size(); continue;
			}
			int greaterIdx = upper_bound(positions[c[i][j]-'a'].begin(), positions[c[i][j] -'a'].end(), j) - positions[c[i][j] - 'a'].begin();
			int lowerIdx = greaterIdx - 1;
			if(greaterIdx != positions[c[i][j]- 'a'].size())
			{
				if(lowerIdx != -1)
				{
					erf += min(abs(positions[c[i][j] - 'a'][greaterIdx] - j), abs(positions[c[i][j] - 'a'][lowerIdx] - j));
				}
				else
					erf += abs(positions[c[i][j] - 'a'][greaterIdx] - j);
			}
			else erf += abs(positions[c[i][j] - 'a'][lowerIdx] - j);
		}
		cout << erf << endl;
	}

}
