#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    int x; cin >> x;
    int left[75], right[75];
    int mval = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> left[i] >> right[i];
        mval = max(right[i], mval);
    }
    int cur = 1, sum = 0, idx = 0;
    while (cur <= mval)
    {
        while (cur > right[idx]) idx++;
        if (cur <= right[idx] && cur >= left[idx])
        {
            sum++; cur++;
        }
        else if (left[idx] >= cur + x){
            cur += x;
        }
        else{
            cur++; sum++;
        }
    }
    cout << sum << endl;
}
