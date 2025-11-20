#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

#include "../../Libs/MyLib.h"
#include "../../Libs/Date.h"
#include <cstdio>

using namespace std;
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;


//bool IsDateInPeriod(stPeriod Period, stDate Date) {
//
//	return !(
//		CompareDates(Date, Period.Start) == enDateCompare::Before ||
//		CompareDates(Date, Period.End) == enDateCompare::After
//		);
//
//}
short CountOverlappingDays(stPeriod Period1, stPeriod Period2) {
	if (!IsPeriodsOverlapping(Period1, Period2))
		return 0;

	bool IsPeriod1Longer = GetPeriodLengthInDays(Period1) > GetPeriodLengthInDays(Period2);
	if (IsPeriod1Longer)
		swap(Period1, Period2);/// So We Don't go Through The Longer One

	/// Now Period1 is Shorter Than Period2 so we go From The Start Of Period1 To The End Of Period1
	/// We Check Each Day If Its In Period2 Or Not

	int OverlapDays = 0;
	while (CompareDates(Period1.Start, Period1.End) == Before) {
		if (IsDateInPeriod(Period2, Period1.Start))
			OverlapDays++;
		Period1.Start = IncreaseDateByOneDay(Period1.Start);
	}
	return OverlapDays;
}

int main() {

	stPeriod Period1 = {
			ReadDate(stDate({ 2022,1,1 })),  //	ReadDate() // this will prompt the user to enter a date
			ReadDate(stDate({ 2022,1,10 }))
	};


	stPeriod Period2 = {
		ReadDate(stDate({ 2022,1,5 })),
		ReadDate(stDate({ 2050,12,30 }))
	};


	printf("Start Of The Period 1 is  %d/%d/%d   \n", Period1.Start.Day, Period1.Start.Month, Period1.Start.Year);

	printf("End Of The Period 1 is  %d/%d/%d   \n", Period1.End.Day, Period1.End.Month, Period1.End.Year);


	printf("Start Of The Period 2 is  %d/%d/%d   \n", Period2.Start.Day, Period2.Start.Month, Period2.Start.Year);

	printf("End Of The Period 2 is  %d/%d/%d   \n", Period2.End.Day, Period2.End.Month, Period2.End.Year);


	printf("Count Of Overlapping Days : %d   \n", CountOverlappingDays(Period1, Period2));



	return 0;
}//