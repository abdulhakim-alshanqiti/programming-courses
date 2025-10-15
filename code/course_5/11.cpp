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
//int ReverseDigit(int number) {
//	int remainder = 0;
//	int reversedNumber = 0;
//	while (number > 0) {
//		remainder = number % 10;
//		number /= 10;
//		reversedNumber = reversedNumber * 10 + remainder;
//	}
//	return  reversedNumber;
//}
//bool IsPalindromeNumber(int number) {
//	return	ReverseDigit(number) == number;
//}
//
//
//
//
//
//int main()
//{
//	int number = ReadPositiveNumber("Please Enter a Number");
//
//	if (IsPalindromeNumber(number))
//		cout << "the number " << number << " is a Palindrome Number" << endl;
//	else
//		cout << "the number " << number << " is Not a Palindrome Number" << endl;
//
//
//	return 0;
//}