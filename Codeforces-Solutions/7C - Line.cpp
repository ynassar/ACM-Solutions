#include <iostream>
using namespace std;

long long A, B, C;
long long gcdex(long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcdex(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int main()
{
    cin >> A >> B >> C;
    C = -C;
    long long x, y;
    long long gcd = gcdex(A, B, x, y);
    if (C % gcd) cout << -1, exit(0);
    cout << x * (C / gcd) << " " << y * (C / gcd)<< endl;

}
