#include <iostream>
using namespace std;

long long cumul[int(1e6)];
long long dp[int(1e6)][3];
int n, k; 
long long absurdity(int idx = 0, int numtaken = 0)
{
    if(numtaken == 2) return 0;
    if(idx > n - k) return ((numtaken == 2) ? 0 : -1e7);
    if(dp[idx][numtaken] != -1) return dp[idx][numtaken];
    return dp[idx][numtaken] = max(absurdity(idx + 1, numtaken),cumul[idx + k] - cumul[idx] + absurdity(idx + k, numtaken + 1));
}
void print(int idx = 0, int numtaken = 0)
{
    if(numtaken == 2) return;
    if(idx > n - k) return;
    if(absurdity(idx,numtaken) == cumul[idx + k] - cumul[idx] + absurdity(idx +k ,numtaken + 1))
    {
        cout << idx + 1 << " ";
        print(idx + k, numtaken + 1);
    }
    else print(idx +1 ,numtaken);
}
int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    cumul[0] = 0;
    int temp;
    for(int i= 1; i <= n; i ++)
    {
        cin >> temp;
        cumul[i] = temp + cumul[i - 1];
    }
    absurdity();
    print();
}
