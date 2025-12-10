#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

#include "../../libs/MyLib.h"
#include <cstdio>
using namespace std;

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;

//stDate IncreaseDateByOneDay(stDate Date) {
//
//	IsLastDayInMonth(Date)
//		?
//		IsLastMonthInYear(Date.Month)
//		?
//		Date.Day = 1,
//		Date.Month = 1,
//		Date.Year++
//		:
//		Date.Day = 1,
//		Date.Month++
//		:
//		Date.Day++;
//
//	return Date;
//}
/// My Solution ^
//stDate IncreaseDateByOneDay(stDate Date) {
//	if (IsLastDayInMonth(Date)) {
//		if (IsLastMonthInYear(Date.Month))
//		{
//			Date.Month = 1; Date.Day = 1; Date.Year++;
//		}
//		else { Date.Day = 1; Date.Month++; }
//	}
//	else { Date.Day++; }
//	return Date;
//}

/// Dr Abu Hadhud Solution  ^





stDate ReadDate(short Year = 0, short Month = 0, short Day = 0) {
	stDate Date;
	Date.Year = (Year == 0) ? ReadNumber("Enter A Year") : Year;
	Date.Month = (Month == 0) ? ReadNumber("Enter A Month") : Month;
	Date.Day = (Day == 0) ? ReadNumber("Enter A Day") : Day;
	return Date;
}



int main() {

	stDate Date = ReadDate(2021, 12, 30);

	printf("The Date is \n%d/%d/%d   \n", Date.Year, Date.Month, Date.Day);
	Date = IncreaseDateByOneDay(Date);

	printf("The Date After Adding 1 Day \n%d/%d/%d   \n", Date.Year, Date.Month, Date.Day);
	return 0;
}