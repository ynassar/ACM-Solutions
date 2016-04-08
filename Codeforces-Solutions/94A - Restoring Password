#include <iostream>
#include <string>
using namespace std;

int decrypt(string encryptedString, string encryptionOf[10]);
int main()
{
	string encryptedPassword;
	cin >> encryptedPassword;
	string encryptionOf[10];
	for(int i = 0; i < 10; i ++)
		cin >> encryptionOf[i];

	for(int i = 0; i < encryptedPassword.size(); i += 10)
		cout << decrypt(encryptedPassword.substr(i, 10), encryptionOf);
}
int decrypt(string encryptedString, string encryptionOf[10])
{
	for(int i = 0; i < 10; i ++)
		if(encryptionOf[i] == encryptedString)
			return i;
}
