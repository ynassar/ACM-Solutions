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
#include <stack>
#include <iomanip>
using namespace std;
 
int originalNumber;
int n;
int dpV[int(1e5 + 5)][105];
int dpA[int(1e5 + 5)][105];
void generatePlays(int number, int plays[]){
	int d1 = number % 10; number /= 10; int d2 = number % 10; number /= 10; int d3 = number % 10; number /= 10; int d4 = number % 10;
	plays[0] = (d1 + 1) % 10 + 10 * d2 + 100 * d3 + 1000 * d4;
	plays[1] = d1 + 10 * ((d2 + 1) % 10) + 100 * d3 + 1000 * d4;
	plays[2] = d1 + 10 * d2 + 100 *( ( d3 + 1) % 10) + 1000 * d4;
	plays[3] = d1 + 10* d2 + 100 * d3 + 1000 * ( ( d4 + 1) % 10);
}
bool isWinningA(int number, int moves);
bool isWinningV(int number, int moves);
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while(t--){
		memset(dpA, -1, sizeof dpA);
		memset(dpV, -1, sizeof dpV);
		cin >> originalNumber >> n;
		cout << (isWinningA(originalNumber, n) ? "Ada" : "Vinit") << endl;
	}
	return 0;
}
bool isWinningA(int number, int moves){
	if(moves == 0)
		return number > originalNumber;
	int& ref = dpA[number][moves];
	if(ref != -1)
		return ref;
	int plays[4];
	generatePlays(number, plays);
	for(int i = 0; i < 4; i ++){
		if(!isWinningV(plays[i], moves - 1))
			return ref = true;
	}
	return ref = false;
}
bool isWinningV(int number, int moves){
	if(moves == 0)
		return number <= originalNumber;
	int& ref = dpV[number][moves];
	if(ref != -1)
		return ref;
	int plays[4];
	generatePlays(number, plays);
	for(int i = 0; i < 4; i ++){
		if(!isWinningA(plays[i], moves - 1))
			return ref = true;
	}
	return ref = false;
}
