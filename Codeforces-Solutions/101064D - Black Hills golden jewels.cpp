#include <iostream>
#include <algorithm>
using namespace std;

long long n, k;
long long a[int(1e5 + 5)];
bool works(long long sum)
{
	long long count = 0;
	for (long long i = 0; i < n; i++)
	{
		long long toFind = sum - a[i];
		long long index = upper_bound(a, a + n, toFind) - a - 1;
		if (index <= i)
			break;
		count += index - i;
		if (count >= k)
			return true;
	}
	return false;
}
int main()
{
	cin >> n >> k;
	for (long long i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	long long start = a[0] + a[1], end = a[n - 1] + a[n - 2];
	while (end > start)
	{
		long long mid = (end - start) / 2 + start;
		if (works(mid))
			end = mid;
		else
			start = mid + 1;
	}
	if (works(start))
		cout << start << endl;
	else cout << end << endl;
}
