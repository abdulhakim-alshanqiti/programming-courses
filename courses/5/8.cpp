//#include <iostream>
//#include <cmath>
//#include <string>
//
//using namespace std;
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
//int DigitFrequency(int number, short digitToCheck) {
//
//
//	int remainder = 0, frequency = 0;
//
//	while (number > 0) {
//		remainder = number % 10;
//		number /= 10;
//
//		if (remainder == digitToCheck)
//			frequency++;
//
//	}
//
//	return frequency;
//}
//
//int main()
//{
//	int number = ReadPositiveNumber("Please Enter a Number");
//	short digit = ReadPositiveNumber("Please Enter a Number"); // short is the smallest container we can get for this number that would be one number bettwen 0-9
//
//	cout << "Digit " << digit << " frequency is " << DigitFrequency(number, digit) << " in the number: " << number << endl;
//
//	return 0;
//}