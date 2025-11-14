#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

using namespace std;

#include "../../Libs/MyLib.h"
#include <cstdio>
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;





stDate AddDaysToDate(stDate Date , short DaysToAdd) {
	short RemainingDays =   DaysToAdd  + DayOrderInYear(Date);
	short MonthDays = 0;
	Date.Month = 1;


	while (true) {

			MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12) {
					Date.Month = 1;
					Date.Year++;
				}
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		
	}
	return Date;

}
int main() {

	stDate Date;

	//Date.Year = ReadNumber("Enter A Year");
	//Date.Month = ReadNumber("Enter A Month");
	//Date.Day = ReadNumber("Enter A Day");

	Date.Year = 2022;
	Date.Month = 10;
	Date.Day = 10;
	printf("The Date       %d/%d/%d  Before Adding %d Days To It \n", Date.Year, Date.Month, Date.Day, 2500);
	Date = AddDaysToDate(Date, 2500);

	printf("The Date After %d/%d/%d \n", Date.Year, Date.Month, Date.Day);

	return 0;
} 