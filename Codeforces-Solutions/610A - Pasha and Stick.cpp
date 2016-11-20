#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n; cin >> n;
    if(n % 2){
        cout << 0 << endl; exit(0);
    }
    else{
        if(n % 4)
            cout << n / 4 << endl;
        else cout << (n / 4) - 1 << endl;
    }
}
