#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;


int n, k;
map<int, int> dp;
int getGrundy(int pileSize)
{
    if(pileSize == 0) return 0;
    if(pileSize == 1 || pileSize == 3) return 1;
    if(pileSize % 2) return 0; 
    if(dp.count(pileSize)) return dp[pileSize];
    int first, second = -1;
    first = (getGrundy(pileSize - 1));
    if(pileSize % 2 == 0){
        if(k % 2 != 0)
            second = getGrundy(pileSize / 2);
        else
            second = 0;
    }
    if(first == 0)
    {
        if(second == first + 1) return dp[pileSize] = 2;
        return dp[pileSize] = 1;
    }
    if(second == 0)
    {
        if(first == second + 1) return dp[pileSize] = 2;
        return dp[pileSize] = 1;
    }
    return dp[pileSize] = 0;
}

int grundy(int pileSize)
{
    if(!pileSize) return 0;
    if(k % 2 == 0){
        if(pileSize == 1 || pileSize == 2) return pileSize;
        return  !(pileSize & 1);
    }
    dp.clear();
    return getGrundy(pileSize);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    int curPile;
    int ret = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> curPile;
        ret ^= grundy(curPile);
    }
    if(ret)
    {
        cout << "Kevin" << endl;
    }
    else
    {
        cout << "Nicky" << endl;
    }
}
