/*
	To find out whether a word can be made into "hello" or not, we need to check if there are the letters "h", "e", "l", "l", and
	"o" in that order contained in the word. To check this, we loop over the string with an integer representing the number of
	the letter in the string "hello" that is supposed to come next. If we find this letter, increment the integer. If the integer
	reaches the length of the word "hello", that means that the letters of "hello" were found in that order, and we can make the
	word into "hello".
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string attemptedHello;
	cin >> attemptedHello;
	string actualHello = "hello";
	int letterNumber = 0;
	bool canSayHello = false;
	for(int i = 0; i < attemptedHello.size() && !canSayHello; i ++)
	{
		if(attemptedHello[i] == actualHello[letterNumber])
			letterNumber ++;
		if(letterNumber == actualHello.size())
			canSayHello = true;
	}
	if(canSayHello)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
