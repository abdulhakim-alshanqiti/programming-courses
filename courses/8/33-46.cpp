#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

#include "../../Libs/MyLib.h"
#include <cstdio>

using namespace std;

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;

bool IsFirstMonthInYear(short Month) {
	return Month == 1;
}
bool IsFirstDayInMonth(short Day) {
	return Day == 1;
}

stDate DecreaseDateByOneDay(stDate Date) {
	if (IsFirstDayInMonth(Date.Day))
		if (IsFirstMonthInYear(Date.Month))
			Date.Month = 12,
			Date.Day = 31,
			Date.Year--;

		else
			Date.Month--,
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
	
	else 
		Date.Day--;
	
	return Date;
}

stDate DecreaseDateByXDays(stDate Date,short NumberOfDaysToSubtract) {

	for (short i = 0; i < NumberOfDaysToSubtract;i++) {
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}
 
stDate DecreaseDateByOneWeek(stDate Date) {
	
	for (short i = 0; i < 7; i++) {
		Date = DecreaseDateByOneDay(Date);
	}
	

	return Date;
}

stDate DecreaseDateByXWeeks(stDate Date,short NumberOfWeeksToSubtract) {
	
	for (short i = 0; i < NumberOfWeeksToSubtract * 7; i++) {
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date) {

	if (IsFirstMonthInYear(Date.Month))
		Date.Year--, Date.Month = 12;
	else
		Date.Month-- ;

	// In Case The Number Of Days In The Original Month Is Greater Than This Month
	short DaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if (DaysInCurrentMonth < Date.Day)
		Date.Day = DaysInCurrentMonth;
	

	return Date;
}

stDate DecreaseDateByXMonths(stDate Date, short NumberOfMonthsToSubtract) {
	for (short i = 0; i < NumberOfMonthsToSubtract; i++) {
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}
stDate DecreaseDateByOneYear(stDate Date) {
	Date.Year--;

	return Date;
}
stDate DecreaseDateByXYears(stDate Date, short NumberOfYearsToSubtract) {

	for (short i = 0; i < NumberOfYearsToSubtract; i++) {
	
	Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXYearsFaster(stDate Date, short NumberOfYearsToSubtract) {
	Date.Year -= NumberOfYearsToSubtract;

	return Date;
}


stDate DecreaseDateByOneDecade(stDate Date) {
	Date.Year -= 10;

	return Date;
}
stDate DecreaseDateByXDecades(stDate Date, short NumberOfDecadesToSubtract) {

	for (short i = 0; i < NumberOfDecadesToSubtract; i++) {

		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadesFaster(stDate Date, short NumberOfDecadesToSubtract) {
	Date.Year -= NumberOfDecadesToSubtract * 10;

	return Date;
}


stDate DecreaseDateByOneCentury(stDate Date) {
	Date.Year -= 100;

	return Date;
}


stDate DecreaseDateByOneMillennium(stDate Date) {
	Date.Year -= 1000;

	return Date;
}

/// My Solution ^

/// Dr Abu Hadhud Solution  ^


stDate ReadDate(short Year = 0, short Month = 0, short Day = 0) {
	stDate Date;
	Date.Year = (Year == 0) ? ReadNumber("Enter A Year") : Year;
	Date.Month = (Month == 0) ? ReadNumber("Enter A Month") : Month;
	Date.Day = (Day == 0) ? ReadNumber("Enter A Day") : Day;
	return Date;
}



int main() {
	stDate Date1 = ReadDate(2022, 12, 31);

	printf("%d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByOneDay(Date1);
	printf("After Subtracting 1 day : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = DecreaseDateByXDays(Date1, 10);
	printf("After Subtracting 10 days : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByOneWeek(Date1);
	printf("After Subtracting 1 Week : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByXWeeks(Date1, 10);
	printf("After Subtracting 10 Weeks : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByOneMonth(Date1);
	printf("After Subtracting 1 Month : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByXMonths(Date1, 5);
	printf("After Subtracting 5 Months : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByOneYear(Date1);
	printf("After Subtracting 1 Year : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByXYears(Date1, 10);
	printf("After Subtracting 10 Years : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByXYearsFaster(Date1, 10);
	printf("After Subtracting 10 Years (Faster) : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByOneDecade(Date1);
	printf("After Subtracting 1 Decade : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByXDecades(Date1, 10);
	printf("After Subtracting 10 Decades : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByXDecadesFaster(Date1, 10);
	printf("After Subtracting 10 Decades (Faster) : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = DecreaseDateByOneCentury(Date1);
	printf("After Subtracting 1 Century : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = DecreaseDateByOneMillennium(Date1);
	printf("After Subtracting 1 Millennium : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	return 0;
}