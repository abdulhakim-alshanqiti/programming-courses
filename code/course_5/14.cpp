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
//// the instructor solution
//
//void PrintInvertedLetterPattern(int number) {
//	cout << endl;
//	for (int i = 65 + number - 1; i >= 65; i--) {
//
//		for (int j = 1; j <= number - ((65 + number - 1) - i); j++)
//		{
//			cout << char(i);
//		}
//		cout << endl;
//
//	}
//
//}
//// my solution
//
////void PrintInvertedLetterPattern(int number) {
////	cout << endl;
////	for (int i = number; i >= 1; i--) {
////		for (int j = 1; j <= i; j++) {
////			cout << char(i + 64);
////		} cout << endl;
////	}
////}
//int main()
//{
//	int number = ReadPositiveNumber("Please Enter a Number");
//	PrintInvertedLetterPattern(number);
//	return 0;
//}