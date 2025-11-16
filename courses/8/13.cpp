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


bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {

return  
	(Date1.Year < Date2.Year) ? true :
	(Date1.Year != Date2.Year) ? false :

	(Date1.Month < Date2.Month) ? true :
	(Date1.Month != Date2.Month) ? false:

	(Date1.Day < Date2.Day) ? true :
	(Date1.Day != Date2.Day) ? false :
	
	true;

}
/// My Solution ^

//bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
//
//	return
//		(Date1.Year != Date2.Year) ? (Date1.Year > Date2.Year) :
//
//		(Date1.Month != Date2.Month) ? (Date1.Month > Date2.Month) :
//
//		(Date1.Day > Date2.Day);
//	
//}
/// Solution I found In Comments ^

stDate ReadDate(short Year = 0, short Month = 0, short Day = 0) {
	stDate Date;
	Date.Year = (Year == 0) ? ReadNumber("Enter A Year") : Year;
	Date.Month = (Month == 0) ? ReadNumber("Enter A Month") : Month;
	Date.Day = (Day == 0) ? ReadNumber("Enter A Day") : Day;
	return Date;
}

int main() {

	stDate Date1 = ReadDate(2021, 6, 10);
	stDate Date2 = ReadDate(2021, 7, 3);

	printf("Is The Date %d/%d/%d  Less Than  %d/%d/%d  \n", Date1.Year, Date1.Month, Date1.Day, Date2.Year, Date2.Month, Date2.Day );
	bool IsLessThan = IsDate1BeforeDate2(Date1,Date2);

	printf("The Answer is %s \n",  BoolToString(IsLessThan).c_str() );

	return 0;
}