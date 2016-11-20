#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2; cin >> str1 >> str2;
    int numdiffs =0;
    int diffidx;
    char diffchar, shouldbe;
    if(str1.size() != str2.size())
    {
        cout << "NO" << endl; exit(0);
    }
    for(int i = 0; i < str1.size(); i ++)
    {
        if(str1[i] != str2[i])
        {
            numdiffs++;
            diffchar = str1[i];
            shouldbe = str2[i];
        }
    }
    if(numdiffs > 2)
    {
        cout << "NO" << endl; exit(0);
    }
    for(int i = 0; i < str1.size(); i ++)
    {
        if(str2[i] == diffchar && str1[i] == shouldbe)
        {
            cout << "YES" << endl; exit(0);
        }
    }
    cout << "NO" << endl; exit(0);
}
