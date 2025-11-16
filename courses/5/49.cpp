#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
float GetFractionPart(float number) {
	return number - int(number);
}



float myCeil(float number) {

	if (abs(GetFractionPart(number)) > 0)
		if (number >= 0)
			return int(number) + 1;
		else
			return int(number);
	else
		return number;
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

	cout << myCeil(number) << endl;
	cout << ceil(number) << endl << endl;


	return 0;
}