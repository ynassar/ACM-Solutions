#include <iostream>
using namespace std;

int main()
{
    int t, s ,q; cin >> t >> s >> q;
    double commonratio = ((q - 1) * 1.f) / (q * 1.f);
    int count = 0;
    double downloaded = s * 1.f;
    while( t - downloaded > 0.005)
    {
        downloaded = (downloaded * 1.f) / (1.f - commonratio);
        count ++;
    }
    cout << count << endl;
}
