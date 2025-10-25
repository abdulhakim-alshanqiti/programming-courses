//#include <iostream>
//#include <cmath>
//#include <string>
//
//using namespace std;
//
//int ReadNumber(string message) {
//	int number = 0;
//	cout << message << endl;
//
//	cin >> number;
//	return number;
//
//}
//
//void reverse_string(string text) {
//	int length = text.length();
//	for (int i = length; i >= 0; i--) {
//		cout << text[i] << endl;
//	}
//
//}
//int main()
//{
//	int number = ReadNumber("Please Enter a Number");
//
//	reverse_string(to_string(number));
//
//
//	return 0;
//}
//// The code above is my code ^ and the code below is my instructor code

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
//void PrintDigits(int number) {
//	int remainder = 0;
//
//	while (number > 0) {
//		remainder = number % 10;
//		number = number / 10; // if the divison is bettwen 1 and 0 for example 0.3,0.7 etc the compiler will make the result 0 because the result is stored in an integer so it truncates the decimals 0.4 -> 0
//		cout << remainder << endl;
//	}
//
//}
//int main()
//{
//	int number = ReadPositiveNumber("Please Enter a Number");
//
//	PrintDigits(number);
//
//
//	return 0;
//}