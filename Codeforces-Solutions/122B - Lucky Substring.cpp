#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str; cin >> str;
    int numfours =0 , numsevens =0;
    for(int i = 0; i < str.size(); i ++)
    {
        if(str[i] == '4') numfours ++;
        if(str[i] == '7') numsevens++;
    }
    if(!numfours && !numsevens)
    {
        cout << -1; exit(0);
    }
    if(numfours >= numsevens) cout << '4';
    else cout << '7';
}
