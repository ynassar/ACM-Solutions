#include <bits/stdc++.h>
using namespace std;

string s1, s2;
string substring = "";
vector<int> indices1, indices2;
int dp[105][105];
int lcs(int i, int j){
	if(i == s1.size() || j == s2.size())
		return 0;
	int& ref = dp[i][j];
	if(ref != -1)
		return ref;
	if(s1[i] == s2[j])
		return ref = 1 + lcs(i + 1, j +1);
	return ref = max(lcs(i + 1, j), lcs(i, j + 1));
}
void getLCS(int i, int j){
	if( i== s1.size() || j == s2.size())
		return;
	if(s1[i] == s2[j]){
		substring += s1[i];
		indices1.push_back(i);
		indices2.push_back(j);
		getLCS(i + 1, j + 1);
	}
	else{
		int& ref = dp[i][j];
		if(ref == dp[i + 1][j])
			getLCS(i + 1, j);
		else
			getLCS(i, j + 1);
	}
}
int main() {
	while(cin >> s1 >> s2){
		memset(dp, -1, sizeof dp);
		indices1.clear();
		indices2.clear();
		substring = "";
		lcs(0, 0);
		getLCS(0, 0);
		int last1 = 0, last2 = 0;
		for(int i = 0; i < indices1.size(); i ++){
			for(last1; last1 < indices1[i]; last1 ++){
				cout << s1[last1];
			}
			last1 = indices1[i] + 1;
			for(last2; last2 < indices2[i]; last2 ++){
				cout << s2[last2];
			}
			last2 = indices2[i] + 1;
			cout << substring[i];
		}
		for(last1; last1 < s1.size(); last1 ++)
			cout << s1[last1];
		for(last2; last2 < s2.size(); last2 ++)
			cout << s2[last2];
		cout << endl;
	}
	return 0;
}
