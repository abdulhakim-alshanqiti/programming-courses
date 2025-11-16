#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

#include "../../Libs/MyLib.h"
#include <cstdio>
using namespace std;

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;

//short FindDiffBettwenTwoDates(stDate Date1, stDate Date2, bool WithLastDay = false) {
//	short CountDiff = 1;
//	while (IsDate1BeforeDate2(Date1, Date2)) {
//		CountDiff++;
//		Date1 = IncreaseDateByOneDay(Date1);
//	}
//	return WithLastDay ? CountDiff : --CountDiff;
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

	stDate Date1 = ReadDate(2022, 1, 1);
	stDate Date2 = ReadDate(2022, 3, 25);

	printf("The Date1 is \n%d/%d/%d   \n", Date1.Year, Date1.Month, Date1.Day);
	printf("The Date2 is \n%d/%d/%d   \n", Date2.Year, Date2.Month, Date2.Day);

	printf("The Diffrence Bettwen The Two With Last Day : %d   \n", FindDiffBettwenTwoDates(Date1,Date2,true));
	printf("The Diffrence Bettwen The Two Without Last Day : %d   \n", FindDiffBettwenTwoDates(Date1, Date2));
	return 0;
}