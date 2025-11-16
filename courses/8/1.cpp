#include <iostream>
#include<iomanip>
#include "../../Libs/MyLib.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace std;

string NumberToString(long long number) {
	if (number == 0) {
		return "";
	}

	if (number >= 1 && number <= 19) {
		string  arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
	
		return arr[number] + " ";
	}

	if (number >= 20 && number <= 99) {
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };


		return arr[number/ 10] + " " + NumberToString(number% 10);
	}
	if (number >= 100 && number <= 199) {
		return  "One Hundred " + NumberToString(number % 100);
	}

	if (number >= 200 && number <= 999) {

		return  NumberToString(number / 100)+  "Hundreds " + NumberToString(number % 100);
	}

	if (number >= 1000 && number <= 1999) {
		return  "One Thousand " + NumberToString(number % 1000);
	}

	if (number >= 2000 && number <= 999999) {
		return NumberToString(number / 1000) + "Thousands " + NumberToString(number % 1000);
	}

	if (number >= 1000000 && number <= 1999999) {
		return  "One Million " + NumberToString(number % 1000000);
	}
	
	if (number >= 2000000 && number <= 999999999) {
		return  NumberToString(number / 1000000) + "Millions " + NumberToString(number % 1000000);
	}

	if (number >= 1000000000 && number <= 1999999999) {
		return  "One Billion " + NumberToString(number % 1000000);
	}

	if (number >= 2000000000 && number <= 999999999999) {
		return NumberToString(number / 1000000000) + "Billions " + NumberToString(number % 1000000000);
	}
	
}



int main() {
	long long number = 25004600000;
	Printl(number);

	Printl(NumberToString(number));


	return 0;
}