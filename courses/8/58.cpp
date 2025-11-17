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

//enum enDateCompare { Before=-1 ,Equal, After };
//string DateCompareToString(enDateCompare Compare) {
//	switch (Compare) {
//
//	case Before: return "Before";
//	case Equal: return "Equal";
//	case After: return "After";
//
//	}
//
//}
//enDateCompare CompareDates(stDate Date1, stDate Date2) {
//	if (IsDate1BeforeDate2(Date1, Date2))
//		return Before;
//	if (IsDate1AfterDate2(Date1,Date2))
//		return After;
//	else 
//		return Equal;
//}
//


//struct stPeriod {
//	stDate Start = { 1,1,1};
//	stDate End = { 1,1,1 };
//};

//bool IsPeriod1AndPeriod2Overlapping(stPeriod Period1, stPeriod Period2) {
//
//
//	if ( 
//		 CompareDates(Period1.End, Period2.Start) == Before ||
//		 CompareDates(Period2.End, Period1.Start) == Before 
//		)
//		return false;
//
//	else 
//		return true;
//}
//
int main() {

	stPeriod Period1 = {
		{2021,1,1 },
		{2022,1,1}
	};
	stPeriod Period2 = {
		{2020,1,1 },
		{2021,5,1}
	};



	printf("Start Of The Period 1 is  %d/%d/%d   \n",  Period1.Start.Day, Period1.Start.Month, Period1.Start.Year);

	printf("End Of The Period 1 is  %d/%d/%d   \n", Period1.End.Day, Period1.End.Month, Period1.End.Year);

	printf("Start Of The Period 2 is  %d/%d/%d   \n", Period2.Start.Day, Period2.Start.Month, Period2.Start.Year);

	printf("End Of The Period 2 is  %d/%d/%d   \n", Period2.End.Day, Period2.End.Month, Period2.End.Year);


	printf("Does Period 1 and Period 2 Overlap %s   \n", BoolToTrueAndFalse(IsPeriod1AndPeriod2Overlapping(Period1, Period2)).c_str());


	return 0;
}////////