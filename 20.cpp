//#include <iostream>
//#include <cstdlib>
//#include <string>
//
//using namespace std;
//
//
//enum enCharTypes {
//	SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4
//};
//int RandomNumber(int from, int to) {
//	int number = 0;
//
//	number = rand() % (to - from + 1) + from;
//
//	return number;
//}
//
//char RandomCharechter(enCharTypes type) {
//	int randomChar = 0;
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
//int main()
//{
//	srand((unsigned)time(NULL));
//
//
//	cout << RandomCharechter(enCharTypes::SmallLetter) << endl;
//	cout << RandomCharechter(enCharTypes::CapitalLetter) << endl;
//	cout << RandomCharechter(enCharTypes::SpecialChar) << endl;
//	cout << RandomCharechter(enCharTypes::Digit) << endl;
//
//
//	return 0;
//}