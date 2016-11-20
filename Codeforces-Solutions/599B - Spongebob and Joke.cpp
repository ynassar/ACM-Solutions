#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> f[(int) 1e5 +5];

bool compare(pair<int, int> a, int b)
{
    return a.first < b;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int b[int(1e5 +5)], a[int(1e5 +5)];
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i ++)
    {
        cin >> f[i].first;
        f[i].second = i;
    }
    for(int i = 0; i < m; i ++)
    {
        cin >> b[i];
    }
    sort(f, f+ n);
    bool ambiguity = false;
    bool impossible = false;
    for(int i = 0; i < m; i ++)
    {
        int currentElementIdx = lower_bound(f, f + n, b[i], compare) - f;
        int currentElement = f[currentElementIdx].second;
        if(f[currentElementIdx].first != b[i]){
            impossible = true;
            //cout << "Impossible" << endl; exit(0);
        }
        if(f[currentElementIdx + 1].first == b[i]){
            ambiguity = true;
            //cout << "Ambiguity" << endl; exit(0);
        }
        a[i] = currentElement;
    }
    if(impossible){
        cout << "Impossible" << endl; exit(0);
    }
    if(ambiguity){
        cout << "Ambiguity" << endl; exit(0);
    }
    cout << "Possible" << endl;
    for(int i = 0; i < m; i ++) cout << a[i] + 1<< " ";
}
