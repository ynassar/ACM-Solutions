#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int arr[int(1e5 +5)];
int copied[int(1e5 +5 )];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n; cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> arr[i];
        copied[i] = arr[i];
    }
    sort(copied, copied +n);
    map<int, int> cur;
    int ans = 0;
    int size = 0;
    for(int i = 0; i < n; i ++)
    {
        if(!cur[arr[i]]) size ++;
        cur[arr[i]] ++;
        cur[copied[i]] --;
        if(!cur[copied[i]]) size --;
        bool add = true;
        if(size) add = false;
        ans += add;
    }
    cout << ans << endl;
}
