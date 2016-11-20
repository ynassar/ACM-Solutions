#include <iostream>
#include <vector>
using namespace std;

bool seen[(int) 1e6 + 5];
int main() {
    // your code goes here
    int n; cin >> n;
    int mval = 0;
    char sign;
    int temp;
    int cur = 0;
    for (int i = 0; i < n; i ++)
    {
        cin >> sign >> temp;
        if(sign == '+')
            cur ++;
        else
        {
            if (!seen[temp])
            {
                mval ++;
            }
            else cur --;
        }
        seen[temp] = true;
        mval = max(mval, cur);
    }
    cout << mval << endl;
    return 0;
}
