#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <set>
using namespace std;
#define MAXSZ 100005
long long n;
long long B1[MAXSZ], B2[MAXSZ];
void update(long long ft[],long long p,long long v){
	for (; p <= n; p += p&(-p))
		ft[p] += v;
}

void update(long long a,long long b,long long v){	
	update(B1, a, v);
	update(B1, b + 1, -v);	
	update(B2, a, v * (a-1));	
	update(B2, b + 1, -v * b);	 
}
long long query(long long ft[],long long b){ 	
	long long sum = 0;
	for(; b > 0; b -= b&(-b))
	sum += ft[b];
	return sum;
}

long long query(long long b){
  return query(B1, b) * b - query(B2, b);
}

long long query(long long a,long long b){
  return query(b) - query(a-1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	long long t; scanf("%lld", &t);
	while(t--)
	{
		memset(B1, 0, sizeof B1);
		memset(B2, 0, sizeof B2);
		long long c;
		scanf("%lld %lld", &n, &c);
		for(long long i = 0; i < c; i ++)
		{
			long long type, p, q, v;
			scanf("%lld", &type);
			if(type)
			{
				scanf("%lld %lld", &p, &q);
				printf("%lld\n", query(p,q));
			}
			else
			{
				scanf("%lld %lld %lld", &p, &q, &v);
				update(p,q,v);
			}
		}
	}
}
