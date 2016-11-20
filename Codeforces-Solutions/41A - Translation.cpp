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
	string a, b; cin >> a >> b;
	reverse(a.begin(), a.end());
	cout << ((a == b) ? "YES" : "NO") << endl;
}
