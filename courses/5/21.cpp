#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


enum enCharTypes {
	SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4
};
int RandomNumber(int from, int to) {
	int number = 0;

	number = rand() % (to - from + 1) + from;

	return number;
}

char RandomCharechter(enCharTypes type) {
	
	switch (type) {

	case enCharTypes::CapitalLetter:
		return RandomNumber('A', 'Z');

	case enCharTypes::SmallLetter:
		return RandomNumber('a', 'z');

	case enCharTypes::SpecialChar:
		return RandomNumber('!', '/');

	case enCharTypes::Digit:
		return RandomNumber('1', '9');

	}


}

string GenerateWord(enCharTypes type, short length) {
	string word = "";
	for (int i = 1; i <= length; i++) {
		word += RandomCharechter(type);
	}
	return word;
}


string GenerateKey() {
	string key = "";


	key = GenerateWord(enCharTypes::CapitalLetter, 4);
	key += "-" + GenerateWord(enCharTypes::CapitalLetter, 4);
	key += "-" + GenerateWord(enCharTypes::CapitalLetter, 4);
	key += "-" + GenerateWord(enCharTypes::CapitalLetter, 4);

	return key;
}

void PrintKeys(short number) {

	for (int i = 1; i <= number; i++) {
		cout << "Key Number [" << i << "] : "
			<< GenerateKey() << endl;
	}
}

int ReadPositiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;

		cin >> number;
	} while (number <= 0);


	return number;

}
int main()
{
	srand((unsigned)time(NULL));
	short number = ReadPositiveNumber("Enter How Many Keys You Want");



	PrintKeys(number);


	return 0;
}