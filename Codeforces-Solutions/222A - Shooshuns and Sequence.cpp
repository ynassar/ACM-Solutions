#include <iostream>
using namespace std;

int main()
{
    int arr[int(1e5 + 1)];
    int n, k; cin >> n >> k; k --;
    for(int i = 0; i < n; i ++) cin >> arr[i];
    int kelement = arr[k];
    for(int i = k + 1; i < n; i ++)
    {
        if(arr[i] != kelement)
        {
            cout << -1 << endl; return 0;
        }
    }
    int idx  = -1;
    for(int i = 0; i < k; i ++)
    {
        if(arr[i] != kelement) idx = i;
    }
    cout << idx + 1 << endl;
}
