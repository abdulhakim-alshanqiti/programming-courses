#include <iostream>
#include<iomanip>
#include "../../Libs/MyLib.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace std;

string NumberToString(int number) {
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

		return  NumberToString(number / 100)+  "Hundred " + NumberToString(number % 100);
	}

	if (number >= 1000 && number <= 1999) {
		return  "One Thousand " + NumberToString(number % 1000);
	}

	if (number >= 2000 && number <= 999999) {
		return NumberToString(number / 1000) + "Thousand " + NumberToString(number % 1000);
	}
	
	
}



int main() {
	int number = 996745;
	Printl(number);

	Printl(NumberToString(number));


	return 0;
}