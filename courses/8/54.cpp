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



/// My Solution ^

/// Dr Abu Hadhud Solution  ^

short GetActualVecationDays(stDate StartDate, stDate EndDate) {
	short ActualVecationDays=0;

	while(IsDate1BeforeDate2(StartDate,EndDate)) {
		if (IsABusinessDay(StartDate))
			ActualVecationDays++;

		StartDate = IncreaseDateByOneDay(StartDate);
	}

	return ActualVecationDays;
}

int main() {
	stDate StartOfVecation = ReadDate(2022,9,1);

	printf("Start Of Vecation is %s %d/%d/%d   \n", GetDayShortName(StartOfVecation).c_str(), StartOfVecation.Day, StartOfVecation.Month, StartOfVecation.Year);

	stDate EndOfVecation = ReadDate(2022, 9, 5);

	printf("End Of Vecation is %s %d/%d/%d   \n", GetDayShortName(EndOfVecation).c_str(), EndOfVecation.Day, EndOfVecation.Month, EndOfVecation.Year);

	printf("Actual Vecation Days is %d  \n", GetActualVecationDays(StartOfVecation,EndOfVecation));


	return 0;
}