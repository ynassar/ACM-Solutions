#include <iostream>
using namespace std;

long long dist_from_end[int(1e5 + 5)], dist_from_start[int(1e5 + 5)];
int main()
{
    long long n; cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        long long temp; cin >> temp;
        if (!dist_from_start[temp]) dist_from_start[temp] = i;
        dist_from_end[temp] = (n - i) + 1;
    }
    long long m; cin >> m;
    long long start = 0, end = 0;
    for (long long i = 0; i < m; i++)
    {
        long long query; cin >> query;
        start += dist_from_start[query];
        end += dist_from_end[query];
    }
    cout << start << " " << end << endl;
}
