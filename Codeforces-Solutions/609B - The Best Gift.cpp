#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int arr[int(1e6)];
int sum_after[int(1e6 + 5)];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        int temp; cin >> temp;
        arr[temp]++;
    }
    int total_sum = n;
    for(int i = 0; i < n; i ++)
    {
        total_sum -= arr[i];
        sum_after[i] = total_sum;
    }
    long long ans = 0;
    for(int i = 0; i < n; i ++)
    {
        ans += arr[i] * sum_after[i];
    }
    cout << ans << endl;
}
