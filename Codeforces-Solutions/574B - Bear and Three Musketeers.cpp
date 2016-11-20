#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> knows[4005];
int recognition[4005];
bool knowmat[4005][4005];
int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int first, second; cin >> first >> second;
        knows[first].push_back(second);
        knows[second].push_back(first);
        knowmat[first][second] = true;
        knowmat[second][first] = true;
        recognition[first] ++;
        recognition[second] ++;
    }
    int mval = INT_MAX;
    int one, two, three;
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (!recognition[i]) continue;
        for (int j = 0; j < knows[i].size(); j++)
        {
            int nj = knows[i][j];
            for (int k = 0; k < knows[knows[i][j]].size(); k++)
            {
                int nk = knows[nj][k];
                if (!knowmat[i][nk]) continue;
                found = true;
                mval = min(mval, recognition[i] + recognition[nj] + recognition[nk]);
            }
        }
    }
    if (!found) cout << -1, exit(0);
    cout << mval - 6 << endl;
    return 0;
}
