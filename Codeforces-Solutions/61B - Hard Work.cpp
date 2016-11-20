#include <iostream>
#include <string>
#include <vector>
using namespace std;

string first, second, third;
vector<string> permutations;
void generate_permutations()
{
    permutations.push_back(first + second + third);
    permutations.push_back(first + third + second);
    permutations.push_back(second + first + third);
    permutations.push_back(second + third + first);
    permutations.push_back(third + first + second);
    permutations.push_back(third + second + first);
}
void strip(string& str)
{
    string ret = "";
    for(int i = 0; i < str.size(); i ++)
    {
        if(tolower(str[i]) >= 'a' && tolower(str[i]) <= 'z') ret += tolower(str[i]);
    }
    str = ret;
}

int main()
{
    cin >> first >> second >> third;
    strip(first);
    strip(second);
    strip(third);
    generate_permutations();
    int n; cin >> n;
    for(int i = 0; i < n; i ++)
    {
        string ans;
        cin >> ans;
        strip(ans);
        bool works = false;
        for(int i = 0; i < 6; i ++)
        {
            if(ans == permutations[i])
            {
                works = true; break;
            }
        }
        cout << ((works) ? "ACC" : "WA") << endl;
    }
}
