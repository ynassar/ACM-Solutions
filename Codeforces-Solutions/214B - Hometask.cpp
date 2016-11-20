#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numof[10];
int main()
{
    int n; cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i ++)
    {
        int temp; cin >> temp;
        numof[temp] ++;
        sum += temp;
    }
    if(!numof[0])
    {
        cout << -1; exit(0);
    }
    if(sum % 3 == 1)
    {
        bool found = false;
        for(int i = 0; i < 10; i ++)
        {
            if(i % 3 == 1 && numof[i])
            {
                numof[i] --;
                found = true;
                sum -= i;
                break;
            }
        }
        if(!found)
        {
            int numfound = 0;
            for(int i= 0; i < 10; i ++)
            {
                if(i % 3 == 2 && numof[i])
                {
                    numof[i] --;
                    numfound ++;
                    sum -= i;
                    i = 0;
                }
                if(numfound == 2) break;
            }
            if(numfound != 2){
                cout << 0; exit(0);
            }
        }
    }
    else if(sum % 3 == 2)
    {
        bool found = false;
        for(int i = 0; i < 10 ; i ++)
        {
            if(i % 3 == 2 && numof[i])
            {
                numof[i] --;
                found = true;
                sum -= i;
                break;
            }
        }
        if(!found)
        {
            int numfound = 0;
            for(int i= 0; i < 10; i ++)
            {
                if( i % 3 == 1 && numof[i])
                {
                    numof[i] --;
                    numfound ++;
                    sum -= i;
                    i = 0;
                }
                if(numfound == 2) break;
            }
            if(numfound != 2){
                cout << 0; exit(0);
            }
        }
    }
    bool zero = true;
    for(int i = 1; i < 10; i ++)
    {
        if(numof[i]) zero = false;
    }
    if(zero)
    {
        cout << 0;
        exit(0);
    }
    for(int i = 9; i >= 0; i --)
    {
        for(int j = 0; j < numof[i]; j++) cout << i;
    }
}
