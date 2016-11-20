#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

long long cumul[int(1e6 + 5)];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	string a, b; cin >> a >> b;
	long long hammingdistance = 0;
	cumul[0] = 0;
	for(int i = 0; i < b.size(); i ++)
	{
		cumul[i + 1] = cumul[i] + b[i] - '0';
	}
	int length = (b.size() - a.size() + 1);
	for(int i = 0; i < a.size(); i ++)
	{
		if(a[i] == '1'){
			hammingdistance += length - (cumul[i + length] - cumul[i]); 
		}
		else
		{
			hammingdistance += cumul[i + length] - cumul[i];
		}
	}
	cout << hammingdistance << endl;

}
