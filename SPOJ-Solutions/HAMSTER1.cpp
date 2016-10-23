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
#include <sstream>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

int v, k, l;
double g = 10.0;
double getScore(double theta)
{
	return sin(2*theta) * k * (v * v) / g + l * (v*v * sin(theta) * sin(theta)) / (2*g);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int t; scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &v, &k, &l);
		double theta1 = atan( (l - sqrt(16.0 * k * k + l*l) ) / (4.0 * k));
		double theta2 = atan( (l + sqrt(16.0 * k * k + l*l) ) / (4.0 * k));
		if(getScore(theta1) > getScore(theta2))
			printf("%.3lf %.3lf\n", theta1, getScore(theta1));
		else
			printf("%.3lf %.3lf\n", theta2, getScore(theta2));
	}
}
