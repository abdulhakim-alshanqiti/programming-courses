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




//bool IsDateValid(stDate Date) {
//	return
//		(Date.Year > 0
//			&& (13 > Date.Month > 0)
//			&& NumberOfDaysInMonth(Date) >= Date.Day > 0);
//}
//
//stDate ReadDate(short Year = 0, short Month = 0, short Day = 0) {
//	stDate Date;
//
//	while (!IsDateValid(Date)) {
//		Date.Year = (Year == 0) ? ReadPositiveNumber("Enter A Year") : Year;
//		Date.Month = (Month == 0) ? ReadPositiveNumber("Enter A Month") : Month;
//		Date.Day = (Day == 0) ? ReadPositiveNumber("Enter A Day") : Day;
//		if (!IsDateValid(Date))
//			Printl("Please Enter A Valid Date");
//	}
//	return Date;
//}


int main() {

	stDate Date1 = ReadDate();

	printf("Date 1 is  %d/%d/%d   \n", Date1.Day, Date1.Month, Date1.Year);





	return 0;
}//