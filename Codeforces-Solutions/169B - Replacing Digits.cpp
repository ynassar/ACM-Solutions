#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string seq;
    string num;
    cin >> num >> seq;
    sort(seq.rbegin(), seq.rend());
    int seqidx = 0;
    for(int i = 0; i < num.size(); i ++)
    {
        if(seq[seqidx] > num[i])
        {
            num[i] = seq[seqidx++];
        }
    }
    cout << num << endl;
}
