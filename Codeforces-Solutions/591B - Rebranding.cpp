#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

char arr[26];
int main()
{
	for(int i = 0; i < 26; i ++)
		arr[i] = 'a' + i;
	int n, m; cin >> n >> m;
	string name; cin >> name;
	for(int i = 0; i < m; i ++)
	{
		char from, to;
		cin >> from >> to;
		for(int j = 0; j < 26; j ++)
		{
			if (arr[j] == from)
				arr[j] = to;
			else if (arr[j] == to)
				arr[j] = from;
		}
	}
	for(int i = 0; i < n; i ++){
		cout << arr[name[i] -'a'];
	}

}
