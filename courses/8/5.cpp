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

	if (Month > 12 || Month < 1) 
		return 0;
	
	if (Month == 2) 
		return IsLeapYear(Year) ? 29 : 28;
	
	short arr31Days[7] = {1,3,5,7,8,10,12};

	for (short i = 0; i < 7; i++)
	{
		if (arr31Days[i] == Month)
			return 31;

	}


	return 30;

}
/// Anu Hadhud Solution ^

short NumberOfHoursInMonth(short Month,short Year) {
	return NumberOfDaysInMonth(Month,Year) * 24;
}
int NumberOfMinutesInMonth(short Month,short Year) {
	return NumberOfHoursInMonth(Month,Year) * 60;
}
int NumberOfSecondsInMonth(short Month,short Year) {
	return NumberOfMinutesInMonth(Month,Year) * 60;
}
void PrintMonthData(short Month,short Year) {


	Printl("days = " + to_string(NumberOfDaysInMonth(Month, Year)));
	Printl("hours = " + to_string(NumberOfHoursInMonth(Month, Year)));
	Printl("minutes = " + to_string(NumberOfMinutesInMonth(Month, Year)));
	Printl("seconds = " + to_string(NumberOfSecondsInMonth(Month, Year)));


}

int main() {
	short Year = ReadNumber("Enter A Year");
	short Month = ReadNumber("Enter A Month");
	PrintMonthData(Month,Year);


	return 0;
}