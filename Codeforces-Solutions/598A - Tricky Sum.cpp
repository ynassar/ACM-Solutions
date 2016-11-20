#include <iostream>
#include <string>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    int t; cin >> t;
    for(int i = 0; i < t; i ++)
    {
        long long n; cin >> n;
        long long power = 1;
        long long logbase2 = 0;
        while(power <= n)
        {
            //cout << "Log " << logbase2 << " power " << power << endl;
            power *= 2;
            logbase2 ++;
        }
        long long ans = n*( n + 1);
        ans /= 2;
        long long summation = 0;
        summation += 1 << (logbase2);
        summation --;
        ans -= 2 * summation;
        cout << ans << endl;
    }
}
