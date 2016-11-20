#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[int(1e6)], b[int(1e6)];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    for(int i= 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];
    sort(a, a+n);
    for(int i = 0; i < m; i ++)
    {
        cout << upper_bound(a, a+n, b[i]) - a<< " ";
    }
}
