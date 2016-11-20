#include <iostream>
using namespace std;

int main()
{
    int first[2005], second[2005];
    int n; cin >> n;
    for(int i = 0; i < n; i ++) cin >> first[i] >> second[i];
    int count = 0;
    for(int i = 0; i < n; i ++)
    {
        for(int j =i + 1; j < n; j ++)
        {
            for(int k = j + 1; k < n; k ++)
            {
                pair<int,int> v1 = make_pair(first[i] - first[j], second[i] - second[j]);
                pair<int,int> v2 = make_pair(first[i] - first[k], second[i] - second[k]);
                int cross = v1.first * v2.second - v2.first * v1.second;
                if(cross) count ++;
            }
        }
    }
    cout << count << endl;
}
