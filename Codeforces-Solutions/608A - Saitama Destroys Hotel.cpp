nclude <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

vector<pair<int, int>> passengers;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, s;
	cin >> n >> s;
	passengers.resize(n);
	for(int i = 0; i < n; i ++)
	{
		cin >> passengers[i].first >> passengers[i].second;
	}
	sort(passengers.rbegin(), passengers.rend());
	int totalTime = 0;
	for(int i = 0; i < n; i ++)
	{
		totalTime += s - passengers[i].first;
		s = passengers[i].first;
		if (totalTime < passengers[i].second) totalTime = passengers[i].second;
	}
	totalTime += s;
	cout << totalTime<< endl;
}
