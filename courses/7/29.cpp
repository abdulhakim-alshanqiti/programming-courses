#include <iostream>
#include<string>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace Strings;
using namespace std;


short CountUpperCaseLetters(string myString) {
	short counter = 0;
	for (short i = 0; i < myString.length(); i++) {
		if (isupper(myString[i]))
			counter++;
	}
	return counter;
}

short CountLowerCaseLetters(string myString) {
	short counter = 0;
	for (short i = 0; i < myString.length(); i++) {
		if (islower(myString[i]))
			counter++;
	}
	return counter;
}

enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) {
	if (WhatToCount == enWhatToCount::All) {
		return S1.length();
	}
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++) {
		if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))             Counter++;
		if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))             Counter++;
	} return Counter;
}

int main() {
	string S1 = ReadStringWS("Write a Sentence");

	cout << "\nString Length = " << S1.length();
	cout << "\nCapital Letters Count= " << CountUpperCaseLetters(S1);
	cout << "\nSmall Letters Count= " << CountLowerCaseLetters(S1);
	cout << "\n\nMethod 2\n";
	cout << "\nString Length = " << CountLetters(S1);
	cout << "\nCapital Letters Count= " << CountLetters(S1, enWhatToCount::CapitalLetters);
	cout << "\nSmall Letters Count= " << CountLetters(S1, enWhatToCount::SmallLetters);

}