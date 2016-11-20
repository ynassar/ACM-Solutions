#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
using namespace std;

set< pair<long long, long long> > ans;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long x; cin >> x;
    for(long long m = 1; (m * m * m) <= 8 * x; m ++)
    {
        long long n = 6 * x + (m * m * m) - m;
        long long divisor = ((3*(m * m)) + (3 * m));
        if(n % divisor) continue;
        n /= divisor;
        if(n < m) continue;
        ans.insert(make_pair(n,m));
        ans.insert(make_pair(m, n));
    }
    //sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(set<pair<long long, long long> >::iterator it = ans.begin() ;it != ans.end(); it ++) cout << it->first << " " << it->second << endl;
}
