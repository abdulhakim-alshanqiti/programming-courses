#include <iostream>
#include "../../Libs/MyLib.h"
using namespace std;
using namespace Input;
using namespace Output;

int main() {

	int number = ReadNumber("Enter a Number");
	Print("The Number Is ");

	number >= 0 ?
		Printl("Positive") :
		Printl("Negitive");

	int number2 = ReadNumber("Enter a Number");
	Print("The Number Is ");

	number2 == 0 ?
		Printl("Zero") :

		number2 >= 0 ?
		Printl("Positive") :
		Printl("Negitive");


	return 0;
}