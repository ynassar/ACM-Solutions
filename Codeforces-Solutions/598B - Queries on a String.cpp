#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

int mod(int a, int b)
{
    int ret = a % b;
    return (ret >= 0) ? ret : (b - abs(ret));
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    string str;
    cin >> str;
    int m; cin >> m;
    for(int i = 0; i < m; i ++)
    {
        int l, r, k; cin >> l >> r >> k; l--; r--;
        string substring ="";
        for(int j = l; j <= r; j ++)
            substring += str[j];
        for(int j = l; j <= r; j ++)
            str[j] = substring[mod((j - l - k), (r - l + 1))];
    }
    cout << str << endl;
}
