#include <iostream>
#include<iomanip>
#include <string>
#include <cmath>

#include "../../libs/MyLib.h"
#include "../../libs/Date.h"
#include <cstdio>

using namespace std;

using namespace Input;
using namespace Output;
using namespace Strings;
using namespace Date;


//bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
//	return IsDate1BeforeDate2(Date2,Date1);
//}


int main() {
	stDate Date1 = ReadDate(2025, 1, 1);
	stDate Date2 = ReadDate(2022, 1, 1);


	printf("Date1 is %s %d/%d/%d   \n", GetDayShortName(Date1).c_str(), Date1.Day, Date1.Month, Date1.Year);

	printf("Date2 is %s %d/%d/%d   \n", GetDayShortName(Date2).c_str(), Date2.Day, Date2.Month, Date2.Year);

	printf("Is Date1 After Date2 : %s   \n", BoolToTrueAndFalse(IsDate1AfterDate2(Date1, Date2)).c_str());


	return 0;
}