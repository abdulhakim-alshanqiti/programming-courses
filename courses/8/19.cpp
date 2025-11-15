//#include <iostream>
//#include<iomanip>
//#include <string>
//#include <cmath>
//
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
//
///// Dr Abu Hadhud Solution  ^
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
//
//	stDate Date1 = ReadDate(2003, 11, 17);
//	stDate Date2 = ReadDate(2003, 11, 17);
//
//	printf("Date 1 \n%d/%d/%d   \n", Date1.Year, Date1.Month, Date1.Day);
//
//	printf("Date 2 \n%d/%d/%d   \n", Date2.Year, Date2.Month, Date2.Day);
//
//	printf("The Diffrence is : %d Days \n", FindDiffBettwenTwoDates(Date1,Date2));
//
//	return 0;
//}