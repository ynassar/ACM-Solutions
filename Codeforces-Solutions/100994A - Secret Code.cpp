#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	string code; cin >> code;
	int n; cin >> n;
	int arr[256] = {};
	for(int i = 0; i < code.size(); i ++)
		arr[code[i]] ++;
	for(int i = 0; i < n; i ++)
	{
		int attarr[256] = {};
		string attempt; cin >> attempt;
		int a = 0, b = 0;

		for(int j = 0; j < attempt.size(); j ++)
		{
			if(code[j] == attempt[j])
				a ++;
			else{
				attarr[attempt[j]] ++;
				if(attarr[attempt[j]] <= arr[attempt[j]])
					b ++;
			}
		}
		cout << a << " " << b << endl;
	}
}
close
