#include <map>
#include <iostream>
using namespace std;

map<long long,long long> numof;
int main()
{
    long long n; cin >> n;
    long long temp;
    for(long long i = 0; i< n; i ++)
    {
        cin >> temp;
        numof[temp]++;
    }
    long long ans = (numof[0]) * (numof[0] - 1) / 2;
    for(long long i = 1; i <= 10; i ++)
    {
        ans += numof[i] * numof[-i];
    }
    cout << ans << endl;
}
