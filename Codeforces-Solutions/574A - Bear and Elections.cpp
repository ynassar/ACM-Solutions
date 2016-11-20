#include <iostream>
using namespace std;

int votes[101];
int candidateswith[1001];
int nworks()
{
    for (int i = 1000; i >= votes[0]; i--)
    {
        if (candidateswith[i]) return i;
    }
    return 0;
}
int main()
{
    int n; cin >> n;
    int mval = -1;
    int maxidx;
    cin >> votes[0];
    for (int i = 1; i < n; i++)
    {
        cin >> votes[i];
        candidateswith[votes[i]]++;
    }
    int greaterthan = nworks();
    int ans = 0;
    while (greaterthan)
    {
        candidateswith[greaterthan]--;
        if(greaterthan) candidateswith[greaterthan - 1] ++;
        votes[0] ++;
        ans++;
        greaterthan = nworks();
    }
    cout << ans << endl;
}
