#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
#endif
	int n, x = 0; string temp; cin >> n;
	for(int i = 0; i < n; i ++)
	{
		cin >> temp;
		x += temp == "X++" || temp == "++X";
		x -= temp == "X--" || temp == "--X";
	}
	cout << x << endl;
}
