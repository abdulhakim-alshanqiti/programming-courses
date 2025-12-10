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


//bool IsLastMonthInYear(short Month) {
//	return Month == 12;
//}
//bool IsLastDayInMonth(stDate Date) {
//	return Date.Day == NumberOfDaysInMonth(Date.Month,Date.Year);
//}
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

	stDate Date = ReadDate(2021, 12, 10);

	printf("The Date is %d/%d/%d   \n", Date.Year, Date.Month, Date.Day);
	bool IsLastDay = IsLastDayInMonth(Date);

	printf("is Last Day In Month %s \n", BoolToString(IsLastDay).c_str());

	bool IsLastMonth = IsLastMonthInYear(Date.Month);

	printf("is Last Month In Year %s \n", BoolToString(IsLastMonth).c_str());
	return 0;
}