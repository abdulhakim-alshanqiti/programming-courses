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
enPrimeNotPrime CheckPrime(int number) {
	int M = number / 2;

	for (int i = 2; i <= M; i++) {
		if (number % i == 0) 
			return enPrimeNotPrime::NotPrime;
		
	}
	return enPrimeNotPrime::Prime;
}



void PrintPrimeNumbers1toN(int number) {
	cout << "PrimeNumbers From 1 to " << number << endl;
	for (int i = 1; i <= number; i++) {

		if (CheckPrime(i) == enPrimeNotPrime::Prime) {
			cout << i << endl;
		}
	}

}
int main()
{
	int number = ReadPositiveNumber("Please Enter a Number!");

	PrintPrimeNumbers1toN(number); return 0;

}
