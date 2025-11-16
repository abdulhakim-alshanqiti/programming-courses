#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

float GetFractionPart(float number) {
	return number - int(number);
}
float myRound(float number) {

	int intPart = int(number);
	float fractionPart = GetFractionPart(number);

	if (abs(fractionPart) >= 0.5)
	{
		if (number >= 0)
			return ++intPart;
		else
			return --intPart;

	}
	else
	{
		return intPart;

	}


}

float ReadNumber(string message) {
	float number = 0;

	cout << message << endl;

	cin >> number;
	return number;
}


int main()
{
	float number = ReadNumber("enter a float");

	cout << myRound(number) << endl;
	cout << round(number) << endl << endl;


	return 0;
}