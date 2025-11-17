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




/// My Solution ^

/// Dr Abu Hadhud Solution  ^


//string GetDayLongName(stDate Date) {
//
//
//	return DayLongName(DayOfWeekOrder(Date));
//}
//
//bool IsEndOfWeek(stDate Date) {
//
//	return DayOfWeekOrder(Date) == 6 ;
//}
//bool IsAWeekEnd(stDate Date) {
//	short DayOrder = DayOfWeekOrder(Date);
//	return (DayOrder == 5 || DayOrder == 6);
//}
//bool IsABusinessDay(stDate Date) {
//	return !IsAWeekEnd(Date);
//}
//
//short DaysUntillEndOfWeek(stDate Date) {
//
//	return 6 - DayOfWeekOrder(Date);
//}
//
//short DaysUntillEndOfMonth(stDate Date) {
//
//	stDate EndOfMonth = Date;
//	EndOfMonth.Day = NumberOfDaysInMonth(Date);
//
//	return GetDiffBettwenTwoDates(Date,EndOfMonth,true);
//}
//
//short DaysUntillEndOfYear(stDate Date) {
//	stDate EndOfYear;
//	EndOfYear.Day = 31;
//	EndOfYear.Month = 12;
//	EndOfYear.Year = Date.Year;
//	
//	return GetDiffBettwenTwoDates(Date, EndOfYear, true);
//}
int main() {
	stDate Date1 = GetSystemDate();

	printf("Today is %s %d/%d/%d   \n", GetDayLongName(Date1).c_str(), Date1.Day, Date1.Month, Date1.Year);

	printf("Is End Of The Week ? %s   \n", BoolToTrueAndFalse(IsEndOfWeek(Date1)).c_str() );

	printf("Is A Weekend ? %s   \n", BoolToTrueAndFalse(IsAWeekEnd(Date1)).c_str());
	printf("Is A Business Day ? %s   \n", BoolToTrueAndFalse(IsABusinessDay(Date1)).c_str());

	printf("Days Untill End Of Week? %d   \n", DaysUntillEndOfWeek(Date1));
	printf("Days Untill End Of Month? %d   \n", DaysUntillEndOfMonth(Date1));
	printf("Days Untill End Of Year? %d   \n", DaysUntillEndOfYear(Date1));


	return 0;
}//////////////////////////////////////////////////////////////////////////////