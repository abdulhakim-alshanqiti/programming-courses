



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



/// this is my version using nested for loops (this one gets an actual reversed numbers


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

/// this is my version using recursion
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

void PrintNumberPattern(int number) {
	cout << endl;
	for (int i = number; i >= 1; i--) {

		for (int j = i; j >= 1; j--) {
			cout << i;
		};

		cout << endl;

	}

}

int main()
{
	int number = ReadPositiveNumber("Please Enter a Number");
	PrintNumberPattern(number);
	return 0;
}