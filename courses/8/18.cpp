//#include <iostream>
//#include<iomanip>
//#include <string>
//#include <cmath>
//#include <ctime>
//#include "../../Libs/MyLib.h"
//#include <cstdio>
//
//using namespace std;
//
//using namespace Input;
//using namespace Output;
//using namespace Strings;
//using namespace Time;
//
//
///// My Solution ^
//stDate GetSystemDate() {
//	stDate Date;
//	time_t t = time(0);
//	// get time now 
//	tm* now = localtime(&t);
//	Date.Year = now->tm_year + 1900;
//	Date.Month = now->tm_mon + 1;
//	Date.Day = now->tm_mday ;
//
//	return Date;
//}
//
//short HowManyDaysHavePassedSince(stDate Date,bool IncludeLastDay=true) {
//	return FindDiffBettwenTwoDates(Date, GetSystemDate(), IncludeLastDay);
//}
///// Dr Abu Hadhud Solution  ^
//
//
//
//
//
//stDate ReadDate(short Year = 0, short Month = 0, short Day = 0) {
//	stDate Date;
//	Date.Year = (Year == 0) ? ReadNumber("Enter A Year") : Year;
//	Date.Month = (Month == 0) ? ReadNumber("Enter A Month") : Month;
//	Date.Day = (Day == 0) ? ReadNumber("Enter A Day") : Day;
//	return Date;
//}
//
//
//
//int main() {
//
//	stDate Date = ReadDate(2003, 11, 18);
//
//	printf("You Were Born At \n%d/%d/%d   \n", Date.Year, Date.Month, Date.Day);
//
//
//	printf("You Lived for : %d Days \n", HowManyDaysHavePassedSince(Date));
//
//	return 0;
//}