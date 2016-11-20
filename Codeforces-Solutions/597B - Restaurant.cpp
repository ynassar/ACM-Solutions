#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[int(1e6 +5 )];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);;
#endif
    int n; cin >> n;
    for(int i= 0; i < n; i ++) cin >> arr[i].second >> arr[i].first;
    sort(arr, arr+n);
    int last = INT_MIN;
    int ans = 0;
    for(int i = 0; i < n; i ++)
    {
        if(arr[i].second > last)
            last = arr[i].first, ans ++;
    }
    cout << ans << endl;
}
