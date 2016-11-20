#include <iostream>
#include <vector>
using namespace std;
#define mp(x,y,z) make_pair(make_pair(x,y), z)
int numof[9];
vector<pair<pair<int,int>, int > > ans;
int main()
{
    int n; cin >> n;
    vector<int> numbers(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> numbers[i];
        numof[numbers[i]] ++;
        if(numbers[i] != 1 && numbers[i] != 2 && numbers[i] != 3 && numbers[i] != 6 && numbers[i] != 4)
        {
            cout << -1; exit(0);
        }
    }
    int numthrees = numof[3];
    for(int i = 0; i < numthrees; i ++)
    {
        ans.push_back(mp(1,3,6));
        numof[3] --;
        numof[6]--;
        numof[1]--;
    }
    int numsixes = numof[6];
    for(int i = 0; i < numsixes; i++)
    {
        ans.push_back(mp(1,2,6));
        numof[6]--;
        numof[2]--;
        numof[1]--;
    }
    int numtwos = numof[2];
    for(int i = 0; i < numtwos; i ++)
    {
        ans.push_back(mp(1,2,4));
        numof[1]--;
        numof[2]--;
        numof[4]--;
    }
    if(numof[2]|| numof[6]|| numof[1]|| numof[4])
    {
        cout << -1; exit(0);
    }
    for(int i = 0; i < ans.size(); i ++)
    {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
    }
}
