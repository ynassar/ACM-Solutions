#include <bits/stdc++.h>
using namespace std;

bool areSame(char c, char d){
	return tolower(c) == tolower(d) || (tolower(c) == 'p' && tolower(d) == 'b') || (tolower(c) == 'b' && tolower(d) == 'p') || (tolower(c) == 'i' && tolower(d) == 'e') || (tolower(c) == 'e' && tolower(d) == 'i');
}
int main() {
	int t; cin >> t;
	while(t--){
		string str1, str2; cin >> str1 >> str2;
		if(str1.size() != str2.size())
			cout << "No" << endl;
		else{
			bool similar = true;
			for(int i = 0; i < str1.size() && similar; i ++){
				if(!areSame(str1[i], str2[i]))
					similar = false;
			}
			cout << ((similar) ? "Yes" : "No") << endl;
		}
	}
	return 0;
}
