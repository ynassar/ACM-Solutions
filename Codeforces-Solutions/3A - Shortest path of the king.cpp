#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


bool taken[4000];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	string startingpos, endingpos;
	cin >> startingpos >> endingpos;
	int startingX = startingpos[0] - 'a' + 1;
	int startingY = startingpos[1] - '0';
	int endingX = endingpos[0] - 'a' + 1;
	int endingY = endingpos[1] - '0';
	vector<string> ans;
	while(startingX != endingX || startingY != endingY)
	{
		if(startingX > endingX)
		{
			if(startingY == endingY)
			{
				ans.push_back("L");
				startingX --;
			}
			else if(startingY < endingY)
			{
				ans.push_back("LU");
				startingX --;
				startingY ++;
			}
			else if(startingY > endingY)
			{
				ans.push_back("LD");
				startingX --;
				startingY --;
			}
		}
		else if(startingX < endingX)
		{
			if(startingY == endingY)
			{
				ans.push_back("R");
				startingX ++;
			}
			else if(startingY < endingY)
			{
				ans.push_back("RU");
				startingX ++;
				startingY ++;
			}
			else if(startingY > endingY)
			{
				ans.push_back("RD");
				startingX ++;
				startingY --;
			}
		}
		else if(startingX == endingX)
		{
			if(startingY < endingY)
			{
				ans.push_back("U");
				startingY ++;
			}
			else if(startingY > endingY)
			{
				ans.push_back("D");
				startingY --;
			}
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i ++)
	{
		cout << ans[i] << endl;
	}
}
