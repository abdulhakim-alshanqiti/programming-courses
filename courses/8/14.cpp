#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

using namespace std;

#include "../../libs/MyLib.h"
#include <cstdio>
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;


//bool IsDate1EqualToDate2(stDate Date1, stDate Date2) {
//	return
//		Date1.Year != Date2.Year ? false :
//		Date1.Month != Date2.Month ? false :
//		Date1.Day == Date2.Day;
//}
/// My Solution ^

//bool IsDate1EqualToDate2(stDate Date1, stDate Date2)
//{
//	return 
//		(Date1.Year == Date2.Year) ?
//		((Date1.Month == Date2.Month) ?
//		((Date1.Day == Date2.Day) ? true : false)
//			: false)
//		: false;
//}

/// Abu Hadhud Solution  ^




stDate ReadDate(short Year = 0, short Month = 0, short Day = 0) {
	stDate Date;
	Date.Year = (Year == 0) ? ReadNumber("Enter A Year") : Year;
	Date.Month = (Month == 0) ? ReadNumber("Enter A Month") : Month;
	Date.Day = (Day == 0) ? ReadNumber("Enter A Day") : Day;
	return Date;
}

int main() {

	stDate Date1 = ReadDate(2021, 7, 10);
	stDate Date2 = ReadDate(2021, 7, 10);

	printf("Is The Date %d/%d/%d  Equal To  %d/%d/%d  \n", Date1.Year, Date1.Month, Date1.Day, Date2.Year, Date2.Month, Date2.Day);
	bool isEqualTo = IsDate1EqualToDate2(Date1, Date2);

	printf("The Answer is %s \n", BoolToString(isEqualTo).c_str());

	return 0;
}