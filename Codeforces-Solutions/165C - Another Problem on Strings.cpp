#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long cumul[long long(1e6 + 5)];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long k; cin >> k;
    string str; cin >> str;
    long long n = str.size();
    cumul[0] = 0;
    for(long long i = 0; i < n; i ++)
    {
        cumul[i + 1] = cumul[i] + (str[i] == '1');
    }
    long long currentK = cumul[n];
    long long ans = 0;
    for(long long i = 0; i <= currentK; i ++)
    {
        long long lowerofI = lower_bound(cumul, cumul+n + 1, i) - cumul;
        long long upperofI = upper_bound(cumul, cumul + n + 1, i) - cumul; upperofI--;
        long long lowerofK = lower_bound(cumul, cumul + n + 1, i + k) - cumul;
        long long upperofK = upper_bound(cumul, cumul+n+1, i + k) - cumul; upperofK --;
        if(cumul[lowerofI] != i || cumul[upperofK] != i + k) continue;
        if(k)ans += (upperofK - lowerofK + 1) * (upperofI - lowerofI + 1);
        else ans += ((upperofK - lowerofK) * (upperofI - lowerofI + 1)) / 2;
    }
    cout << ans << endl;
}
