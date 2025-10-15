//#include <iostream>
//#include <cstdlib>
//#include <string>
//#include <vector>
//using namespace std;
//
//enum enCharTypes {
//	SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4
//};
//int RandomNumber(int from, int to) {
//	return rand() % (to - from + 1) + from;
//}
//
//char RandomCharechter(enCharTypes type) {
//
//	switch (type) {
//
//	case enCharTypes::CapitalLetter:
//		return RandomNumber('A', 'Z');
//
//	case enCharTypes::SmallLetter:
//		return RandomNumber('a', 'z');
//
//	case enCharTypes::SpecialChar:
//		return RandomNumber('!', '/');
//
//	case enCharTypes::Digit:
//		return RandomNumber('1', '9');
//
//	}
//
//
//}
//
//string GenerateWord(enCharTypes type, short length) {
//	string word = "";
//	for (int i = 1; i <= length; i++) {
//		word += RandomCharechter(type);
//	}
//	return word;
//}
//
//
//string GenerateKey() {
//	string key = "";
//
//
//	key = GenerateWord(enCharTypes::CapitalLetter, 4);
//	key += "-" + GenerateWord(enCharTypes::CapitalLetter, 4);
//	key += "-" + GenerateWord(enCharTypes::CapitalLetter, 4);
//	key += "-" + GenerateWord(enCharTypes::CapitalLetter, 4);
//
//	return key;
//}
//
//
//
//int ReadPositiveNumber(string message) {
//	int number = 0;
//	do {
//		cout << message << endl;
//
//		cin >> number;
//	} while (number <= 0);
//
//
//	return number;
//
//}
//
//vector<string> FillArrayWithKeys(short length) {
//
//	vector<string> numbers;
//
//
//	for (int i = 1; i <= length; i++) {
//
//
//		numbers.push_back(GenerateKey());
//	}
//
//	return numbers;
//}
//
//
//
//void PrintArray(vector<string> array, string message) {
//
//	if (array.size() == 0) {
//		message += " Empty";
//	}
//
//	cout << message << endl;
//
//
//	for (int i = 0; i < array.size(); i++) {
//
//		cout << "Array[" << i << "]: " << array[i] << endl;
//
//
//	}
//	cout << endl;
//
//
//
//}
//
//
//
//
//int main()
//{
//	srand((unsigned)time(NULL));
//
//	short lengthOfArray = ReadPositiveNumber("Enter How Many Elements You Want");
//
//	vector<string> array = FillArrayWithKeys(lengthOfArray);
//
//	PrintArray(array, "Array 1: \t");
//
//
//
//
//	return 0;
//}