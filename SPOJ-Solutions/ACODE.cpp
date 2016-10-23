#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


string enc;
long long dp[int(1e5 + 5)];
long long ways(int index){
	if (index == enc.size())
		return 1;
	if (enc[index] == '0')
		return 0;
	long long& ref = dp[index];
	if (ref != -1)
		return ref;
	if (index == enc.size() - 1)
		return ref = ways(index + 1);
	if (atoi(enc.substr(index, 2).c_str()) <= 26)
		return ref = ways(index + 1) + ways(index + 2);
	return ref = ways(index + 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	while (cin >> enc, enc != "0"){
		memset(dp, -1, sizeof dp);
		cout << ways(0) << endl;
	}
	return 0;
}
