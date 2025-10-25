#include <iostream>
#include <string>
using namespace std;

enum enPrimeNotPrime {
	Prime = 1, NotPrime = 2
};

int ReadPositiveNumber(string message) {
	int n = 0;
	do {
		cout << message << endl;

		cin >> n;
	} while (n <= 0);

	return n;
}


void PrintPrimeNumbers1toN(int number) {
	cout << "Numbers From 1 to " << number << endl;
	for (int i = 1; i <= number; i++) {


		cout << i << endl;

	}

}
int main()
{
	int number = ReadPositiveNumber("Please Enter a Number!");

	PrintPrimeNumbers1toN(number); return 0;

}

