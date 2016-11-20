#include <iostream>
#include <vector>
#include <string>
using namespace std;

string arr[11];
int n, m;
bool haspigadj(int i, int j)
{
    if(i > 0)
    {
        if(arr[i - 1][j] == 'P') return true;
    }
    if(j > 0)
    {
        if(arr[i][j - 1] == 'P') return true;
    }
    if(i < n - 1)
    {
        if(arr[i + 1][j] == 'P') return true;
    }
    if(j < m - 1)
    {
        if(arr[i][j + 1] == 'P') return true;
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            if (arr[i][j] != 'W') continue;
            ans += haspigadj(i,j);
        }
    }
    cout << ans << endl;
}
