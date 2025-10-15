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
//int SumDigits(int number) {
//	int remainder = 0, sum = 0;
//	while (number > 0) {
//		remainder = number % 10;
//		number = number / 10; // if the divison is bettwen 1 and 0 for example 0.3,0.7 etc the compiler will make the result 0 because the result is stored in an integer so it truncates the decimals 0.4 -> 0
//
//		cout << remainder << endl;
//		sum += remainder;
//
//
//	}
//
//	return sum;
//}
//int main()
//{
//	int number = ReadPositiveNumber("Please Enter a Number");
//
//	cout <<"Sum Of The Digits = " << SumDigits(number) << endl;
//
//
//	return 0;
//}