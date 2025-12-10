#include <iostream>
#include<string>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace Strings;
using namespace std;


bool IsVowel(char Char) {
	Char = tolower(Char);
	return ((Char == 'a') || (Char == 'e') || (Char == 'i') || (Char == 'o') || (Char == 'u'));
}

short CountVowelsInString(string String) {
	short Counter = 0;
	for (short i = 0; i < String.length(); i++)
	{
		if (IsVowel(String[i]))
			Counter++;

	}
	return Counter;
}
int main() {

	string String = ReadStringWS("Pick a String");
	int result = CountVowelsInString(String);

	cout << "The Number Of Vowels In The String \"" + String + "\"  : " << result;


	return 0;
}