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

int DigitFrequency(int number, short digitToCheck) {


	int remainder = 0, frequency = 0;

	while (number > 0) {
		remainder = number % 10;
		number /= 10;

		if (remainder == digitToCheck)
			frequency++;

	}

	return frequency;
}

void NumbersFrequency(int number) {

	for (int i = 0, short frequency = 0; i <= 9; i++) {

		frequency = DigitFrequency(number, i);

		if (frequency > 0)
		{
			cout << "Digit " << i << " frequency is " << frequency << endl;
		}
	}


}




int main()
{
	int number = ReadPositiveNumber("Please Enter a Number");

	NumbersFrequency(number);

	return 0;
}