#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n,k;
int mBell = -1;
map<int, int> originalMap;
int arr[int(1e6)];
bool canFit(int x)
{
    if(x < mBell) return false;
    map<int, int> bellSizes = originalMap;
    int numRequired = 0;
    for(int k = 0; k < n; k ++)
    {
        int i = arr[k];
        if(!bellSizes.count(i)) continue;
        if(i > x) return false;
        int other = x - i;
        bool takeOne = false;
        auto lb = bellSizes.lower_bound(other);
        if(lb == bellSizes.begin() && lb->first != other) takeOne = true;
        auto match = lb;
        if(match == bellSizes.end()) match --;
        else if((!takeOne && match != bellSizes.begin() && match->first != other)) match --;
        if(match->first == i && bellSizes[i] == 1) takeOne = true;
        if(takeOne)
        {
            numRequired ++;
            bellSizes[i] --;
            if(!bellSizes[i]) bellSizes.erase(i);
        }
        else
        {
            numRequired ++;
            bellSizes[i] --;
            if(!bellSizes[i]) bellSizes.erase(i);
            bellSizes[match->first]--;
            if(!bellSizes[match->first]) bellSizes.erase(match->first);
        }
        /*if(bellSizes[i])
        {
            i --;
        }*/
    }
    return numRequired <= k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    int temp;
    for(int i = 0; i < n; i ++){
        cin >> arr[i];
        originalMap[arr[i]] ++;
        mBell = max(arr[i], mBell);
    }
    int start = 0, end = 1e7;
    while(end - start > 1)
    {
        int mid = (end + start + 1) / 2;
        if(canFit(mid))
            end = mid;
        else
            start = mid + 1;
    }
    if(canFit(start)) cout << start << endl;
    else cout << end << endl;
}
