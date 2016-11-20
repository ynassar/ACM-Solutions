#include <iostream>
using namespace std;


int main()
{
    long long n, d, m, l; cin >> n >> d >> m >> l;
    long long cur = 0;
    long long lastplatform = (n - 1) * m + l;
    while (true)
    {
        long long curplat = cur - cur % m;
        cur += d * (1 + ((curplat + l - cur) / d));
        if (cur % m > l || cur > lastplatform)
        {
            cout << cur;
            return 0;
        }
    }
}
