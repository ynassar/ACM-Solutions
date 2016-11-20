#include <iostream>
using namespace std;

int arr[2005];
int dp[2005];
int n;

int main()
{
    cin >> n;
    int mval = -1;
    for(int i = 0; i < n; i ++)
    {
        cin >> arr[i];
        dp[arr[i]]++;
        mval = max(mval, arr[i]);
    }
    for(int i = 0; i < n; i ++)
    {
        int sum = 1;
        for(int j = arr[i] + 1; j <= mval; j ++)
            sum += dp[j];
        cout << sum << " ";
    }
}
