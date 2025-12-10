#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

#include "../../libs/MyLib.h"
#include "../../libs/Date.h"
#include <cstdio>

using namespace std;

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;





short GetActualVecationDays(stDate StartDate, stDate EndDate) {
	short ActualVecationDays = 0;

	while (IsDate1BeforeDate2(StartDate, EndDate)) {
		if (IsABusinessDay(StartDate))
			ActualVecationDays++;

		StartDate = IncreaseDateByOneDay(StartDate);
	}

	return ActualVecationDays;
}

stDate VacationReturnDate(stDate StartDate, short VecationDays) {
	short ActualVecationDays = 0;
	while (ActualVecationDays < VecationDays) {
		if (IsABusinessDay(StartDate))
			ActualVecationDays++;

		StartDate = IncreaseDateByOneDay(StartDate);
	}
	return StartDate;
}
/// My Solution ^
stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{


	// in case the date is a weekend keep adding one day util you reach a business day
	// we get rid of all weekends before the first business day
	while (IsAWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}


	//here we increase the vacation dates to add all weekends to it.

	short WeekEndCounter = 0;

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{

		if (IsAWeekEnd(DateFrom))
			WeekEndCounter++;

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//in case the return date is week end keep adding one day util you reach business day
	while (IsAWeekEnd(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DateFrom;
}
/// Dr Abu Hadhud Solution  ^


int main() {
	stDate StartOfVecation = ReadDate(2022, 1, 1);

	printf("Start Of Vecation is %s %d/%d/%d   \n", GetDayShortName(StartOfVecation).c_str(), StartOfVecation.Day, StartOfVecation.Month, StartOfVecation.Year);

	stDate EndOfVecation = VacationReturnDate(StartOfVecation,ReadPositiveNumber("Please Enter Vecation Days"));

	printf("End Of Vecation is %s %d/%d/%d   \n", GetDayShortName(EndOfVecation).c_str(), EndOfVecation.Day, EndOfVecation.Month, EndOfVecation.Year);

	return 0;
}