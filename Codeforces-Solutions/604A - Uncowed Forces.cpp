#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    long long score =0;
    int values[] = {500, 1000, 1500, 2000, 2500 };
    int submissions[5];
    int wrongsubmissions[5];
    for(int i = 0; i < 5; i ++)
    {
        cin >> submissions[i];
    }
    for(int i = 0; i <5 ; i ++) cin >> wrongsubmissions[i];
    for(int i = 0; i < 5; i ++)
    {
        score += max(75 * values[i], (250 - submissions[i]) * (values[i]) - (50 * 250 * wrongsubmissions[i])); 
    }
    int n, m; cin >> n >> m;
    score /= 250;
    score += 100 * n;
    score -= 50 *m;
    cout << score << endl;
}
