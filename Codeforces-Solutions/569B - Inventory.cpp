#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int sequence[int(1e5 + 5)];
int numof[int(1e5 + 5)];
int n;
int main()
{
    cin >> n;
    queue<int> invalids;
    for(int i = 0; i < n; i ++)
    {
        cin >> sequence[i];
        numof[sequence[i]] ++;
        if(numof[sequence[i]] > 1 || sequence[i] > n) invalids.push(i);
    }
    for(int count = 1; count <= n; count ++)
    {
        if(numof[count]) continue;
        int invalididx = invalids.front();
        invalids.pop();
        sequence[invalididx] = count;
    }
    for(int i = 0; i < n; i ++) cout << sequence[i] << " ";
}
