//#include <iostream>
//#include<iomanip>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//#include "../../Libs/MyLib.h"
//#include <cstdio>
//using namespace Input;
//using namespace Output;
//using namespace Strings;
//using namespace Time;
//
//
//
//
//
//stDate IncreaseDateByXDays(stDate Date , short DaysToAdd) {
//	short RemainingDays =   DaysToAdd  + DayOrderInYear(Date);
//	short MonthDays = 0;
//	short YearDays = 0;
//	Date.Month = 1;
//
//	while (true) {
//			YearDays = NumberOfDaysInYear(Date.Year);
//			if (RemainingDays > YearDays) {
//				RemainingDays -= YearDays;
//				Date.Year++;
//			}
//			else {
//				MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
//				if (RemainingDays > MonthDays)
//				{
//					RemainingDays -= MonthDays;
//					Date.Month++;
//
//					if (Date.Month > 12) {
//						Date.Month = 1;
//						Date.Year++;
//					}
//				}
//				else {
//					Date.Day = RemainingDays;
//					break;
//				}
//			}
//	}
//	return Date;
//
//}
//stDate ReadDate(short Year = 0, short Month = 0, short Day = 0) {
//	stDate Date;
//	Date.Year = (Year == 0) ?  ReadNumber("Enter A Year") : Year;
//	Date.Month = (Month == 0) ? ReadNumber("Enter A Month") : Month;
//	Date.Day = (Day == 0) ? ReadNumber("Enter A Day") : Day;
//	return Date;
//}
//int main() {
//
//	stDate Date = ReadDate(2022,10,10);
//
//	printf("The Date       %d/%d/%d  Before Adding %d Days To It \n", Date.Year, Date.Month, Date.Day, 2500);
//	Date = IncreaseDateByXDays(Date, 2500);
//
//	printf("The Date After %d/%d/%d \n", Date.Year, Date.Month, Date.Day);
//
//	return 0;
//} 