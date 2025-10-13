#include <iostream>
#include <cmath>
#include <string>

using namespace std;
string ReadText(string message) {
	string text = "";
	do {
		cout << message << endl;

		getline(cin, text);
	} while (text.length() < 0);


	return text;

}
string EncryptText(string text, short encryptionKey) {
	for (int i = 0; i <= text.length(); i++) {
		text[i] = char((int)text[i] + encryptionKey);
	}


	return text;
}

string DecryptText(string text, short encryptionKey) {


	for (int i = 0; i <= text.length(); i++) {
		text[i] = char((int)text[i] - encryptionKey);
	}


	return text;
}

int main()
{
	const short encryptionKey = 2;
	string text = ReadText("Enter a Text");
	string encryptedText = EncryptText(text, encryptionKey);
	string decryptedText = DecryptText(encryptedText, encryptionKey);

	cout << "the Original text is :" << text << endl;
	cout << "the Encrypted text is :" << encryptedText << endl;
	cout << "the Decrypted text is :" << decryptedText << endl;

	return 0;
}