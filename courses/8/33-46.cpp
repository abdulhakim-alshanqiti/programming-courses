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


	stDate Date1 = ReadDate(2022, 11, 1);


	printf("%d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByOneDay(Date1);
	printf("After Adding 1 day : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByXDays(Date1, 10);
	printf("After Adding 10 days : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneWeek(Date1);
	printf("After Adding 1 Week : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXWeeks(Date1, 10);
	printf("After Adding 10 Weeks : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneMonth(Date1);
	printf("After Adding 1 Month : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXMonths(Date1, 5);
	printf("After Adding 5 Months : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneYear(Date1);
	printf("After Adding 1 Year : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXYears(Date1, 10);
	printf("After Adding 10 Years : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXYearsFaster(Date1, 10);
	printf("After Adding 10 Years (Faster) : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneDecade(Date1);
	printf("After Adding 1 Decade : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXDecades(Date1, 10);
	printf("After Adding 10 Decades : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByXDecadesFaster(Date1, 10);
	printf("After Adding 10 Decades (Faster) : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);


	Date1 = IncreaseDateByOneCentury(Date1);
	printf("After Adding 1 Century : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	Date1 = IncreaseDateByOneMillennium(Date1);
	printf("After Adding 1 Millennium : %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);

	return 0;
}