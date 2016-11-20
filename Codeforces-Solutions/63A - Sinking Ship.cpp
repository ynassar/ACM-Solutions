#include <iostream>
#include <string>
using namespace std;

int main()
{
    string arr[105];
    int priorities[105];
    bool taken[105];
    int n; cin >> n;
    string temp;
    for(int i = 0; i < n; i ++)
    {
        cin >> arr[i];
        cin >> temp;
        if(temp == "rat") priorities[i] = 4;
        else if(temp == "woman" || temp == "child") priorities[i] = 3;
        else if(temp == "man") priorities[i] = 2;
        else priorities[i] = 1;
        taken[i] = false;
    }
    for(int i = 0; i < n; i ++)
    {
        int mval = -1; int next;
        for(int j = 0; j < n; j ++)
        {
            if(taken[j]) continue;
            if(priorities[j] > mval)
            {
                mval = priorities[j]; next = j;
            }
        }
        taken[next] = true;
        cout << arr[next] << endl;
    }
}
