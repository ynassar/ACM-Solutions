#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> divisors;
long long gcd(long long a, long long b)
{
    return (a) ? (gcd(b % a, a)) : b;
}

void get_divisors(long long greatest)
{
    for (long long i = 1; i * i <= greatest; i++)
    {
        if(!(greatest % i)) divisors.push_back(i), divisors.push_back(greatest/i);
    }
    divisors.push_back(greatest);
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long a, b; cin >> a >> b;
    long long m; cin >> m;
    long long greatest = gcd(a, b);
    get_divisors(greatest);
    sort(divisors.begin(), divisors.end());
    for (long long i = 0; i < m; i++)
    {
        long long low, high; cin >> low >> high;
        long long start = 0, end = divisors.size() - 1;
        while (end - start > 1)
        {
            long long m = start + (end - start) / 2;
            if (divisors[m] > high)
            {
                end = m - 1;
            }
            else if (divisors[m] < low)
            {
                start = m + 1;
            }
            else
            {
                start = m;
            }
        }
        if (end >= 0 && end < divisors.size())
        {
            if (divisors[end] >= low && divisors[end] <= high)
                start = end;
        }
        if (start >= 0 && start < divisors.size())
        {
            if (divisors[start] >= low && divisors[start] <= high)
            {
                cout << divisors[start] << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else cout << -1 << endl;
    }
}
