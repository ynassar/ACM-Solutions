#include <iostream>
#include <string>
#include <map>
using namespace std;

int conversion[256];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    conversion['>'] = 8;
    conversion['<'] = 9;
    conversion['+'] = 10;
    conversion['-'] = 11;
    conversion['.'] = 12;
    conversion[','] = 13;
    conversion['['] = 14;
    conversion[']'] = 15;
    string str; cin >> str;
    long long ans = 0;
    for(int i = 0; i < str.size(); i ++)
    {
        ans *= 16;
        ans %= 1000003;
        ans += conversion[str[i]];
        ans %= 1000003;
    }
    cout << ans << endl;
}
