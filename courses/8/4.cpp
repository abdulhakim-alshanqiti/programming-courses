#include <iostream>
#include<iomanip>
#include "../../Libs/MyLib.h"
#include <string>
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;
using namespace std;


short NumberOfDaysInYear(short Year) {
	return  (IsLeapYear(Year) ? 366 : 365);
}
short NumberOfHoursInYear(short Year) {
	return NumberOfDaysInYear(Year)  * 24;
}
int NumberOfMinutesInYear(short Year) {
	return NumberOfHoursInYear(Year) * 60;
}
int NumberOfSecondsInYear(short Year) {
	return NumberOfMinutesInYear(Year)* 60;
}

void PrintYearData(short Year) {


	Printl( "days = " + to_string( NumberOfDaysInYear(Year)));
	Printl( "hours = "   + to_string( NumberOfHoursInYear(Year)));
	Printl( "minutes = " + to_string( NumberOfMinutesInYear(Year)));
	Printl( "seconds = " + to_string( NumberOfSecondsInYear(Year)));


}

int main() {
	short year = ReadNumber("Enter A Year");
	PrintYearData(year);

	return 0;
}