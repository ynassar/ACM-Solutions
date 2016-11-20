#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <assert.h>
#include <set>
#include <vector>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
#endif
	int d, l, v1, v2;
	cin >> d >> l >> v1 >> v2;
	double left = ((v1 * 1.0) * (l - d)) / (v1 + v2);
	cout << fixed << setprecision(9) << left / v1;
}
