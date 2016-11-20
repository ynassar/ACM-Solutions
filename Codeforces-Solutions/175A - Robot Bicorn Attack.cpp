#include <iostream>
#include <string>
using namespace std;

string str;
string substring(int start, int end)
{
    string ret = "";
    for(int i = start; i < end; i ++)
    {
        ret += str[i];
    }
    return ret;
}
bool isValid(const string& s)
{
    if(s == "0") return true;
    return !(s[0] == '0') && (atoi(s.c_str()) <= 1e6);
}
int main()
{
     cin >> str;
    int i = 0;
    long long mval = -1;
    for(int j = i + 1; j < str.size(); j ++)
    {
        for(int k = j + 1; k < str.size(); k ++)
        {
            string first = substring(0, j), second = substring(j, k), third = substring(k, str.size());
            if(isValid(first) && isValid(second) && isValid(third))
            {
                long long cur = atoi(first.c_str()) + atoi(second.c_str()) + atoi(third.c_str());
                mval = max(mval, cur);
            }
        }
    }
    cout << mval << endl;
}
