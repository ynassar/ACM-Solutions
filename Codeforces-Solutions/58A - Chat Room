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
