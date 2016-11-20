#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool dpset[200][200][200];
pair<bool, pair<bool, bool> > dp[200][200][200];
void update(pair<bool, pair<bool, bool>>& toUpdate, pair<bool, pair<bool,bool> > toCheck)
{
	toUpdate.first = max(toUpdate.first,toCheck.first);
	toUpdate.second.first = max(toUpdate.second.first,toCheck.second.first);
	toUpdate.second.second = max(toUpdate.second.second,toCheck.second.second);

}
pair<bool, pair<bool, bool>> cards(int numRed, int numGreen, int numBlue)
{
	if(numBlue + numRed + numGreen == 1)
	{
		if(numBlue)
		{
			return dp[numRed][numGreen][numBlue] = make_pair(false, make_pair(false, true));
		}
		else if(numRed)
		{
			return dp[numRed][numGreen][numBlue] = make_pair(true, make_pair(false, false));
		}
		else if(numGreen)
		{
			return dp[numRed][numGreen][numBlue] = make_pair(false, make_pair(true, false));
		}
	}
	if(dpset[numRed][numGreen][numBlue]) return dp[numRed][numGreen][numBlue];
	pair<bool, pair<bool, bool>> ret;
	if(numRed)
	{
		if(numRed >= 2)
			update(ret, cards(numRed - 1, numGreen, numBlue));
		if(numBlue)
			update(ret, cards(numRed - 1, numGreen + 1, numBlue - 1));
		if(numGreen)
			update(ret, cards(numRed - 1, numGreen - 1, numBlue + 1));
	}
	if(numBlue)
	{
		if(numBlue >= 2)
			update(ret, cards(numRed, numGreen, numBlue - 1));
		if(numGreen)
			update(ret, cards(numRed + 1, numGreen - 1, numBlue - 1));
	}
	if(numGreen)
	{
		if(numGreen >= 2)
			update(ret, cards(numRed, numGreen - 1, numBlue));
	}
	dpset[numRed][numGreen][numBlue] = true;
	return dp[numRed][numGreen][numBlue] = ret;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int numRed = 0, numBlue = 0, numGreen = 0;
	int n; cin >> n;
	string str; cin >> str;
	for(int i = 0; i < n; i ++)
	{
		numRed += str[i] == 'R';
		numBlue += str[i] == 'B';
		numGreen += str[i] == 'G';
	}
	pair<bool, pair<bool, bool> > ans = cards(numRed, numGreen, numBlue);
	string output = "";
	if(ans.first) output += 'R';
	if(ans.second.first) output += 'G';
	if(ans.second.second) output += 'B';
	sort(output.begin(), output.end());
	cout << output << endl;
}
