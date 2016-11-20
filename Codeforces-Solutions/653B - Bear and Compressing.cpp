#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int n, q;
map<char, vector<string>> operations;
int compressing(string currentString = "a")
{
	if(currentString.length() == n)
		return 1;
	int ans = 0;
	int i = 0;
	for(int j = 0; j < operations[currentString[i]].size(); j ++)
		ans += compressing(currentString.substr(0, i).append(operations[currentString[i]][j]).append(currentString.substr(i+1, currentString.length() - i + 1)));
	return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
	ifstream cin("input.txt");
//	ofstream cout("output.txt");
#endif
	cin >> n >> q;
	for(int i = 0; i < q; i ++)
	{
		string u;
		char v;
		cin >> u >> v;
		operations[v].push_back(u);
	}
	cout << compressing() << endl;
}
