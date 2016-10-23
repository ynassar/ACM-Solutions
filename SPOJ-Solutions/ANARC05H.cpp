#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

string a;
int dp[27][270][270];
int sumRemaining[27];
int chop(int i = 1, int sum = a[0] - '0', int sumPrev = 0)
{
	if (i == a.size())
		return sum >= sumPrev;
	int& ref = dp[i][sum][sumPrev];
	if (ref != -1)
		return ref;
	if (sum >= sumPrev){
		return ref = chop(i + 1, a[i] - '0', sum) + chop(i + 1, sum + a[i] - '0', sumPrev);
	}
	else{
		return ref = chop(i + 1, sum + a[i] - '0', sumPrev);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t = 1;
	while (cin >> a, a != "bye"){
		memset(dp, -1, sizeof dp);
		cout << t++ << ". " << chop() << endl;
	}
	return 0;
}
