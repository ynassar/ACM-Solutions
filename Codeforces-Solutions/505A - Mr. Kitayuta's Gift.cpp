#include <string>
#include <iostream>
#include <fstream>
using namespace std;

bool isPalindrome(const string& str)
{
	for(int i = 0; i < str.size() / 2; i ++)
	{
		if(str[i] != str[str.size() - 1 - i]) return false;
	}
	return true;
}
int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("input.txt");
#endif
	string toMakePalindrome; cin >> toMakePalindrome;

	for(int i = 0; i <= toMakePalindrome.size(); i ++)
	{
		for(char character = 'a'; character <= 'z'; character ++)
		{
			string toInsert = "";
			toInsert += character;
			toMakePalindrome.insert(i, toInsert);
			if(isPalindrome(toMakePalindrome))
				cout << toMakePalindrome << endl, exit(0);
			toMakePalindrome.erase(i, 1);
		}
	}
	cout << "NA" << endl;
}
