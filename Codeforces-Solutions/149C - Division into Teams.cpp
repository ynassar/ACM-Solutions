#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

pair<int,int> players[int(1e6 + 5)];
vector<int> team1, team2;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n; cin >> n; for(int i = 0; i < n; i ++) cin >> players[i].first, players[i].second = i;
	sort(players,players+n);
	int turn = 0;
	for(int i = 0; i < n / 2; i ++)
	{
		if(turn == 0){
			team1.push_back(players[i].second);
			team2.push_back(players[n - 1 - i].second);
			turn = 1;
		}
		else
		{
			team1.push_back(players[n - 1 - i].second);
			team2.push_back(players[i].second);
			turn = 0;
		}
	}
	if(n % 2)
	{
		if(turn == 0) team2.push_back(players[n/2].second);
		else team1.push_back(players[n/2].second);
	}
	cout << team1.size() << endl;
	for(int i = 0; i < team1.size(); i ++)
	{
		cout << team1[i] + 1 << " ";
	}
	cout << endl;
	cout << team2.size() << endl;
	for(int i = 0; i < team2.size(); i ++)
	{
		cout << team2[i]  + 1<< " ";
	}
}
