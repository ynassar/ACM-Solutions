#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str; cin >> str;
    int ones = 0, zeroes= 0;
    for(int i= 0; i < str.size(); i ++)
    {
        if(str[i] == '1')
        {
            ones ++; zeroes = 0;
        }
        if(str[i] == '0')
        {
            zeroes++; ones = 0;
        }
        if(zeroes == 7 || ones == 7)
        {
            cout << "YES" << endl; return 0;
        }
    }
    cout << "NO" << endl; return 0;
}
