#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int ReadPositiveNumber(string message) {
	int number = 0;
	do {
		cout << message << endl;

		cin >> number;
	} while (number <= 0);


	return number;

}

int ReverseNumber(int number) {
	int remainder = 0, reversed_number = 0;

	while (number > 0) {
		remainder = number % 10;
		number = number / 10; // if the divison is bettwen 1 and 0 for example 0.3,0.7 etc the compiler will make the result 0 because the result is stored in an integer so it truncates the decimals 0.4 -> 0

		reversed_number = reversed_number * 10 + remainder;
		cout << reversed_number << endl;


	}

	return reversed_number;
}
int main()
{
	int number = ReadPositiveNumber("Please Enter a Number");


	return 0;
}