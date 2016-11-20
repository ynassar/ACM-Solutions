#include <iostream>
#include <string>
using namespace std;

string first, second;
int main()
{
     cin >> first >> second;
     int fours =0, sevens = 0;
     for(int i = 0; i < second.size(); i ++)
     {
         if(first[i] == second[i]) continue;
         if(second[i] == '4') fours ++; if(second[i] == '7') sevens++;
     }
     cout << fours + sevens - ((fours >=sevens) ? sevens : fours) << endl;
}
