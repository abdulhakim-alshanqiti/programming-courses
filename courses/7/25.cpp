#include <iostream>
#include<string>
#include "../../libs/MyLib.h"
#include <vector>
using namespace Input;
using namespace std;




string LowerFirstLetterOfEachWord(string S1) {
	bool isFirstLetter = true;
	for (int i = 0; i < S1.length(); i++)
	{
		if (isFirstLetter && S1[i] != ' ')
			S1[i] = tolower(S1[i]);


		isFirstLetter = (S1[i] == ' ' ? true : false);

	}
	return S1;
}

int main() {

	string myString = ReadStringWS("Enter a String");


	myString = LowerFirstLetterOfEachWord(myString);
	cout << myString << endl;


	return 0;
}