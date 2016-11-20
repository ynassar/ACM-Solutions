#include <iostream>
#include <string>
using namespace std;

int main()
{
    string arr[55];
    int n, m; cin >> n >> m;
    int maxi = -1, mini = INT_MAX, maxj = -1, minj = INT_MAX;
    for(int i = 0; i < n; i ++)
    {
        cin >> arr[i];
        for(int j = 0; j < m; j ++)
        {
            if(arr[i][j] == '*')
            {
                maxi = max(maxi, i); mini = min(mini, i);
                maxj = max(maxj, j); minj = min(minj, j);
            }
        }
    }
    for(int i = mini; i <= maxi; i ++)
    {
        for(int j = minj; j <= maxj;j ++)
            cout << arr[i][j];
        cout << endl;
    }
}
