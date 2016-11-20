#include <iostream>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int sum=0,My_sum=0,n,x;
	cin>>n;
    vector<int>l;
	l.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
		sum+=l[i];
	}
	sort(l.rbegin(), l.rend());
	for(int j=0;j<n;j++)
	{
		My_sum+=l[j];
		if(My_sum>(sum-My_sum)){
			cout<<j+1;
			return 0;
		}
	}

	return 0;
}
