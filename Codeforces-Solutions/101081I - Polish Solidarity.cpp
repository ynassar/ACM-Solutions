#include <bits/stdc++.h>
using namespace std;
#define MAX int(1e5 + 5)

pair< pair<int, int>, int> times[MAX];
int startTimes[MAX];
int dp[MAX];
int n;
int solidarity(int index)
{
	if(index == n)
		return dp[index] = 0;
	int& ref = dp[index];
	if(ref != -1)
		return ref;
	int endTime = times[index].first.second;
	int nextIndex = lower_bound(startTimes, startTimes+ n, endTime) - startTimes;
	return ref = max(1 + solidarity(nextIndex), solidarity(index + 1));
}
void printSolution(int index)
{
	if(index == n)
		return;
	
	int endTime = times[index].first.second;
	int nextIndex = lower_bound(startTimes, startTimes+ n, endTime) - startTimes;
	if(dp[index] == 1 + dp[nextIndex]){
		cout << times[index].second + 1 << " ";
		printSolution(nextIndex);
	}
	else {
		printSolution(index + 1);
	}
}
int main() {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i = 0; i < n; i ++) {
		string temp; cin >> temp;
		startTimes[i] = times[i].first.first = atoi(temp.substr(0,2).c_str()) * 60 + atoi(temp.substr(3, 2).c_str());
		cin >> temp;
		times[i].first.second = atoi(temp.substr(0,2).c_str()) * 60 + atoi(temp.substr(3, 2).c_str());
		times[i].second = i;
	}
	sort(times, times + n);
	sort(startTimes, startTimes + n);
	solidarity(0);
	printSolution(0);
	return 0;
}
close
