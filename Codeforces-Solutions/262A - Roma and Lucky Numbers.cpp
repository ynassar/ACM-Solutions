#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    string str;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int cnt = 0;
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '4' || str[j] == '7') cnt++;
        }
        if (cnt <= k) ans++;
    }
    cout << ans;
}
