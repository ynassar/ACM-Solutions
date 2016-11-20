#include <iostream>
#include <string>
using namespace std;


int main()
{
    string word; cin >> word;
    bool iswrong = true;
    for(int i = 1; i < word.size(); i ++)
    {
        if(toupper(word[i]) != word[i])
        {
            iswrong = false; break;
        }
    }
    if(iswrong)
    {
        for(int i = 0; i < word.size(); i ++)
        {
            if(word[i] == tolower(word[i])) cout << char(toupper(word[i]));
            else if(word[i] == toupper(word[i])) cout << char(tolower(word[i]));
        }
    }
    else cout << word;
}
