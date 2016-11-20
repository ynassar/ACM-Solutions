#include <iostream>
using namespace std;

int arr[100][100];

int main()
{
    int n; cin >>n;
    int x1, y1, x2, y2;
    int sum = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        sum += abs(y2 - y1 + 1) *abs(x2 - x1 + 1);
    }
    cout << sum << endl;
}
