#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int t; cin >> t;
	while(t--)
	{
		double u, v, w, U, V, W;
		cin >> u >> v >> w >> W >> V >> U;
		double a =4*(pow(u,2)*pow(v,2)*pow(w,2)) - pow(u,2)*pow((pow(v,2)+pow(w,2)-pow(U,2)),2) - pow(v,2)*pow((pow(w,2)+pow(u,2)-pow(V,2)),2) - pow(w,2)*pow((pow(u,2)+pow(v,2)-pow(W,2)),2) + (pow(v,2)+pow(w,2)-pow(U,2))*(pow(w,2)+pow(u,2)-pow(V,2))*(pow(u,2)+pow(v,2)-pow(W,2));
		double vol = sqrt(a) / 12.0;
		printf("%.4lf\n", vol);
	}
	return 0;
}
