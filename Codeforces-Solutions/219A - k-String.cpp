#include <iostream>
#include <string>
using namespace std;

int numof[26];
int main()
{
	int k; cin >> k;
	string str; cin >> str;
	for(int i = 0; i < str.size(); i ++)
	{
		numof[str[i] - 'a'] ++;
	}
	string ans = "";
	for(int i = 0; i < 26; i ++)
	{
		if(numof[i] % k)
		{
			cout << -1; exit(0);
		}
		else
		{
			for(int j = 0; j < numof[i] / k; j ++)
			{
				ans += char(i + 'a');
			}
		}
	}
	for(int i = 0; i < k; i ++) cout << ans;
}
