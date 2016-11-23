#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	bool first = true;
	while(t--){
		if(!first)
			cout << endl;
		first = false;
		int b, sg, sb; cin >> b >> sg >> sb;
		int temp;
		priority_queue<int> greens, blues;
		for(int i = 0; i < sg; i ++){
			cin >> temp;
			greens.push(temp);
		}
		for(int i = 0; i < sb; i ++){
			cin >> temp;
			blues.push(temp);
		}
		queue<int> pendingBlues, pendingGreens;
		while(!greens.empty() && !blues.empty()){
			int ab = min(b,(int) min(greens.size(), blues.size()));
			for(int i = 0; i < ab; i ++){
				int blue = blues.top(); blues.pop();
				int green = greens.top(); greens.pop();
				if(blue > green)
					pendingBlues.push(blue - green);
				if(green > blue)
					pendingGreens.push(green - blue);
			}
			while(!pendingGreens.empty()) greens.push(pendingGreens.front()), pendingGreens.pop();
			
			while(!pendingBlues.empty()) blues.push(pendingBlues.front()), pendingBlues.pop();
		}
		if(greens.empty() && blues.empty()){
			cout << "green and blue died" << endl;;
		}
		else if(greens.empty()){
			cout << "blue wins" << endl;
			while(!blues.empty()){
				cout << blues.top() << endl;
				blues.pop();
			}
		}
		else{
			cout << "green wins" << endl;
			while(!greens.empty()){
				cout << greens.top() << endl;
				greens.pop();
			}
		}
	}
	return 0;
}
