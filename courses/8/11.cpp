#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

using namespace std;

#include "../../Libs/MyLib.h"
using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Time;

string DateFromDay(short Year, short DayCount) {
	short CountOfDays = 0;
	string result="";
	for (short i = 1; i < 12; i++) {
		CountOfDays += NumberOfDaysInMonth(i, Year);


		if (CountOfDays >= DayCount) {
			CountOfDays -= NumberOfDaysInMonth(i, Year);
			for (short j = 1; j < NumberOfDaysInMonth(i, Year); j++)
			{
				CountOfDays++;
				if (CountOfDays == DayCount) {
					result = to_string(Year) + "/" + to_string(i) + "/" + to_string(j);
					return result;
				}

			}
		}
	}
	return result;
}


int main() {
/*	

	short Year = ReadNumber("Enter A Year");
	short Month = ReadNumber("Enter A Month");
	short Day = ReadNumber("Enter A Day");
	
	*/
	short DayCount = NumberOfDaysFromBeginningOfYear(2003, 11, 18);

	Printl("Number Of Days Since The Beginning Of The Year :" + to_string( DayCount));



	Printl("The Date Is " + DateFromDay(2003, DayCount));

	return 0;
}