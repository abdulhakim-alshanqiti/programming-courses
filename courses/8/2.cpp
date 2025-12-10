#include <iostream>
#include<iomanip>
#include "../../libs/MyLib.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;
using namespace std;

int main() {
	short year = ReadNumber("Enter A Year");
	Printl("Is The Year " + to_string(year)  + " A Leap Year ?\n"+ BoolToString(IsLeapYear(year)) );


	return 0;
}