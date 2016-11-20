#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int floordiv(int a, int b)
{
    if(a > 0) return a / b;
    return (a / b) - 1;
}

int arr[int(1e6)];
int min_differences[int(1e6 + 5)];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int n; cin >> n;
    int sum = 0;
    for(int i =0; i < n; i ++) cin >> arr[i], sum += arr[i];
    sort(arr, arr+n);
    int startingEstimate = floordiv((sum - 1), n);
    startingEstimate ++;
    bool started = false;
    for(int i = n - 1; i >= 0; i --)
    {
        if(startingEstimate - 1)
        {
            if(sum % (startingEstimate - 1) == 0 && sum / (startingEstimate - 1) == i + 1)
            {
                started = true;
            }
        }
        else
        {
            if(sum == 0) started = true;
        }
        if(started){
            min_differences[i] = startingEstimate - 1;
        }
        else{
            min_differences[i] = startingEstimate;
            sum -= startingEstimate;
        }
    }
    int differences = 0;
    for(int i = 0; i < n; i ++)
    {
        differences += abs(min_differences[i] - arr[i]);
    }
    cout << differences / 2 << endl;
}
