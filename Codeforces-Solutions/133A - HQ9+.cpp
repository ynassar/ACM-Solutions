#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str; cin >> str;
    for(int i= 0; i < str.size(); i ++)
    {
        if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9')
        {
            cout << "YES" << endl; return 0;
        }
    }
    cout << "NO" << endl; return 0;
}
