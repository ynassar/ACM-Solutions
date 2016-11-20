#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string removezeroes(const string& s)
{
    string ret = "";
    for(int i = 0; i < s.size(); i ++)
    {
        if(s[i] != '0') ret += s[i];
    }
    return ret;
}
int main()
{
    string a, b, c;
    int cval;
    cin >> a >> b;
    cval = atoi(a.c_str()) + atoi(b.c_str());
    stringstream ss;
    ss << cval;
    c = ss.str();
    a = removezeroes(a), b = removezeroes(b), c= removezeroes(c);
    if(atoi(c.c_str()) == atoi(a.c_str()) + atoi(b.c_str())) cout << "YES" << endl;
    else cout << "NO" << endl;
}
