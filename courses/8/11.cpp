#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

using namespace std;

#include "../../Libs/MyLib.h"
#include <cstdio>
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;



//stDate DateFromDayOrder(short DayOrder,short Year ) {
//	short CountOfDays = 0;
//	short MonthDays = 0;
//	stDate result;
//
//	for (short Month = 1; Month <= 12; Month++) {
//		MonthDays = NumberOfDaysInMonth(Month, Year);
//		CountOfDays += MonthDays;
//		if (CountOfDays >= DayOrder) {
//					result.Year = Year;
//					result.Month = Month;
//					result.Day = (MonthDays - (CountOfDays - DayOrder ) );
//					return result;
//		}
//	}
//	return result;
//}
/// My Solution ^



int main() {


    short Year = ReadNumber("Enter A Year");
	short Month = ReadNumber("Enter A Month");
	short Day = ReadNumber("Enter A Day");

	//short Year = 2003;
	//short Month = 11;
	//short Day = 18;

	short DayOrder = DayOrderInYear(Year, Month, Day);

	printf("Number Of Days Since The Beginning Of The Year : %d \n",  DayOrder);

	stDate Date = DateFromDayOrder(DayOrder,Year);
	printf("The Date Is  %d/%d/%d \n", Date.Year, Date.Month, Date.Day);

	return 0;
}