#include <iostream>
#include <string>
#include <map>
using namespace std;

map<long long, long long> numLeft, numRight;
long long arr[int(1e6)];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        numRight[arr[i]] ++;
    }
    long long ans = 0;
    for(int i =0; i < n; i ++)
    {
        numRight[arr[i]] --;
        if(!(arr[i] % k)){
            ans += numLeft[arr[i] / k] * numRight[arr[i] * k];
        }
        numLeft[arr[i]] ++;
    }
    cout << ans << endl;
}
