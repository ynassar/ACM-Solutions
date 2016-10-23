#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
	//freopen("Text.txt", "r", stdin);
	int h, w;
	cin >> h >> w;
	vector<int> es, ws;
	es.resize(h);
	ws.resize(h);
	for (int i = 0; i < h; i++)
		cin >> es[i];
	for (int i = 0; i < h; i++)
	{
		cin >> ws[i];
		ws[i] = w - ws[i];
	}
	int t=99999999,temp;
	for (int i = 0; i < h; i++)
		if (t > ws[i] - es[i])
		{
			t = ws[i] - es[i];
			temp = i;
		}
	double res = t / 2.0;
	cout << res << endl;
	return 0;
}
