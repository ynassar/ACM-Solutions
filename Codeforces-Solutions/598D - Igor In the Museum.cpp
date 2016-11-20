#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

char arr[1005][1005];
//int num[1005][1005];
int vis[1005][1005];
int dp[1005][1005];
int n, m, k;
int maxi = -1, maxj = -1;
int answers[int(1e5+5)];
int queryNum = 1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
int dfs(int i, int j)
{
    vis[i][j] = queryNum;
    int ret = 0;
    for(int c= 0; c < 4; c ++)
    {
        if(isValid(i + dy[c], j + dx[c]))
        {
            if(!vis[i + dy[c]][j + dx[c]] ) {
                if(arr[i + dy[c]][j + dx[c]] == '.')
                    ret += dfs(i + dy[c], j + dx[c]);
                else
                    ret ++;
            }
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
            cin >> arr[i][j];
    }
    for(int i = 0; i < k; i ++)
    {
        int x, y; cin >> x >> y; x--; y--;
        int val;
        if(vis[x][y])
        {
            val = answers[vis[x][y]];
        }
        else
        {
            val = dfs(x,y);
        }
        answers[queryNum++] = val;
        cout << val << endl;
    }

}
