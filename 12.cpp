// this is my version using recursion

//#include <iostream>
//using namespace std;
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
//void InvertedPattern(int number) {
//	int inverted = 0;
//	for (int i = 1; i <= number; i++) {
//		inverted = inverted * 10 + number;
//	}
//
//	if (number == 1) {
//		cout << 1 << endl;
//		return;
//	}
//
//	cout << inverted << endl;
//
//	InvertedPattern(number - 1);
//}
//
//int main() {
//	int number = ReadPositiveNumber("Please Enter a Number");
//	InvertedPattern(number);
//	return 0;
//}

// this is my version using nested for loops (this one gets an actual reversed numbers

//#include <iostream>
//using namespace std;
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
//void InvertedPattern(int number) {
//	for (int i = number; i >= 1; i--) {
//		int inverted = 0;
//
//		for (int j = i; j >= 1; j--) {
//			inverted = inverted * 10 + i;
//		}
//
//		cout << inverted << endl;
//	}
//}
//
//int main() {
//	int number = ReadPositiveNumber("Please Enter a Number");
//	InvertedPattern(number);
//	return 0;
//}


//#include <iostream>
//#include <cmath>
//#include <string>
//
//using namespace std;
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
//
//
//
//void PrintNumberPattern(int number) {
//	cout << endl;
//	for (int i = number; i >= 1; i--) {
//
//		for (int j = i; j >= 1; j--) {
//			cout << i;
//		};
//
//		cout << endl;
//
//	}
//
//}
//
//int main()
//{
//	int number = ReadPositiveNumber("Please Enter a Number");
//	PrintNumberPattern(number);
//	return 0;
//}