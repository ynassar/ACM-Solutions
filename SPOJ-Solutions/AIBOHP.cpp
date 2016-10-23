#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
 
using namespace std;
 
int n;
string s;
int dp[5007][5007];
 
int palin(int i, int j)
{
 
	if (i >= j)
		return 0;
 
	int &r = dp[i][j];
 
	if (r != -1)
		return r;
 
	if (s[i] == s[j])
		return r = palin(i + 1, j - 1);
 
	return r = min(1 + palin(i, j - 1), 1 + palin(i + 1, j));
 
}
 
int main()
{
 
	int t; cin >> t;
	while(t--){
		cin >> s;
		int n = s.size();
		memset(dp, -1, sizeof dp);
		cout << palin(0, n - 1) << endl;
	}
}
