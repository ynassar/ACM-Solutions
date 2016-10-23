#include<iostream>
#include<string>
#include<map>
#include<cstring>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int courses[1004];
    int pref[1004][1004];
    int ans[1004];
    pair<int, int> scores[1004];
    for (int i = 1; i <= M; i++)
        cin >> courses[i];
    memset(pref, -1, sizeof pref);
    memset(ans, -1, sizeof ans);
    for (int i = 1; i <= N; i++) {
        cin >> scores[i].first;
        scores[i].first *= -1;
        scores[i].second = i;
        int cnt; cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            cin >> pref[i][j];
        }
    }
    
    sort(scores+1, scores + N+1);
    
    int st=1, en=1;
    while (st <= N)
    {
        //calculate st and en
        int ii;
        for (ii = st; ii < N && scores[ii].first == scores[ii + 1].first; ii++);
        en = ii;
        
        for (int i = 1; i <= M; i++) {
            for (int j = st; j <= en; j++) {
                int courseIdx = pref[scores[j].second][i];
                if ( courseIdx == -1 || ans[scores[j].second] != -1)
                    continue;
                if (courses[courseIdx] != 0) {
                    courses[courseIdx]--;
                    ans[scores[j].second] = courseIdx;
                }
            }
        }
        
        st = en + 1;
    }
    
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
    
}
close
