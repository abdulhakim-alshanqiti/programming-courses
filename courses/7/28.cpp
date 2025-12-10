#include <iostream>
#include<string>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace Strings;
using namespace std;


string InvertAllLettersCase(string myString) {
	for (int i = 0; i < myString.length(); i++) {
		myString[i] = InvertCase(myString[i]);
	}
	return myString;
}

int main() {

	string myString = ReadStringWS("Enter a Sentence");
	system("cls");
	cout << "String before Inversion \n\n" << myString << "\n\n";

	cout << "String After Inversion \n\n" << InvertAllLettersCase(myString) << "\n\n";
	return 0;
}