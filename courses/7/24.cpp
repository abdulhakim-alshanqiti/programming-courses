#include <iostream>
#include<string>
#include "../../Libs/MyLib.h"
#include <vector>
using namespace Input;
using namespace std;




string UpperFirstLetterOfEachWord(string S1) {
	bool isFirstLetter = true;
	for (int i = 0; i < S1.length(); i++)
	{
		if (isFirstLetter && S1[i] != ' ')
			S1[i] = toupper(S1[i]);


		isFirstLetter = (S1[i] == ' ' ? true : false);

	}
	return S1;
}

int main() {

	string myString = ReadStringWS("Enter a String");


	myString = UpperFirstLetterOfEachWord(myString);
	cout << myString << endl;


	return 0;
}