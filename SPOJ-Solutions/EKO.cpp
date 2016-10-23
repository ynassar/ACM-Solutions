#include<iostream>

#include<algorithm>
using namespace std;

long long a[int(1e6 + 5)];
long long n, m;
long long cutByHeight(long long h)
{
	long long sum = 0;
	for (long long i = 0; i < n; i++)
	{
		if (a[i] >= h)
			sum += a[i] - h;
	}
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	long long maxheight = -1;
	for (long long i = 0; i < n; i++){
		cin >> a[i];
		maxheight = max(maxheight, a[i]);
	}
	long long start = 0, end = maxheight;
	while (end - start > 1)
	{
		long long mid = (end - start) / 2 + start;
		if (cutByHeight(mid) >= m)
			start = mid;
		else
			end = mid - 1;
	}
	if (cutByHeight(end) >= m)
		cout << end << endl;
	else cout << start << endl;
}
