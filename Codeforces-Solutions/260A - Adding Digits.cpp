#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int  b, n; cin >> a >> b >> n;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < 10; j ++)
        {
            if(i == 0)
            {
                a.push_back(j + '0'); 
                if (atoi(a.c_str()) % b == 0)
                    break;
                else
                {
                    if(j == 9) 
                    {
                        cout << -1<< endl; return 0;
                    }
                    a.pop_back();
                    continue;
                }
            }
            if(j % b == 0)
            {
                a.push_back(j + '0');
                break;
            }
            if(j == 9) 
            {
                cout << -1<< endl; return 0;
            }
        }
    }
    cout << a << endl; return 0;
}
