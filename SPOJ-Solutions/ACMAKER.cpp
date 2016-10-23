#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


map<string, bool> insig;
string words[155];
string acro;
int m = 0;
bool has[155][26];
int dp[155][155][155][2];
void splitLine(string& line)
{
	memset(dp, -1, sizeof dp);
	m = 0;
	acro = "";
	int i;
	for (i = 0; i < line.size(); i++){
		if (line[i] == ' '){
			break;
		}
		else{
			acro += line[i];
		}
	}
	line += ' ';
	string cur = "";
	i++;
	for (i; i < line.size(); i++){
		if (line[i] == ' '){
			if (!insig[cur]){
				words[m++] = cur;
			}
			cur = "";
		}
		else{
			cur += line[i];
		}
	}
}
int ways(int wordIdx, int charIdx, int acroIdx, bool tookThisWord = false){
	//	cout << "WORD = " << words[wordIdx] << " charIdx = " << charIdx << " acroIdx = " << acroIdx << endl;
	if (acroIdx == acro.size())
		return wordIdx >= m - 1;
	if (wordIdx == m)
		return 0;
	int& ref = dp[wordIdx][charIdx][acroIdx][tookThisWord];
	if (ref != -1)
		return ref;
	if (charIdx == words[wordIdx].size()){
		if (!tookThisWord)
			return 0;
		return ref = ways(wordIdx + 1, 0, acroIdx, false);
	}
	if (words[wordIdx][charIdx] == tolower(acro[acroIdx])){
		return ref = ways(wordIdx, charIdx + 1, acroIdx, tookThisWord) + ways(wordIdx, charIdx + 1, acroIdx + 1, true);
	}
	else{
		return ref = ways(wordIdx, charIdx + 1, acroIdx, tookThisWord);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int n;
	while (cin >> n, n != 0){
		string str;
		insig.clear();
		for (int i = 0; i < n; i++){
			cin >> str;
			insig[str] = true;
		}
		string line;
		getline(cin, line);
		getline(cin, line);
		while (line != "LAST CASE"){
			splitLine(line);
			int ans = ways(0, 0, 0);
			if (ans == 0){
				cout << acro << " is not a valid abbreviation" << endl;
			}
			else{
				cout << acro << " can be formed in " << ans << " ways" << endl;
			}
			getline(cin, line);
		}
	}
	return 0;
}
