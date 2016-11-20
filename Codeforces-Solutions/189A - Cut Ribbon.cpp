#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, a, b, c;
int dp[5000];
int ribbon(int len)
{
    if (len == 0) return 0;
    if (len < 0) return -1e9;
    if (dp[len] != -1) return dp[len];
    return dp[len] = max(1 + ribbon(len - a), max(1 + ribbon(len - b), 1 + ribbon(len - c)));
}
int main()
{
    cin >> n >> a >> b >> c;
    memset(dp, -1, sizeof dp);
    cout << ribbon(n);
}
