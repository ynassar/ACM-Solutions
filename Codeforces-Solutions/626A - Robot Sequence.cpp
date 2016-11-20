#include <iostream>
#include <map>
using namespace std;

map<char, int> dx;
map<char, int> dy;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	dx['U'] = 0;
	dy['U'] = 1;
	dx['L'] = -1;
	dy['L'] = 0;
	dx['R'] = 1;
	dy['R'] = 0;
	dx['D'] = 0;
	dy['D'] = -1;
	int xcumul[205], ycumul[205];
	xcumul[0] = 0, ycumul[0] = 0;
	int n; cin >> n;
	for(int i = 0; i < n; i ++)
	{
		char temp; cin >> temp;
		xcumul[i + 1] = xcumul[i] + dx[temp];
		ycumul[i + 1] = ycumul[i] + dy[temp];
	}
	int count = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = i; j <= n; j ++)
		{
			count += ((xcumul[j] - xcumul[i - 1] == 0) && (ycumul[j] - ycumul[i - 1] == 0));
		}
	}
	cout << count << endl;
}
