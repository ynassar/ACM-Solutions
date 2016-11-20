#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int numof[26];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
#endif
    string str; cin >> str;
    deque<int> odds;
    for(int i = 0; i < str.size(); i ++)
        numof[str[i] - 'a'] ++;
    for(int i =0 ; i < 26; i ++)
    {
        if(numof[i] & 1)
        {
            odds.push_back(i);
        }
    }
    while(odds.size() > 1)
    {
        int back = odds.back();
        odds.pop_back();
        int front = odds.front();
        odds.pop_front();
        numof[back] --;
        numof[front] ++;
    }
    int mid = -1;
    stack<int> other_half;
    for(int i = 0; i < 26; i ++)
    {
        if(numof[i] & 1){
            mid = i;
        }
        for(int j = 0; j < numof[i] / 2; j ++)
        {
            cout << char(i + 'a');
            other_half.push(i);
        }
    }
    if(mid != -1) cout << char(mid + 'a');
    while(!other_half.empty()){
        cout << char(other_half.top() + 'a');
        other_half.pop();
    }
}
