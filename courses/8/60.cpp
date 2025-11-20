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
int main() {

	stPeriod Period1 = {
		{2022,1,1 },
		{2022,2,2}
	};

	stDate Date1 = { 2022,1,25 };


	printf("Start Of The Period 1 is  %d/%d/%d   \n", Period1.Start.Day, Period1.Start.Month, Period1.Start.Year);

	printf("End Of The Period 1 is  %d/%d/%d   \n", Period1.End.Day, Period1.End.Month, Period1.End.Year);

	printf("Is Date In Period ? %s   \n",BoolToTrueAndFalse( IsDateInPeriod(Period1,Date1) ).c_str() );



	return 0;
}