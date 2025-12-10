#include <iostream>
#include<iomanip>
#include "../../libs/MyLib.h"
#include <string>
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;
using namespace std;


//enum enMonthOfYear
//{
//	January = 1,
//	February,
//	March,
//	April,
//	May,
//	June,
//	July,
//	August,
//	September,
//	October,
//	November,
//	December
//};
//
//
//
//
//
//
//short NumberOfDaysInMonth(short Year ,short Month) {
//	switch (enMonthOfYear(Month))
//	{
//	case January:return 31;
//	case February:return (IsLeapYear(Year) ? 29 : 28);
//	case March:return 31;
//	case April:return 30;
//	case May:return 31;
//	case June:return 30;
//	case July:return 31;
//	case August:return 31;
//	case September:return 30;
//	case October:return 31;
//	case November:return 30;
//	case December:return 31;
//
//	}
//
//}
/// My Solution ^



short NumberOfDaysInMonth(short Month,short Year) {	
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDaysInEachMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	return	(Month == 2) ? (IsLeapYear(Year) ? 29 : 28) :NumberOfDaysInEachMonth[Month] ;
}

/// Abu Hadhud Solution ^
short NumberOfHoursInMonth(short Month,short Year) {
	return NumberOfDaysInMonth(Month,Year) * 24;
}
int NumberOfMinutesInMonth(short Month,short Year) {
	return NumberOfHoursInMonth(Month,Year) * 60;
}
int NumberOfSecondsInMonth(short Month,short Year) {
	return NumberOfMinutesInMonth(Month,Year) * 60;
}


int main() {
	short Year = ReadNumber("Enter A Year");
	short Month = ReadNumber("Enter A Month");
	Printl("days = " + to_string(NumberOfDaysInMonth(Month, Year)));


	return 0;
}