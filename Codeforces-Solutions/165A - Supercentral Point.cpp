#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int x[250], y[250];
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool right = false, left = false, up = false, down = false;
        int thisx = x[i], thisy = y[i];
        for (int j = 0; j < n; j++)
        {
            if (x[j] == thisx)
            {
                if (y[j] > thisy)
                    up = true;
                if (y[j] < thisy)
                    down = true;
            }
            else if (y[j] == thisy)
            {
                if (x[j] > thisx) right = true;
                if (x[j] < thisx) left = true;
            }
        }
        if (up && down && left && right) count++;
    }
    cout << count << endl;
} 
