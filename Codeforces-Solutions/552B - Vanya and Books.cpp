#include <iostream>
using namespace std;

int pow(int num, int power)
{
    int ans = 1;
    for(int i= 0 ; i < power; i ++) ans *= num;
    return ans;
}
int main()
{
    long long int n; cin >> n;
    bool done = false;
    long long int num = 1, count = 0;
    long long int ans = 0;
    while(n / num >= 10)
    {
        ans += 9 * pow(10,count) * (count + 1);
        count ++;
        num *= 10;
    }
    ans += (count + 1) * (n - (num - 1));
    cout << ans << endl;
}
