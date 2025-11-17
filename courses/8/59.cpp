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

//short GetPeriodLengthInDays(stPeriod Period,bool IncludingLastDay=false) {
//	return GetDifferenceInDays(Period.Start, Period.End,IncludingLastDay);
//}

int main() {

	stPeriod Period1 = {
		{2022,1,1 },
		{2022,1,2}
	};



	printf("Start Of The Period 1 is  %d/%d/%d   \n", Period1.Start.Day, Period1.Start.Month, Period1.Start.Year);

	printf("End Of The Period 1 is  %d/%d/%d   \n", Period1.End.Day, Period1.End.Month, Period1.End.Year);

	printf("Period 1 Length Is %d (Without End Day)  \n", GetPeriodLengthInDays(Period1));
	printf("Period 1 Length Is %d (Including End Day)  \n", GetPeriodLengthInDays(Period1,true));


	return 0;
}