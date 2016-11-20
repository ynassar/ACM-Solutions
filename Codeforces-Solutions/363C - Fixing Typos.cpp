#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str; cin >> str;
	string ans = "";
	int n = 0;
	for(int i = 0; i < str.size(); i ++)
	{
		n = ans.size() - 1;
		if(i == 0 || i == 1)
		{
			ans += str[i]; continue;
		}
		if(str[i] == ans[n] && str[i] == ans[n - 1]) continue;
		if(i == 2)
		{
			ans += str[i]; continue;
		}
		if(str[i] == ans[n] && ans[n - 1] == ans[n - 2]) continue;
		ans += str[i];
	}
	cout << ans << endl;
}
