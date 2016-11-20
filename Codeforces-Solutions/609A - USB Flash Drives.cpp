#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int binPow(int n, int p)
{
    int ret = 1;
    int x = n;
    while(p)
    {
        if(p % 2) ret *= x;
        x *= x;
        p /= 2;
    }
    return ret;
}

int arr[int(1e5)];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int sum = 0, count = 0;
    for(int i = n - 1; i >= 0; i --)
    {
        sum += arr[i];
        count ++;
        if(sum >= m)
        {
            cout << count << endl; exit(0);
        }
    }
}
